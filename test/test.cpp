
#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x0600
#include <windows.h>
#include "../inc/spi.h"

int WinMain(  HINSTANCE hInstance,
              HINSTANCE hPrevInstance,
              LPSTR     lpCmdLine,
              int       nShowCmd)
{
  spi::string test_string {"TEST_STRING"};
  spi::spi_log (test_string.operator const char* ());
  MessageBoxA (NULL, test_string, "TEST", MB_OK);
  return 0;
};
