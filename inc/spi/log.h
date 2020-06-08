/* LOG.H - Master header file for log system.
 * Southeastern Policy Institute, 2020
 */

# ifndef  _SPI_LOG_H_
#   define  _SPI_LOG_H_
#   include "spidef.h"
#   include "mutex.h"
#   include "file.h"
#   include "string.h"
#   ifdef   __cplusplus
namespace spi {

  class SPI_LOG_API log : mutex {
    static log* main_instance;
    static const t_char* startup_string;
    static const t_char* filename_ext;

    unsigned long host_thread_;
    file file_;
    void* start_time_;
    log (const log&);
    log& operator= (const log&);
    log (void);
  public:
    log (const string<t_char>&);
    ~log (void);
    unsigned long operator() (const string<t_char>&);
    static inline log& stdout (void) {
      if (!main_instance)
        main_instance = new log ();
      return *main_instance;
    };
  };

};
#   endif   /* __cplusplus */
# endif   /* _SPI_LOG_H_ */
