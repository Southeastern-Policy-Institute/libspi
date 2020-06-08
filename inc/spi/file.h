/* FILE.H - File manipulation class.
 * Southeastern Policy Institute, 2020
 */

# ifndef  _SPI_FILE_H_
#   define  _SPI_FILE_H_
#   include "spidef.h"
#   include "mutex.h"
#   include "string.h"
#   ifdef   __cplusplus
namespace spi {

  /* C++ Wrapper Class */
  class SPI_LOG_API file : mutex {
    void* handle_;
    static void* create_file (const void*);
    __SIZE_TYPE__ write_to_file (const void*, __SIZE_TYPE__);
  public:
    file (const file&) = delete;
    file& operator= (const file&) = delete;
    ~file (void);
    inline file (void) : mutex (), handle_ (NULL) {};
    template<typename T> file (const string<T>& path) : mutex (),
                                                        handle_ (NULL)
    { handle_ = create_file (path.operator const T* ()); };
    template<typename T> __SIZE_TYPE__ Write (const string<T>& str) {
      return write_to_file (str.operator const T* (),
                            str.length () * sizeof (T));
    };
    inline operator bool (void) const {
      return handle_ != NULL && handle_ != (void*)-1;
    };
  };
  
};
#   endif   /* __cplusplus */
# endif /* _SPI_FILE_H_ */
