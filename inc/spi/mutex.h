/* MUTEX.H - Class for manipulating Windows mutex objects.
 * Southeastern Policy Institute, 2020
 */

# ifndef  _SPI_MUTEX_H_
#   define  _SPI_MUTEX_H_
#   ifdef   __cplusplus

namespace spi {

  class mutex {
    void* handle_;
  public:
    mutex (void);
    ~mutex (void);
    mutex (const mutex&) = delete;
    mutex& operator= (const mutex&) = delete;
    
    bool lock (void) const;
    void unlock (void) const;
  };

};

#   endif /* __cplusplus */
# endif /* _SPI_MUTEX_H_ */