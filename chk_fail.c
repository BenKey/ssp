/**
* This file has no copyright assigned and is placed in the Public Domain.
* This file is part of the mingw-w64 runtime package.
* No warranty is given; refer to the file DISCLAIMER.PD within this package.
*/

#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#if ((defined(_MSC_VER) || defined(__MINGW64__)) && !defined(__CYGWIN__))
#  include <intrin.h>
#endif

#include "ssp.h"

void __cdecl ___chk_fail(void)
{
  static const char msg[] = "*** buffer overflow detected ***: terminated\n";
  write(_fileno(stderr), msg, strlen(msg));
  if (IsProcessorFeaturePresent(PF_FASTFAIL_AVAILABLE))
  {
    __fastfail(FAST_FAIL_RANGE_CHECK_FAILURE);
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
