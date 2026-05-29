/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_console_system_53c.c
Label Definition File: CWE78_OS_Command_Injection.one_string.label.xml
Template File: sources-sink-53c.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * Case0Source: console Read input from the console
 * Case1Source: Fixed string
 * Sink: system
 *    Case0Sink : Execute command in data using system()
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define FULL_COMMAND "dir "
#else
#include <unistd.h>
#define FULL_COMMAND "ls "
#endif

#ifdef _WIN32
#define SYSTEM system
#else /* NOT _WIN32 */
#define SYSTEM system
#endif

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

/* case0 function declaration */
void CWE78_OS_Command_Injection__char_console_system_53d_case0Sink(char * data);

void CWE78_OS_Command_Injection__char_console_system_53c_case0Sink(char * data)
{
    CWE78_OS_Command_Injection__char_console_system_53d_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declaration */
void CWE78_OS_Command_Injection__char_console_system_53d_case1V1Sink(char * data);

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE78_OS_Command_Injection__char_console_system_53c_case1V1Sink(char * data)
{
    CWE78_OS_Command_Injection__char_console_system_53d_case1V1Sink(data);
}

#endif /* OMITCASE1 */
