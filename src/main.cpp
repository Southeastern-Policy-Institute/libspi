
#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x0600
#include <windows.h>
#include "../inc/spi.h"

BOOL log_init (void);
BOOL log_fini (void);

extern "C" BOOL WINAPI DllMain (HINSTANCE hinst,
                                DWORD reason,
                                LPVOID reserved)
{
  switch (reason) {
  case DLL_PROCESS_ATTACH:
    return log_init ();
  case DLL_PROCESS_DETACH:
    log_fini ();
    return TRUE;
  default:
    break;
  };

  return FALSE;
};
