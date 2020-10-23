/* CHAR_TRAITS.HPP - Standard character-type traits
 * Southeastern Policy Institute, 2020
 */

# if !defined(_SPI_CHAR_TRAITS_HPP_) && defined(__cplusplus)
#   define  _SPI_CHAR_TRAITS_HPP_
#   include "types.h"
#   include "string.hpp"

namespace spi {

  struct mbstate_t {
    union {
      struct {
        char a, b;
      };
      wchar_t ab;
    } *arr;
    size_t count, shift_state;
  };

  template <class stateT> class fpos {
  public:
    stateT state (void) const;
    void state (stateT);
  };

  template<class charT> struct char_traits;

  typedef fpos<mbstate_t> streampos;

  typedef fpos<mbstate_t> wstreampos;

  template <> struct char_traits<char> {
    typedef char      char_type;
    typedef int       int_type;
    typedef size_t    off_type;
    typedef streampos pos_type;
    typedef mbstate_t state_type;

    static constexpr bool eq (char_type c, char_type d) noexcept {
      return c == d;
    };

    static constexpr bool lt (char_type c, char_type d) noexcept {
      return !eq (c, d);
    };

    static size_t length (const char_type* s) {
      size_t output = 0;
      while (*s++)
        output++;
      return output;
    };

    static void assign (char_type& r, const char_type& c) noexcept {
      r = c;
    };

    static char_type* assign (char_type* p, size_t n, char_type c) {
      return spi::memset (p, c, n);
    };

    static int compare (const char_type* p, const char_type* q, size_t n) {
      while (n--) { if (!eq(*p, *q)) return lt (*p, *q) ? -1 : 1; ++p; ++q; };
      return 0;
    };

    static const char_type* find (const char_type* p, size_t n,
                                  const char_type& c)
    {
      for (size_t i = 0; i < n; i++)
        if (p[i] == c)
          return &p[i];
      return nullptr;
    };

    static char_type* move (char_type* dest, const char_type* src, size_t n) {
      return spi::memcpy (dest, src, n);
    };

    static char_type* copy (char_type* dest, const char_type* src, size_t n) {
      while (((dest < src && dest + n >= src) || (dest > src)) && src + n >= dest)
        n--;
      return spi::memcpy (dest, src, n);
    };

    static constexpr int_type eof() noexcept { return -1; };

    static constexpr int_type not_eof(int_type c) noexcept {
      return c != -1 ? c : 0;
    };

    static constexpr char_type to_char_type (int_type c) noexcept {
      return c & 0xFF;
    };

    static constexpr int_type to_int_type (char_type c) noexcept {
      return c & 0xFFFFFFFF;
    };

    static constexpr bool eq_int_type (int_type x, int_type y) noexcept {
      return x == y;
    };

  };

#   ifdef UNICODE
  template <> struct char_traits<wchar_t> {
    typedef wchar_t   char_type;
    typedef int       int_type;
    typedef size_t    off_type;
    typedef streampos pos_type;
    typedef mbstate_t state_type;
  };
#   endif /* UNICODE */

};

# endif /* _SPI_CHAR_TRAITS_HPP_ */
