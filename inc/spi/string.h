/* STRING.H - Lightweight string manipulation routines.
 * Southeastern Policy Institute, 2020
 */

# ifndef  _SPI_STRING_H_
#   define  _SPI_STRING_H_
#   ifndef  __SIZE_TYPE__
#     define  __SIZE_TYPE__ long unsigned int
#   endif /* __SIZE_TYPE__ */
#   ifdef   __cplusplus

namespace spi {

  template <typename T> T* memcpy (T* dest, const T* src, __SIZE_TYPE__ len) {
    T* initial_dest = dest;
    while (len--)
      *dest++ = *src++;
    return initial_dest;
  };

  template <typename T> T* memset (T* dest, const T& val, __SIZE_TYPE__ len) {
    T* initial_dest = dest;
    while (len--)
      *dest++ = val;
    return initial_dest;
  };

  template <typename T> class string {
    T* str_;
  public:
    static __SIZE_TYPE__ strlen (const T* str) {
      __SIZE_TYPE__ len;
      for (len = 0; *str; str++, len++);
      return len;
    };
    inline string (void) : str_ (NULL) {};
    inline string (__SIZE_TYPE__ length) : str_ (NULL) {
      str_ = new T[length];
    };
    inline string (const T* str) : str_ (NULL) {
      if (!str)
        return;
      str_ = new T[strlen (str) + 1];
      if (str_)
        str_ = memcpy (str_, str, strlen (str));
    };
    inline ~string (void) {
      if (!str_)
        return;
      delete str_;
    };
    inline operator const T* (void) const { return str_; };
    inline operator T* (void) { return str_; };
    inline __SIZE_TYPE__ length (void) const { return strlen (str_); };
  };

};

#   endif /* __cplusplus */
# endif /* _SPI_STRING_H_ */