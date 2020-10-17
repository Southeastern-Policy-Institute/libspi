/* TYPES.H - Visual Basic Type Interoperability
 * Southeastern Policy Institute, 2020
 */

# if !defined(_SPI_TYPES_HPP_)
#   define  _SPI_TYPES_HPP_
#   include <stdint.h>
#   if !defined(ENUM) && defined(__cplusplus)
#     define  ENUM(x,t) enum class x : t
#   elif !defined(ENUM) && !defined(__cplusplus)
#     define  ENUM(x,t) enum x
#   endif /* ENUM */
#   ifdef __cplusplus
namespace spi {
  namespace types {
#   endif /* __cplusplus */

    typedef uint16_t  VarType;    // Size: 2
    typedef uint16_t  Boolean;    // Size: 2
    typedef uint8_t   Byte;       // Size: 1
    typedef int16_t   Integer;    // Size: 2
    typedef uint16_t  uInteger;   // Size: 2
    typedef int32_t   Long;       // Size: 4
    typedef uint32_t  uLong;      // Size: 4
    typedef uint64_t  uLongLong;  // Size: 8
    typedef uintptr_t Object;     // Size: 4
    typedef uint16_t**bString;    // Size: 4

#   ifdef __cplusplus
  };
};
#   endif /* __cplusplus */
# endif /* _SPI_TYPES_HPP_ */
