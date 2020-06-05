/* LOG.H - Master header file for log system.
 * Southeastern Policy Institute, 2020
 */

# ifndef  _SPI_LOG_H_
#   define  _SPI_LOG_H_
#   include "spidef.h"
#   ifdef   __cplusplus
namespace spi {
  extern "C" {
#   endif   /* __cplusplus */

    /* Log a string to log file. */
    SPI_LOG_API unsigned long spi_log (const void*);

    /* Get host thread ID. */
    SPI_LOG_API unsigned long spi_host_thread (void);

#   ifdef   __cplusplus
  };

  /* C++ Wrapper Class */
  class log {
    log (void) = delete;
    log (const log&) = delete;
    log& operator=(const log&) = delete;
    ~log (void) = delete;
  public:
    /* Log a string to file. */
    static inline unsigned long Log (const void* text) {
      return spi_log (text);
    };

    /* Get host thread ID. */
    static inline unsigned long HostThreadId (void) {
      return spi_host_thread ();
    };
  };
};
#   endif   /* __cplusplus */
# endif   /* _SPI_LOG_H_ */
