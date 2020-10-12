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

void operator delete[] (void* ptr) {
  free (ptr);
};

namespace spi {
  string& operator<< (string& dest, const string& str) {
    __SIZE_TYPE__ len = dest.length () + str.length () + 1;
    tchar_t* temp = new tchar_t[len];
    memclr (temp, len);
    memcpy (temp, dest.array_, dest.length ());
    memcpy (temp + dest.length (), str.c_str (), str.length ());
    delete dest.array_;
    dest.array_ = temp;
    return dest;
  };
};
