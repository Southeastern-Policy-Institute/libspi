/* VARIANT.H - Visual Basic Variant Type Implementation
 * Southeastern Policy Institute, 2020
 */

# if !defined(_SPI_VARIANT_HPP_)
#   define  _SPI_VARIANT_HPP_
#   include "types.h"
#   if defined(__cplusplus)
namespace spi {
  namespace types {
#   endif /* __cplusplus */
  
    typedef struct {
      uint32_t  clSize;
      uint32_t  rpcReserved;
      VarType   vt;
      uint16_t  wReserved1;
      uint16_t  wReserved2;
      uint16_t  wReserved3;
      union {
        Boolean   boolVal;
        Byte      bVal;
        Integer   iVal;
        Long      lVal;
        uLongLong llVal;
        Object    oVal;
        bString   sRef;
      };
    } Variant;

#   if defined(__cplusplus)
  };
};
#   endif /* __cplusplus */
# endif /* _SPI_VARIANT_HPP_ */
