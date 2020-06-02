
#include <windows.h>
#include "../inc/spi.h"

int WinMain(  HINSTANCE hInstance,
              HINSTANCE hPrevInstance,
              LPSTR     lpCmdLine,
              int       nShowCmd)
{
  spi::mutex* test_mutex = new spi::mutex ();
  spi::string test_string {"TESTING!"};
  MessageBoxA (NULL, test_string, "TEST", MB_OK);
  delete test_mutex;
  return 0;
};