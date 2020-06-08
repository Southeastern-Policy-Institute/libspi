
#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x0600
#include <windows.h>
#include "../inc/spi.h"

static spi::mutex* ghMutex = NULL;
static spi::file* log_file = NULL;
static DWORD ithread {0};
static SYSTEMTIME   start_time;

BOOL log_fini (void) {
  delete log_file;
  delete ghMutex;
  return TRUE;
};

BOOL log_init (void) {
  BOOL success_state = FALSE;
  static LPCTSTR startup_string = "LIBSPI_LOG v%d.%02d r%04x\n"
                                  "Started %02d/%02d/%02d at %02d:%02d:%02d\n"
                                  "Host Thread: %04X\n";
  static LPCTSTR log_ext = ".log";
  spi::string<TCHAR> buffer {spi::string<TCHAR> (200)};
  spi::string<TCHAR> log_filename {spi::string<TCHAR> (MAX_PATH)};
  GetLocalTime (&start_time);
  ithread = GetCurrentThreadId ();

  // Initialize global mutex
  ghMutex = new spi::mutex ();

  // Initialize process handle
  HANDLE hProc = OpenProcess (
    PROCESS_QUERY_INFORMATION | PROCESS_VM_READ,
    FALSE,
    GetCurrentProcessId ()
  );
  if (!hProc)
    return FALSE;

  // Generate log file name
  if (!log_filename.operator const TCHAR* ())
    return FALSE;
  if (!GetModuleFileName (NULL, log_filename, MAX_PATH))
    goto L1;
  spi::memcpy (
    log_filename.operator TCHAR* () + (log_filename.length () - 4),
    log_ext,
    4
  );

  // Generate log file handle
  log_file = new spi::file (log_filename);
  if (!log_file->operator bool ())
    goto L1;

  // Generate temporary buffer and print startup string to it
  if (!buffer.operator TCHAR* ())
    goto L1;
  wsprintf (buffer.operator TCHAR* (), startup_string, __SPI_VER_MAJOR__,
            __SPI_VER_MINOR__, __SPI_VER_REVIS__, start_time.wMonth,
            start_time.wDay, start_time.wYear, start_time.wHour,
            start_time.wMinute, start_time.wSecond, ithread);

  // Write startup string to file
  log_file->Write (buffer);

  success_state = TRUE;
L1: // Error: Unable to generate log file name or handle
  return success_state;
};

extern "C" SPI_LOG_API DWORD spi_host_thread (void) {
  if (!ghMutex->lock ())
    return 0;
  DWORD ret_val = ithread;
  ghMutex->unlock ();
  return ret_val;
};

extern "C" SPI_LOG_API DWORD spi_log (const void* str) {
  spi::string<TCHAR> buffer {1024};
  static LPCTSTR log_format = "[%04X|+%04d] %s\n";
  DWORD bytes_written = 0;
  SIZE_T secs = 0;

  if (!ghMutex->lock ())
    return 0;
  if (!str || log_file == INVALID_HANDLE_VALUE || !log_file) {
    bytes_written = 0;
    goto E1;
  };

  SYSTEMTIME now;
  GetLocalTime (&now);
  secs =  ((SIZE_T)(now.wHour - start_time.wHour) * 3600) +
          ((SIZE_T)(now.wMinute - start_time.wMinute) * 60) +
          (now.wSecond - start_time.wSecond);
  wsprintf (buffer, log_format, GetCurrentThreadId (), secs, str);
  log_file->Write (buffer);
E1: // Error after locking mutex
  ghMutex->unlock ();
  return bytes_written;
};
