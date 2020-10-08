/* STDLIB.CPP - Standard C and C++ Library Functions.
 * Southeastern Policy Institute, 2020
 */

#include <stdlib.h>
#include "../inc/spi.h"

void* operator new (__SIZE_TYPE__ len) {
  return malloc (len);
};

void* operator new[] (__SIZE_TYPE__ len) {
  return malloc (len);
};

void operator delete (void* ptr) {
  free (ptr);
};

void operator delete (void* ptr, __SIZE_TYPE__ res) noexcept {
  free (ptr);
};
