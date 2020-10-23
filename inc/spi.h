/* SPI.H - Master header file for libspi.
 * Southeastern Policy Institute, 2020
 */

# if !defined(_SPI_H_)
#   define  _SPI_H_
#   include "spi/types.h"
#   include "spi/iostream"
#   include "spi/algorithm.hpp"
#   include "spi/array.hpp"
#   include "spi/string.hpp"
#   include "spi/list.hpp"
#   include "spi/variant.h"
#   include "spi/exception.hpp"
#   ifdef   __cplusplus
#     define  EXTERN_C extern "C"
#   else
#     define  EXTERN_C extern
#   endif /* __cplusplus */
#   if !defined(ALIGN) && defined(__GNUC__)
#     define ALIGN(x) __attribute__ ((aligned (x)))
#   elif !defined(ALIGN) && defined(_MSC_VER)
#     define ALIGN(x) __declspec(align(x))
#   endif /* ALIGN */
# endif /* _SPI_H_ */
