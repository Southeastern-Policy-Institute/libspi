/* VARIANT.H - Variable of variables
 * Southeastern Policy Institute, 2020
 */

# if !defined(_SPI_VARIANT_HPP_)
#   define  _SPI_VARIANT_HPP_
#   include "types.h"
#   if defined(__cplusplus)
namespace spi {
  using namespace types;
#   endif /* __cplusplus */
  
  typedef struct {
    __UINT32_TYPE__ clSize;
    __UINT32_TYPE__ rpcReserved;
    VarType         vt;
    __UINT16_TYPE__ wReserved1;
    __UINT16_TYPE__ wReserved2;
    __UINT16_TYPE__ wReserved3;
    __GNU_EXTENSION union {
      Boolean boolVal;
      Byte bVal;
      Integer iVal;
      Long lVal;
      uLongLong llVal;
      Object oVal;
      bString sRef;
    };
  } Variant;

#   if defined(__cplusplus)
};
#   endif /* __cplusplus */
# endif /* _SPI_VARIANT_HPP_ */
