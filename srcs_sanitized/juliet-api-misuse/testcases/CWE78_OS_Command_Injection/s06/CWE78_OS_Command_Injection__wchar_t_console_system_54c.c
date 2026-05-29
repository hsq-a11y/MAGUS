/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__wchar_t_console_system_54c.c
Label Definition File: CWE78_OS_Command_Injection.one_string.label.xml
Template File: sources-sink-54c.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * Case0Source: console Read input from the console
 * Case1Source: Fixed string
 * Sink: system
 *    Case0Sink : Execute command in data using system()
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define FULL_COMMAND L"dir "
#else
#include <unistd.h>
#define FULL_COMMAND L"ls "
#endif

#ifdef _WIN32
#define SYSTEM _wsystem
#else /* NOT _WIN32 */
#define SYSTEM system
#endif

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

/* case0 function declaration */
void CWE78_OS_Command_Injection__wchar_t_console_system_54d_case0Sink(wchar_t * data);

void CWE78_OS_Command_Injection__wchar_t_console_system_54c_case0Sink(wchar_t * data)
{
    CWE78_OS_Command_Injection__wchar_t_console_system_54d_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declaration */
void CWE78_OS_Command_Injection__wchar_t_console_system_54d_case1V1Sink(wchar_t * data);

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE78_OS_Command_Injection__wchar_t_console_system_54c_case1V1Sink(wchar_t * data)
{
    CWE78_OS_Command_Injection__wchar_t_console_system_54d_case1V1Sink(data);
}

#endif /* OMITCASE1 */
