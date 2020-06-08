/* SPI.H - Master header file for libspi.
 * Southeastern Policy Institute, 2020
 */

# ifndef  _SPI_H_
#   define  _SPI_H_
#   include "spi/spidef.h"
#   include "spi/string.h"
#   include "spi/mutex.h"
#   include "spi/vector.h"
#   include "spi/file.h"
#   include "spi/log.h"
#   ifdef   __cplusplus
extern "C" {
#   endif /* __cplusplus */
  // (size)
  SPI_LOG_API void* malloc (__SIZE_TYPE__);
  // (num, size)
  SPI_LOG_API void* calloc (__SIZE_TYPE__, __SIZE_TYPE__);
  // (pointer to memory)
  SPI_LOG_API void free (void*);
#   ifdef   __cplusplus
};
#   endif /* __cplusplus */
# endif /* _SPI_H_ */
