#ifndef MAGUS_JULIET_WIN_SHIM_WINDOWS_H
#define MAGUS_JULIET_WIN_SHIM_WINDOWS_H

#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <wchar.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef int BOOL;
typedef int INT;
typedef unsigned int UINT;
typedef long LONG;
typedef uint32_t DWORD;
typedef uint32_t ULONG;
typedef unsigned short WORD;
typedef unsigned char BYTE;
typedef unsigned char UCHAR;
typedef uintptr_t ULONG_PTR;
typedef intptr_t HANDLE;
typedef HANDLE HMODULE;
typedef HANDLE HINSTANCE;
typedef HANDLE HKEY;
typedef HANDLE HUSKEY;
typedef HANDLE DLL_DIRECTORY_COOKIE;
typedef HANDLE HCRYPTPROV;
typedef HANDLE HCRYPTKEY;
typedef HANDLE HCRYPTHASH;
typedef void *LPVOID;
typedef const void *LPCVOID;
typedef char *LPSTR;
typedef wchar_t *LPWSTR;
typedef const char *LPCSTR;
typedef const wchar_t *LPCWSTR;
typedef DWORD *LPDWORD;
typedef BYTE *LPBYTE;
typedef LONG LSTATUS;
typedef int ALG_ID;
typedef int FARPROC;

typedef enum _SECURITY_IMPERSONATION_LEVEL {
    SecurityAnonymous,
    SecurityIdentification,
    SecurityImpersonation,
    SecurityDelegation
} SECURITY_IMPERSONATION_LEVEL;

typedef struct _SECURITY_ATTRIBUTES {
    DWORD nLength;
    LPVOID lpSecurityDescriptor;
    BOOL bInheritHandle;
} SECURITY_ATTRIBUTES, *LPSECURITY_ATTRIBUTES;

typedef struct _STARTUPINFOA {
    DWORD cb;
    LPSTR lpReserved;
    LPSTR lpDesktop;
    LPSTR lpTitle;
    DWORD dwX;
    DWORD dwY;
    DWORD dwXSize;
    DWORD dwYSize;
    DWORD dwXCountChars;
    DWORD dwYCountChars;
    DWORD dwFillAttribute;
    DWORD dwFlags;
    WORD wShowWindow;
    WORD cbReserved2;
    BYTE *lpReserved2;
    HANDLE hStdInput;
    HANDLE hStdOutput;
    HANDLE hStdError;
} STARTUPINFOA, *LPSTARTUPINFOA;

typedef struct _STARTUPINFOW {
    DWORD cb;
    LPWSTR lpReserved;
    LPWSTR lpDesktop;
    LPWSTR lpTitle;
    DWORD dwX;
    DWORD dwY;
    DWORD dwXSize;
    DWORD dwYSize;
    DWORD dwXCountChars;
    DWORD dwYCountChars;
    DWORD dwFillAttribute;
    DWORD dwFlags;
    WORD wShowWindow;
    WORD cbReserved2;
    BYTE *lpReserved2;
    HANDLE hStdInput;
    HANDLE hStdOutput;
    HANDLE hStdError;
} STARTUPINFOW, *LPSTARTUPINFOW;

typedef struct _PROCESS_INFORMATION {
    HANDLE hProcess;
    HANDLE hThread;
    DWORD dwProcessId;
    DWORD dwThreadId;
} PROCESS_INFORMATION, *LPPROCESS_INFORMATION;

#ifdef UNICODE
typedef STARTUPINFOW STARTUPINFO;
typedef LPSTARTUPINFOW LPSTARTUPINFO;
#else
typedef STARTUPINFOA STARTUPINFO;
typedef LPSTARTUPINFOA LPSTARTUPINFO;
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef WINAPI
#define WINAPI
#endif

#ifndef __stdcall
#define __stdcall
#endif

#ifndef __try
#define __try if (1)
#endif

#ifndef __except
#define __except(expr) else
#endif

#ifndef GetExceptionCode
#define GetExceptionCode() 0
#endif

#ifndef NULL
#define NULL ((void *)0)
#endif

#ifndef MAX_PATH
#define MAX_PATH 260
#endif

#ifndef INFINITE
#define INFINITE 0xffffffffUL
#endif

#define WAIT_OBJECT_0 0
#define WAIT_FAILED 0xffffffffUL

#define INVALID_HANDLE_VALUE ((HANDLE)(intptr_t)-1)
#define DETACHED_PROCESS 0x00000008UL

#define GENERIC_READ 0x80000000UL
#define GENERIC_WRITE 0x40000000UL
#define FILE_SHARE_READ 0x00000001UL
#define FILE_SHARE_WRITE 0x00000002UL
#define CREATE_NEW 1UL
#define CREATE_ALWAYS 2UL
#define OPEN_EXISTING 3UL
#define OPEN_ALWAYS 4UL
#define TRUNCATE_EXISTING 5UL
#define FILE_ATTRIBUTE_NORMAL 0x00000080UL
#define FILE_FLAG_FIRST_PIPE_INSTANCE 0x00080000UL
#define PIPE_ACCESS_DUPLEX 0x00000003UL
#define PIPE_TYPE_BYTE 0x00000000UL
#define PIPE_TYPE_MESSAGE 0x00000004UL
#define PIPE_READMODE_BYTE 0x00000000UL
#define PIPE_READMODE_MESSAGE 0x00000002UL
#define PIPE_WAIT 0x00000000UL
#define PIPE_UNLIMITED_INSTANCES 255UL
#define NMPWAIT_USE_DEFAULT_WAIT 0UL

#define LOGON32_LOGON_NETWORK 3UL
#define LOGON32_PROVIDER_DEFAULT 0UL

#define TOKEN_ASSIGN_PRIMARY 0x0001UL
#define TOKEN_DUPLICATE 0x0002UL
#define TOKEN_IMPERSONATE 0x0004UL
#define TOKEN_QUERY 0x0008UL
#define TOKEN_ALL_ACCESS 0x000F01FFUL

#define ERROR_SUCCESS 0L
#define ERROR_PIPE_CONNECTED 535L
#define KEY_READ 0x20019UL
#define KEY_WRITE 0x20006UL
#define REG_OPTION_NON_VOLATILE 0UL
#define REG_SZ 1UL
#define HKEY_CURRENT_USER ((HKEY)(intptr_t)0x1001)
#define HKEY_LOCAL_MACHINE ((HKEY)(intptr_t)0x1002)

#define STATUS_NO_MEMORY 0xC0000017UL

#ifndef _TRUNCATE
#define _TRUNCATE ((size_t)-1)
#endif

#ifndef _snprintf
#define _snprintf snprintf
#endif

#ifndef _snwprintf
#define _snwprintf swprintf
#endif

#ifndef _vsnprintf
#define _vsnprintf vsnprintf
#endif

#ifndef _vsnwprintf
#define _vsnwprintf vswprintf
#endif

#ifndef _malloca
#include <alloca.h>
#define _malloca alloca
#endif

#ifndef _alloca
#include <alloca.h>
#define _alloca alloca
#endif

BOOL WINAPI SetComputerNameA(LPCSTR lpComputerName);
BOOL WINAPI SetComputerNameW(LPCWSTR lpComputerName);
DWORD WINAPI WaitForSingleObject(HANDLE hHandle, DWORD dwMilliseconds);
BOOL WINAPI CloseHandle(HANDLE hObject);
DWORD WINAPI GetLastError(void);

HMODULE WINAPI LoadLibraryA(LPCSTR lpLibFileName);
HMODULE WINAPI LoadLibraryW(LPCWSTR lpLibFileName);
BOOL WINAPI FreeLibrary(HMODULE hLibModule);
FARPROC WINAPI GetProcAddress(HMODULE hModule, LPCSTR lpProcName);

HANDLE WINAPI CreateFileA(
    LPCSTR lpFileName,
    DWORD dwDesiredAccess,
    DWORD dwShareMode,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    DWORD dwCreationDisposition,
    DWORD dwFlagsAndAttributes,
    HANDLE hTemplateFile);
HANDLE WINAPI CreateFileW(
    LPCWSTR lpFileName,
    DWORD dwDesiredAccess,
    DWORD dwShareMode,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    DWORD dwCreationDisposition,
    DWORD dwFlagsAndAttributes,
    HANDLE hTemplateFile);

HANDLE WINAPI CreateMutexA(LPSECURITY_ATTRIBUTES lpMutexAttributes, BOOL bInitialOwner, LPCSTR lpName);
HANDLE WINAPI CreateMutexW(LPSECURITY_ATTRIBUTES lpMutexAttributes, BOOL bInitialOwner, LPCWSTR lpName);
HANDLE WINAPI CreateNamedPipeA(LPCSTR lpName, DWORD dwOpenMode, DWORD dwPipeMode, DWORD nMaxInstances, DWORD nOutBufferSize, DWORD nInBufferSize, DWORD nDefaultTimeOut, LPSECURITY_ATTRIBUTES lpSecurityAttributes);
HANDLE WINAPI CreateNamedPipeW(LPCWSTR lpName, DWORD dwOpenMode, DWORD dwPipeMode, DWORD nMaxInstances, DWORD nOutBufferSize, DWORD nInBufferSize, DWORD nDefaultTimeOut, LPSECURITY_ATTRIBUTES lpSecurityAttributes);
BOOL WINAPI ConnectNamedPipe(HANDLE hNamedPipe, LPVOID lpOverlapped);

BOOL WINAPI CreateProcessA(
    LPCSTR lpApplicationName,
    LPSTR lpCommandLine,
    LPSECURITY_ATTRIBUTES lpProcessAttributes,
    LPSECURITY_ATTRIBUTES lpThreadAttributes,
    BOOL bInheritHandles,
    DWORD dwCreationFlags,
    LPVOID lpEnvironment,
    LPCSTR lpCurrentDirectory,
    LPSTARTUPINFOA lpStartupInfo,
    LPPROCESS_INFORMATION lpProcessInformation);
BOOL WINAPI CreateProcessW(
    LPCWSTR lpApplicationName,
    LPWSTR lpCommandLine,
    LPSECURITY_ATTRIBUTES lpProcessAttributes,
    LPSECURITY_ATTRIBUTES lpThreadAttributes,
    BOOL bInheritHandles,
    DWORD dwCreationFlags,
    LPVOID lpEnvironment,
    LPCWSTR lpCurrentDirectory,
    LPSTARTUPINFOW lpStartupInfo,
    LPPROCESS_INFORMATION lpProcessInformation);
BOOL WINAPI CreateProcessAsUserA(
    HANDLE hToken,
    LPCSTR lpApplicationName,
    LPSTR lpCommandLine,
    LPSECURITY_ATTRIBUTES lpProcessAttributes,
    LPSECURITY_ATTRIBUTES lpThreadAttributes,
    BOOL bInheritHandles,
    DWORD dwCreationFlags,
    LPVOID lpEnvironment,
    LPCSTR lpCurrentDirectory,
    LPSTARTUPINFOA lpStartupInfo,
    LPPROCESS_INFORMATION lpProcessInformation);
BOOL WINAPI CreateProcessAsUserW(
    HANDLE hToken,
    LPCWSTR lpApplicationName,
    LPWSTR lpCommandLine,
    LPSECURITY_ATTRIBUTES lpProcessAttributes,
    LPSECURITY_ATTRIBUTES lpThreadAttributes,
    BOOL bInheritHandles,
    DWORD dwCreationFlags,
    LPVOID lpEnvironment,
    LPCWSTR lpCurrentDirectory,
    LPSTARTUPINFOW lpStartupInfo,
    LPPROCESS_INFORMATION lpProcessInformation);

BOOL WINAPI LogonUserA(LPCSTR lpszUsername, LPCSTR lpszDomain, LPCSTR lpszPassword, DWORD dwLogonType, DWORD dwLogonProvider, HANDLE *phToken);
BOOL WINAPI LogonUserW(LPCWSTR lpszUsername, LPCWSTR lpszDomain, LPCWSTR lpszPassword, DWORD dwLogonType, DWORD dwLogonProvider, HANDLE *phToken);
BOOL WINAPI ImpersonateSelf(SECURITY_IMPERSONATION_LEVEL ImpersonationLevel);
BOOL WINAPI ImpersonateNamedPipeClient(HANDLE hNamedPipe);
BOOL WINAPI RevertToSelf(void);
BOOL WINAPI OpenProcessToken(HANDLE ProcessHandle, DWORD DesiredAccess, HANDLE *TokenHandle);
BOOL WINAPI DuplicateTokenEx(HANDLE hExistingToken, DWORD dwDesiredAccess, LPSECURITY_ATTRIBUTES lpTokenAttributes, int ImpersonationLevel, int TokenType, HANDLE *phNewToken);
BOOL WINAPI VirtualLock(LPVOID lpAddress, size_t dwSize);
BOOL WINAPI VirtualUnlock(LPVOID lpAddress, size_t dwSize);

DWORD WINAPI GetTempPathA(DWORD nBufferLength, LPSTR lpBuffer);
DWORD WINAPI GetTempPathW(DWORD nBufferLength, LPWSTR lpBuffer);
UINT WINAPI GetTempFileNameA(LPCSTR lpPathName, LPCSTR lpPrefixString, UINT uUnique, LPSTR lpTempFileName);
UINT WINAPI GetTempFileNameW(LPCWSTR lpPathName, LPCWSTR lpPrefixString, UINT uUnique, LPWSTR lpTempFileName);
DWORD WINAPI GetCurrentDirectoryA(DWORD nBufferLength, LPSTR lpBuffer);
DWORD WINAPI GetCurrentDirectoryW(DWORD nBufferLength, LPWSTR lpBuffer);
DWORD WINAPI GetModuleFileNameA(HMODULE hModule, LPSTR lpFilename, DWORD nSize);
DWORD WINAPI GetModuleFileNameW(HMODULE hModule, LPWSTR lpFilename, DWORD nSize);
UINT WINAPI GetWindowsDirectoryA(LPSTR lpBuffer, UINT uSize);
UINT WINAPI GetWindowsDirectoryW(LPWSTR lpBuffer, UINT uSize);
UINT WINAPI GetSystemDirectoryA(LPSTR lpBuffer, UINT uSize);
UINT WINAPI GetSystemDirectoryW(LPWSTR lpBuffer, UINT uSize);
DWORD WINAPI SearchPathA(LPCSTR lpPath, LPCSTR lpFileName, LPCSTR lpExtension, DWORD nBufferLength, LPSTR lpBuffer, LPSTR *lpFilePart);
DWORD WINAPI SearchPathW(LPCWSTR lpPath, LPCWSTR lpFileName, LPCWSTR lpExtension, DWORD nBufferLength, LPWSTR lpBuffer, LPWSTR *lpFilePart);
BOOL WINAPI SetEnvironmentVariableA(LPCSTR lpName, LPCSTR lpValue);
BOOL WINAPI SetEnvironmentVariableW(LPCWSTR lpName, LPCWSTR lpValue);
BOOL WINAPI SetDllDirectoryA(LPCSTR lpPathName);
BOOL WINAPI SetDllDirectoryW(LPCWSTR lpPathName);
DLL_DIRECTORY_COOKIE WINAPI AddDllDirectory(LPCWSTR NewDirectory);

wchar_t *_wgetenv(const wchar_t *name);
int _putenv(const char *envstring);
int _wputenv(const wchar_t *envstring);

LSTATUS WINAPI RegOpenKeyExA(HKEY hKey, LPCSTR lpSubKey, DWORD ulOptions, DWORD samDesired, HKEY *phkResult);
LSTATUS WINAPI RegOpenKeyExW(HKEY hKey, LPCWSTR lpSubKey, DWORD ulOptions, DWORD samDesired, HKEY *phkResult);
LSTATUS WINAPI RegCreateKeyA(HKEY hKey, LPCSTR lpSubKey, HKEY *phkResult);
LSTATUS WINAPI RegCreateKeyW(HKEY hKey, LPCWSTR lpSubKey, HKEY *phkResult);
LSTATUS WINAPI RegCreateKeyExA(HKEY hKey, LPCSTR lpSubKey, DWORD Reserved, LPSTR lpClass, DWORD dwOptions, DWORD samDesired, LPSECURITY_ATTRIBUTES lpSecurityAttributes, HKEY *phkResult, DWORD *lpdwDisposition);
LSTATUS WINAPI RegCreateKeyExW(HKEY hKey, LPCWSTR lpSubKey, DWORD Reserved, LPWSTR lpClass, DWORD dwOptions, DWORD samDesired, LPSECURITY_ATTRIBUTES lpSecurityAttributes, HKEY *phkResult, DWORD *lpdwDisposition);
LSTATUS WINAPI RegSetValueExA(HKEY hKey, LPCSTR lpValueName, DWORD Reserved, DWORD dwType, const BYTE *lpData, DWORD cbData);
LSTATUS WINAPI RegSetValueExW(HKEY hKey, LPCWSTR lpValueName, DWORD Reserved, DWORD dwType, const BYTE *lpData, DWORD cbData);
LSTATUS WINAPI RegCloseKey(HKEY hKey);

typedef struct _CRITICAL_SECTION {
    void *DebugInfo;
    long LockCount;
    long RecursionCount;
    HANDLE OwningThread;
    HANDLE LockSemaphore;
    unsigned long SpinCount;
} CRITICAL_SECTION;

void WINAPI InitializeCriticalSection(CRITICAL_SECTION *lpCriticalSection);
void WINAPI EnterCriticalSection(CRITICAL_SECTION *lpCriticalSection);
void WINAPI LeaveCriticalSection(CRITICAL_SECTION *lpCriticalSection);
void WINAPI DeleteCriticalSection(CRITICAL_SECTION *lpCriticalSection);

#ifdef UNICODE
#define SetComputerName SetComputerNameW
#define LoadLibrary LoadLibraryW
#define CreateFile CreateFileW
#define CreateMutex CreateMutexW
#define CreateProcess CreateProcessW
#define CreateProcessAsUser CreateProcessAsUserW
#define LogonUser LogonUserW
#define GetTempPath GetTempPathW
#define GetTempFileName GetTempFileNameW
#define GetCurrentDirectory GetCurrentDirectoryW
#define GetModuleFileName GetModuleFileNameW
#define GetWindowsDirectory GetWindowsDirectoryW
#define GetSystemDirectory GetSystemDirectoryW
#define SearchPath SearchPathW
#define SetEnvironmentVariable SetEnvironmentVariableW
#define SetDllDirectory SetDllDirectoryW
#define RegOpenKeyEx RegOpenKeyExW
#define RegCreateKey RegCreateKeyW
#define RegCreateKeyEx RegCreateKeyExW
#define RegSetValueEx RegSetValueExW
#else
#define SetComputerName SetComputerNameA
#define LoadLibrary LoadLibraryA
#define CreateFile CreateFileA
#define CreateMutex CreateMutexA
#define CreateProcess CreateProcessA
#define CreateProcessAsUser CreateProcessAsUserA
#define LogonUser LogonUserA
#define GetTempPath GetTempPathA
#define GetTempFileName GetTempFileNameA
#define GetCurrentDirectory GetCurrentDirectoryA
#define GetModuleFileName GetModuleFileNameA
#define GetWindowsDirectory GetWindowsDirectoryA
#define GetSystemDirectory GetSystemDirectoryA
#define SearchPath SearchPathA
#define SetEnvironmentVariable SetEnvironmentVariableA
#define SetDllDirectory SetDllDirectoryA
#define RegOpenKeyEx RegOpenKeyExA
#define RegCreateKey RegCreateKeyA
#define RegCreateKeyEx RegCreateKeyExA
#define RegSetValueEx RegSetValueExA
#endif

#ifdef __cplusplus
}
#endif

#endif

/* Keep NULL compatible with Juliet's integer HANDLE casts under clang C.
   This must sit outside the include guard because forced compatibility
   includes can happen before std_testcase.h redefines NULL as (void *)0. */
#undef NULL
#define NULL 0
