#ifndef MAGUS_JULIET_WIN_SHIM_PROCESS_H
#define MAGUS_JULIET_WIN_SHIM_PROCESS_H

#include <stdint.h>
#include <stdio.h>
#include <wchar.h>

#ifndef _P_WAIT
#define _P_WAIT 0
#endif
#ifndef _P_NOWAIT
#define _P_NOWAIT 1
#endif

#ifdef __cplusplus
extern "C" {
#endif

intptr_t _spawnl(int mode, const char *cmdname, const char *arg0, ...);
intptr_t _spawnlp(int mode, const char *cmdname, const char *arg0, ...);
intptr_t _spawnv(int mode, const char *cmdname, const char *const *argv);
intptr_t _spawnvp(int mode, const char *cmdname, const char *const *argv);
intptr_t _wspawnl(int mode, const wchar_t *cmdname, const wchar_t *arg0, ...);
intptr_t _wspawnlp(int mode, const wchar_t *cmdname, const wchar_t *arg0, ...);
intptr_t _wspawnv(int mode, const wchar_t *cmdname, const wchar_t *const *argv);
intptr_t _wspawnvp(int mode, const wchar_t *cmdname, const wchar_t *const *argv);

intptr_t _execl(const char *cmdname, const char *arg0, ...);
intptr_t _execlp(const char *cmdname, const char *arg0, ...);
intptr_t _execv(const char *cmdname, const char *const *argv);
intptr_t _execvp(const char *cmdname, const char *const *argv);
intptr_t _wexecl(const wchar_t *cmdname, const wchar_t *arg0, ...);
intptr_t _wexeclp(const wchar_t *cmdname, const wchar_t *arg0, ...);
intptr_t _wexecv(const wchar_t *cmdname, const wchar_t *const *argv);
intptr_t _wexecvp(const wchar_t *cmdname, const wchar_t *const *argv);

uintptr_t _beginthreadex(void *security, unsigned stack_size, unsigned (*start_address)(void *), void *arglist, unsigned initflag, unsigned *thrdaddr);
void _endthreadex(unsigned retval);

wchar_t *_wgetenv(const wchar_t *name);
int _putenv(const char *envstring);
int _wputenv(const wchar_t *envstring);

int _wsystem(const wchar_t *command);
FILE *_popen(const char *command, const char *type);
FILE *_wpopen(const wchar_t *command, const wchar_t *type);
int _pclose(FILE *stream);

#ifdef __cplusplus
}
#endif

#endif
