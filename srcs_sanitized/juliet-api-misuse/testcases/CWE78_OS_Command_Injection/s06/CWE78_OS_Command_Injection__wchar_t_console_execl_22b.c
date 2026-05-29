/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__wchar_t_console_execl_22b.c
Label Definition File: CWE78_OS_Command_Injection.strings.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * Case0Source: console Read input from the console
 * Case1Source: Fixed string
 * Sink: execl
 *    Case0Sink : execute command with wexecl
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define COMMAND_INT_PATH L"%WINDIR%\\system32\\cmd.exe"
#define COMMAND_INT L"cmd.exe"
#define COMMAND_ARG1 L"/c"
#define COMMAND_ARG2 L"dir "
#define COMMAND_ARG3 data
#else /* NOT _WIN32 */
#include <unistd.h>
#define COMMAND_INT_PATH L"/bin/sh"
#define COMMAND_INT L"sh"
#define COMMAND_ARG1 L"-c"
#define COMMAND_ARG2 L"ls "
#define COMMAND_ARG3 data
#endif

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the source function */
extern int CWE78_OS_Command_Injection__wchar_t_console_execl_22_case0Global;

wchar_t * CWE78_OS_Command_Injection__wchar_t_console_execl_22_case0Source(wchar_t * data)
{
    if(CWE78_OS_Command_Injection__wchar_t_console_execl_22_case0Global)
    {
        {
            /* Read input from the console */
            size_t dataLen = wcslen(data);
            /* if there is room in data, read into it from the console */
            if (100-dataLen > 1)
            {
                /* NOTE: Read data from the console */
                if (fgetws(data+dataLen, (int)(100-dataLen), stdin) != NULL)
                {
                    /* The next few lines remove the carriage return from the string that is
                     * inserted by fgetws() */
                    dataLen = wcslen(data);
                    if (dataLen > 0 && data[dataLen-1] == L'\n')
                    {
                        data[dataLen-1] = L'\0';
                    }
                }
                else
                {
                    printLine("fgetws() failed");
                    /* Restore NUL terminator if fgetws fails */
                    data[dataLen] = L'\0';
                }
            }
        }
    }
    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the source functions. */
extern int CWE78_OS_Command_Injection__wchar_t_console_execl_22_case1V11Global;
extern int CWE78_OS_Command_Injection__wchar_t_console_execl_22_case1V12Global;

/* case1V11() - use case1source and case0sink by setting the static variable to false instead of true */
wchar_t * CWE78_OS_Command_Injection__wchar_t_console_execl_22_case1V11Source(wchar_t * data)
{
    if(CWE78_OS_Command_Injection__wchar_t_console_execl_22_case1V11Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: Append a fixed string to data (not user / external input) */
        wcscat(data, L"*.*");
    }
    return data;
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the if in the source function */
wchar_t * CWE78_OS_Command_Injection__wchar_t_console_execl_22_case1V12Source(wchar_t * data)
{
    if(CWE78_OS_Command_Injection__wchar_t_console_execl_22_case1V12Global)
    {
        /* ALT: Append a fixed string to data (not user / external input) */
        wcscat(data, L"*.*");
    }
    return data;
}

#endif /* OMITCASE1 */
