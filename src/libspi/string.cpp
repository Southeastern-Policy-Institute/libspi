/* STRING.CPP - String manipulation routines.
 * Southeastern Policy Institute, 2020
 */

#include <spi.h>

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

  string& operator<< (string& dest, tchar_t c) {
    __SIZE_TYPE__ len = dest.length () + 2;
    tchar_t* temp = new tchar_t[len];
    memclr (temp, len);
    memcpy (temp, dest.array_, dest.length ());
    temp[dest.length()] = c;
    delete dest.array_;
    dest.array_ = temp;
    return dest;
  };

};
