/* FILE.CPP - File manipulation routines.
 * Southeastern Policy Institute, 2020
 */

#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x0600
#include <windows.h>
#include "../inc/spi.h"
namespace spi {
  void* file::create_file (const void* path) {
    return CreateFile ( (LPCSTR)path, GENERIC_WRITE, FILE_SHARE_WRITE,
                        NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
  };

  __SIZE_TYPE__ file::write_to_file (const void* str, __SIZE_TYPE__ len) {
    DWORD bytes_written = 0;
    if (!lock ())
      return 0;
    if (!str || handle_ == INVALID_HANDLE_VALUE || !handle_) {
      bytes_written = 0;
      goto E1;
    };
    WriteFile (handle_, str, len, &bytes_written, NULL);
E1: unlock ();
    return bytes_written;
  };

  file::~file (void) {
    if (handle_ != INVALID_HANDLE_VALUE && handle_ != NULL)
      CloseHandle (handle_);
  };
};