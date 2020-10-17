
# ifdef WIN32
#   include <windows.h>
# endif /* WIN32 */
# include <stdio.h>
# define  COMPILING_BYLAW
# include <spi.h>

# ifdef WIN32
extern "C" int WINAPI WinMain(
  HINSTANCE hInstance,
  HINSTANCE hPrevInstance,
  LPSTR     lpCmdLine,
  int       nShowCmd
) {
# else
int main (void) {
# endif /* WIN32 */


  
  return 0;
};