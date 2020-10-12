/* STRING.HPP - Variable-width character string manipulation.
 * Southeastern Policy Institute, 2020
 */

# if !defined(_SPI_STRING_HPP_)
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
#   ifdef __cplusplus
namespace spi {

  // Variable width NULL terminated string datatype.
  class string : public array<tchar_t> {
  public:
    // Returns the number of characters in a string.
    template<typename T = tchar_t>
    static unsigned int strlen (const T* str) {
      register unsigned int len = 0;
      if (!str)
        return 0;
      while (*str++)
        len++;
      return len;
    };

    string (void) : array (1) { array_[0] = PREFIX_L('\0'); };

    string (unsigned int len) : array (len + 1) {
      memset (array_, PREFIX_L('\0'), len + 1);
    };

    string (const tchar_t* str) : string (strlen (str) + 1) {
      memcpy (array_, str, strlen (str));
    };

#     ifdef UNICODE
    typedef union {
      struct {
        char a;
        char b;
      };
      wchar_t ab;
    } wide_t;

    string (const char* src) : string ((strlen (src)+1)*2) {
      unsigned int output_len = strlen<char> (src) + 1;
      wide_t* output = reinterpret_cast<wide_t*> (array_);
      for (register unsigned int i = 0; i < output_len; i++)
        output[i].a = src[i], output[i].b = '\0';
    };

    operator array<char> (void) {
      const wide_t* lens = reinterpret_cast<const wide_t*> (array_);
      unsigned int output_len = strlen (array_) + 1;
      array<char> output {output_len};
      for (register unsigned int i = 0; i < output_len; i++)
        output[i] = lens[i].a;
      return output;
    };
#     endif /* UNICODE */

    friend string& operator<< (string&, const string&);

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
#   endif
# endif /* _SPI_STRING_HPP_ */
