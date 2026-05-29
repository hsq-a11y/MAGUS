/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE273_Improper_Check_for_Dropped_Privileges__w32_ImpersonateNamedPipeClient_15.c
Label Definition File: CWE273_Improper_Check_for_Dropped_Privileges__w32.label.xml
Template File: point-note-15.tmpl.c
*/
/*
 * @description
 * CWE: 273 Improper Check for Dropped Privileges
 * Sinks: ImpersonateNamedPipeClient
 *    Case1Sink: Check if ImpersonateNamedPipeClient() succeeded or not
 *    Case0Sink : Failed to check return status of ImpersonateNamedPipeClient()
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#pragma comment(lib, "advapi32.lib")
#define BUFSIZE 1024

#ifndef OMITCASE0

void CWE273_Improper_Check_for_Dropped_Privileges__w32_ImpersonateNamedPipeClient_15_case0()
{
    switch(6)
    {
    case 6:
    {
        HANDLE hPipe = INVALID_HANDLE_VALUE;
        hPipe = CreateNamedPipeA(
                    "\\\\.\\pipe\\test_pipe",
                    PIPE_ACCESS_DUPLEX | FILE_FLAG_FIRST_PIPE_INSTANCE,
                    PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
                    PIPE_UNLIMITED_INSTANCES,
                    BUFSIZE,
                    BUFSIZE,
                    NMPWAIT_USE_DEFAULT_WAIT,
                    NULL);
        if (hPipe == INVALID_HANDLE_VALUE)
        {
            exit(1);
        }
        /* ConnectNamedPipe returns failure if a client connected between CreateNamedPipe and now,
         * which isn't actually an error in terms of waiting for a client. */
        if (!ConnectNamedPipe(hPipe, NULL) && GetLastError() != ERROR_PIPE_CONNECTED)
        {
            CloseHandle(hPipe);
            exit(1);
        }
        /* NOTE: Failed to check return status of ImpersonateNamedPipeClient
         * -- However, since we're not even DOING anything with the pipe
         * it's debatable whether this is really a bug
         */
        ImpersonateNamedPipeClient(hPipe);
        printLine("Impersonated");
        if (!RevertToSelf())
        {
            exit(1);
        }
        CloseHandle(hPipe);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case11() changes the switch to switch(5) */
static void case11()
{
    switch(5)
    {
    case 6:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    default:
    {
        HANDLE hPipe = INVALID_HANDLE_VALUE;
        hPipe = CreateNamedPipeA(
                    "\\\\.\\pipe\\test_pipe",
                    PIPE_ACCESS_DUPLEX | FILE_FLAG_FIRST_PIPE_INSTANCE,
                    PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
                    PIPE_UNLIMITED_INSTANCES,
                    BUFSIZE,
                    BUFSIZE,
                    NMPWAIT_USE_DEFAULT_WAIT,
                    NULL);
        if (hPipe == INVALID_HANDLE_VALUE)
        {
            exit(1);
        }
        /* ConnectNamedPipe returns failure if a client connected between CreateNamedPipe and now,
         * which isn't actually an error in terms of waiting for a client. */
        if (!ConnectNamedPipe(hPipe, NULL) && GetLastError() != ERROR_PIPE_CONNECTED)
        {
            CloseHandle(hPipe);
            exit(1);
        }
        /* ALT: Check if "ImpersonateNamedPipeClient" succeeded or not */
        if (!ImpersonateNamedPipeClient(hPipe))
        {
            printLine("Failed to impersonate");
        }
        else
        {
            printLine("Impersonated");
            if (!RevertToSelf())
            {
                exit(1);
            }
        }
        CloseHandle(hPipe);
    }
    break;
    }
}

/* case12() reverses the blocks in the switch */
static void case12()
{
    switch(6)
    {
    case 6:
    {
        HANDLE hPipe = INVALID_HANDLE_VALUE;
        hPipe = CreateNamedPipeA(
                    "\\\\.\\pipe\\test_pipe",
                    PIPE_ACCESS_DUPLEX | FILE_FLAG_FIRST_PIPE_INSTANCE,
                    PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
                    PIPE_UNLIMITED_INSTANCES,
                    BUFSIZE,
                    BUFSIZE,
                    NMPWAIT_USE_DEFAULT_WAIT,
                    NULL);
        if (hPipe == INVALID_HANDLE_VALUE)
        {
            exit(1);
        }
        /* ConnectNamedPipe returns failure if a client connected between CreateNamedPipe and now,
         * which isn't actually an error in terms of waiting for a client. */
        if (!ConnectNamedPipe(hPipe, NULL) && GetLastError() != ERROR_PIPE_CONNECTED)
        {
            CloseHandle(hPipe);
            exit(1);
        }
        /* ALT: Check if "ImpersonateNamedPipeClient" succeeded or not */
        if (!ImpersonateNamedPipeClient(hPipe))
        {
            printLine("Failed to impersonate");
        }
        else
        {
            printLine("Impersonated");
            if (!RevertToSelf())
            {
                exit(1);
            }
        }
        CloseHandle(hPipe);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    }
}

void CWE273_Improper_Check_for_Dropped_Privileges__w32_ImpersonateNamedPipeClient_15_case1()
{
    case11();
    case12();
}

#endif /* OMITCASE1 */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITCASE1
    printLine("Calling case1()...");
    CWE273_Improper_Check_for_Dropped_Privileges__w32_ImpersonateNamedPipeClient_15_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE273_Improper_Check_for_Dropped_Privileges__w32_ImpersonateNamedPipeClient_15_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
