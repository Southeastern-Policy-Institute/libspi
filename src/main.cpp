
#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x0600
#include <windows.h>
#include "../inc/spi.h"

extern "C" BOOL WINAPI DllMain (HINSTANCE hinst,
                                DWORD reason,
                                LPVOID reserved)
{
  switch (reason) {
  case DLL_PROCESS_ATTACH:
    spi::log::stdout ();
  case DLL_PROCESS_DETACH:
    return TRUE;
  default:
    break;
  };

  return FALSE;
};
