/* SPI.H - Master header file for libspi.
 * Southeastern Policy Institute, 2020
 */

# if !defined(_SPI_H_)
#   define  _SPI_H_
#   include "spi/types.h"
#   include "spi/algorithm.hpp"
#   include "spi/array.hpp"
#   include "spi/string.hpp"
#   include "spi/stream.hpp"
#   include "spi/list.hpp"
#   include "spi/variant.h"
#   ifdef   __cplusplus
#     define  EXTERN_C extern "C"
#   else
#     define  EXTERN_C extern
#   endif /* __cplusplus */
# endif /* _SPI_H_ */
