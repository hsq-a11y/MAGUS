#ifndef MAGUS_JULIET_WIN_COMPAT_H
#define MAGUS_JULIET_WIN_COMPAT_H

#include "windows.h"
#include "process.h"
#include "direct.h"
#include "io.h"
#include <stdio.h>

#if defined(__GNUC__) || defined(__clang__)
__attribute__((constructor)) static void magus_juliet_unbuffer_stdio(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}
#endif

#endif
