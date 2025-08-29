/**
* This file has no copyright assigned and is placed in the Public Domain.
* This file is part of the mingw-w64 runtime package.
* No warranty is given; refer to the file DISCLAIMER.PD within this package.
*/

#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "ssp.h"

noreturn void __cdecl __stack_chk_fail(void)
{
  static const char msg[] = "*** stack smashing detected ***: terminated\n";
  write(_fileno(stderr), msg, strlen(msg));
  if (IsProcessorFeaturePresent(PF_FASTFAIL_AVAILABLE))
  {
    __fastfail(FAST_FAIL_STACK_COOKIE_CHECK_FAILURE);
  }
  else
  {
    TerminateProcess(GetCurrentProcess(), STATUS_STACK_BUFFER_OVERRUN);
#ifdef __GNUC__
    __builtin_unreachable();
#elif _MSC_VER
    __assume(0);
#endif
  }
}
