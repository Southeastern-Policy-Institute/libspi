/* STDLIB.CPP - Standard C and C++ Library Functions.
 * Southeastern Policy Institute, 2020
 */

#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x0600
#include <windows.h>
#include "../inc/spi.h"

SPI_LOG_API void* operator new (__SIZE_TYPE__ len) {
  return malloc (len);
};

SPI_LOG_API void* operator new[] (__SIZE_TYPE__ len) {
  return malloc (len);
};

SPI_LOG_API void operator delete (void* ptr) {
  free (ptr);
};

SPI_LOG_API void operator delete (void* ptr, __SIZE_TYPE__ res) noexcept {
  free (ptr);
};

extern "C" {
  SPI_LOG_API void* malloc (__SIZE_TYPE__ size) {
    if (!size)
      return NULL;
    return HeapAlloc (GetProcessHeap (), HEAP_ZERO_MEMORY, size);
  };
  
  SPI_LOG_API void* calloc (__SIZE_TYPE__ num, __SIZE_TYPE__ size) {
    if (!size || !num)
      return NULL;
    return HeapAlloc (GetProcessHeap (), HEAP_ZERO_MEMORY, num * size);
  };

  SPI_LOG_API void free (void* ptr) {
    if (ptr)
      HeapFree (GetProcessHeap (), 0, ptr);
  };
};