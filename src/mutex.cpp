/* MUTEX.CPP - Implements the mutex class.
 * Southeastern Policy Institute, 2020
 */

#include <windows.h>
#include "../inc/spi.h"

namespace spi {

  mutex::mutex (void) : handle_ ((void*)0U) {
    handle_ = CreateMutex (NULL, FALSE, NULL);
  };

  mutex::~mutex (void) {
    CloseHandle (handle_);
  };

  bool mutex::lock (void) const {
    DWORD wait_result = WaitForSingleObject (handle_, INFINITE);
    return wait_result == WAIT_OBJECT_0;
  };

  void mutex::unlock (void) const {
    ReleaseMutex (handle_);
  };

};