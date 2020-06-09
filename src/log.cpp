
#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x0600
#include <windows.h>
#include "../inc/spi.h"

namespace spi {

  log* log::main_instance {NULL};

  const t_char* log::startup_string = "LIBSPI_LOG v%d.%02d r%04x\r\n"
                                      "Started %02d/%02d/%02d "
                                      "at %02d:%02d:%02d\r\n"
                                      "Host Thread: %04X\r\n";
  const t_char* log::filename_ext   = ".log";

  log::log (void)
    : log ([]()->const string<t_char>{
        string<t_char> buffer {MAX_PATH};
        GetModuleFileName (NULL, buffer, MAX_PATH);
        memcpy (
          buffer.operator t_char* () + (buffer.length () - 4),
          filename_ext,
          4
        );
        return buffer;
      }())
  {};

  log::log (const string<t_char>& path)
    : mutex (),
      host_thread_ (GetCurrentThreadId ()),
      file_ (path),
      start_time_ (new SYSTEMTIME)
  {
    string<t_char> buffer {MAX_PATH};
    GetLocalTime ((LPSYSTEMTIME)start_time_);
    SYSTEMTIME* start_time = (LPSYSTEMTIME)start_time_;
    wsprintf (buffer, startup_string, __SPI_VER_MAJOR__,
              __SPI_VER_MINOR__, __SPI_VER_REVIS__, start_time->wMonth,
              start_time->wDay, start_time->wYear, start_time->wHour,
              start_time->wMinute, start_time->wSecond, host_thread_);
    file_.Write (buffer);
  };

  log::~log (void) {
    delete (LPSYSTEMTIME)start_time_;
  };

  unsigned long log::operator() (const string<t_char>& str) {
    static const t_char* log_format {"[%04X|+%04d] %s\r\n"};
    string<t_char> buffer {1024};
    SYSTEMTIME now;
    GetLocalTime (&now);
    SYSTEMTIME* start_time = (LPSYSTEMTIME)start_time_;
    __SIZE_TYPE__ seconds { 
      ((__SIZE_TYPE__)(now.wHour - start_time->wHour) * 3600) +
      ((__SIZE_TYPE__)(now.wMinute - start_time->wMinute) * 60) +
      (now.wSecond - start_time->wSecond) };
    if (!lock ())
      return 0;
    wsprintf (buffer, log_format, GetCurrentThreadId (), seconds,
              str.operator const t_char* ());
    unsigned long bytes_written = file_.Write (buffer);
    unlock ();
    return bytes_written;
  };

};
