
#include <windows.h>
#include "../inc/spi.h"

int WinMain(  HINSTANCE hInstance,
              HINSTANCE hPrevInstance,
              LPSTR     lpCmdLine,
              int       nShowCmd)
{
  spi::spi_log ("TESTING");
  MessageBoxA (NULL, "TESTING AGAIN", "TEST", MB_OK);
  return 0;
};
