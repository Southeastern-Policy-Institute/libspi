/* STDLIB.CPP - Standard C and C++ Library Functions.
 * Southeastern Policy Institute, 2020
 */

#define  WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "../inc/spi.h"

void* operator new (__SIZE_TYPE__ len) {
  return HeapAlloc (GetProcessHeap (), HEAP_ZERO_MEMORY, len);
};

void* operator new[] (__SIZE_TYPE__ len) {
  return HeapAlloc (GetProcessHeap (), HEAP_ZERO_MEMORY, len);
};

void operator delete (void* ptr) {
  if (ptr)
    HeapFree (GetProcessHeap (), 0, ptr);
};

void operator delete (void* ptr, __SIZE_TYPE__ res) noexcept {
  if (ptr)
    HeapFree (GetProcessHeap (), 0, ptr);
};