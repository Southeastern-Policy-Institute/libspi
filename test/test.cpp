
#include <windows.h>
#include "../inc/spi.h"

int WinMain(  HINSTANCE hInstance,
              HINSTANCE hPrevInstance,
              LPSTR     lpCmdLine,
              int       nShowCmd)
{
  spi::string<char> test_string = "TESTING!";
  MessageBoxA (NULL, test_string, "TEST", MB_OK);
  return 0;
};