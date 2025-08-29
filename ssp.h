/**
* This file has no copyright assigned and is placed in the Public Domain.
* This file is part of the mingw-w64 runtime package.
* No warranty is given; refer to the file DISCLAIMER.PD within this package.
*/

#pragma once

#include <stdnoreturn.h>

noreturn void __cdecl __chk_fail(void);
char* __cdecl __gets_chk(char* dst, size_t bufsize);
void* __cdecl __memcpy_chk(void* dst, const void* src, size_t n, size_t bufsize);
void* __cdecl __memmove_chk(void* dst, const void* src, size_t n, size_t bufsize);
void* __cdecl __mempcpy_chk(void* dst, const void* src, size_t n, size_t bufsize);
void* __cdecl __memset_chk(void* dst, int c, size_t n, size_t bufsize);
noreturn void __cdecl __stack_chk_fail(void);
char* __cdecl __stpcpy_chk(char* dst, const char* src, size_t bufsize);
char* __cdecl __strcat_chk(char* dst, const char* src, size_t bufsize);
char* __cdecl __strcpy_chk(char* dst, const char* src, size_t bufsize);
char* __cdecl __strncat_chk(char* dst, const char* src, size_t n, size_t bufsize);
char* __cdecl __strncpy_chk(char* dst, const char* src, size_t n, size_t bufsize);
