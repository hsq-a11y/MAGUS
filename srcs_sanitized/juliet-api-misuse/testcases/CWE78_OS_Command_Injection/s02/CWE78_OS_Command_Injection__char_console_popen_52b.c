/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_console_popen_52b.c
Label Definition File: CWE78_OS_Command_Injection.one_string.label.xml
Template File: sources-sink-52b.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * Case0Source: console Read input from the console
 * Case1Source: Fixed string
 * Sink: popen
 *    Case0Sink : Execute command in data using popen()
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
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

/* define POPEN as _popen on Windows and popen otherwise */
#ifdef _WIN32
#define POPEN _popen
#define PCLOSE _pclose
#else /* NOT _WIN32 */
#define POPEN popen
#define PCLOSE pclose
#endif

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

/* case0 function declaration */
void CWE78_OS_Command_Injection__char_console_popen_52c_case0Sink(char * data);

void CWE78_OS_Command_Injection__char_console_popen_52b_case0Sink(char * data)
{
    CWE78_OS_Command_Injection__char_console_popen_52c_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declaration */
void CWE78_OS_Command_Injection__char_console_popen_52c_case1V1Sink(char * data);

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE78_OS_Command_Injection__char_console_popen_52b_case1V1Sink(char * data)
{
    CWE78_OS_Command_Injection__char_console_popen_52c_case1V1Sink(data);
}

#endif /* OMITCASE1 */
