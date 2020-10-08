/* STRING.HPP - Variable-width character string manipulation.
 * Southeastern Policy Institute, 2020
 */

# if !defined(_SPI_STRING_HPP_) && defined(__cplusplus)
#   define  _SPI_STRING_HPP_
#   include "algorithm.hpp"
#   include "array.hpp"
#   ifdef   UNICODE
#     define  PREFIX_L(x) L ## x
typedef wchar_t tchar_t;
#   else
#     define  PREFIX_L(x) x
typedef char tchar_t;
#   endif /* UNICODE */

namespace spi {

  // Variable width NULL terminated string datatype.
  class string : public array<tchar_t> {
  public:
    // Returns the number of characters in a string.
    static unsigned int strlen (const tchar_t* str) {
      unsigned int len;
      if (!str)
        return 0;
      for (len = 0; *str; str++, len++);
      return len;
    };

    string (void) : array (1) { array_[0] = PREFIX_L('\0'); };
    string (unsigned int len) : array (len + 1) {
      memset (array_, PREFIX_L('\0'), len + 1);
    };
    string (const tchar_t* str) : array (strlen (str) + 1) {
      memcpy (array_, str, strlen (str));
    };

    bool operator== (const string& target) const {
      if (target.length () != length ())
        return false;
      for (unsigned int i = 0; i < length (); i++)
        if (array_[i] != target[i])
          return false;
      return true;
    };
    inline bool operator!= (const string& target) const {
      return !operator== (target);
    };
    inline unsigned int length (void) const {
      return strlen (array_);
    };
    inline const tchar_t* c_str (void) const { return array_; };
  };

};

# endif /* _SPI_STRING_HPP_ */
