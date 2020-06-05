/* STDDEF.H - Standard Definitions for libspi
 * Southeastern Policy Institute, 2020
 */

# ifndef  _SPI_SPIDEF_H_
#   define  _SPI_SPIDEF_H_
#   ifndef  NULL
#     define NULL (void*)0U
#   endif /* NULL */
#   ifdef   BUILDING_LIBSPI
#     define  SPI_LOG_API __declspec(dllexport)
#   else
#     define  SPI_LOG_API __declspec(dllimport)
#   endif
# endif /* _SPI_SPIDEF_H_ */
