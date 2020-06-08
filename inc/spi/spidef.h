/* STDDEF.H - Standard Definitions for libspi
 * Southeastern Policy Institute, 2020
 */

# ifndef  _SPI_SPIDEF_H_
#   define  _SPI_SPIDEF_H_
#   ifndef  NULL
#     define NULL (void*)0U
#   endif /* NULL */
#   ifndef  __SIZE_TYPE__
#     define __SIZE_TYPE__ unsigned int
#   endif /* __SIZE_TYPE__ */
#   ifdef   BUILDING_LIBSPI
#     define  SPI_LOG_API __declspec(dllexport)
#   else
#     define  SPI_LOG_API __declspec(dllimport)
#   endif
#   define  __SPI_VER_MAJOR__ 0
#   define  __SPI_VER_MINOR__ 1
#   define  __SPI_VER_REVIS__ 20200608
# endif /* _SPI_SPIDEF_H_ */
