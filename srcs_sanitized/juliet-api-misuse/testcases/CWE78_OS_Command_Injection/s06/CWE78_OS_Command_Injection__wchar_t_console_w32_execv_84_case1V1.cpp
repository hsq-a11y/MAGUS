/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__wchar_t_console_w32_execv_84_case1V1.cpp
Label Definition File: CWE78_OS_Command_Injection.strings.label.xml
Template File: sources-sink-84_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * Case0Source: console Read input from the console
 * Case1Source: Fixed string
 * Sinks: w32_execv
 *    Case0Sink : execute command with wexecv
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE78_OS_Command_Injection__wchar_t_console_w32_execv_84.h"

#include <process.h>
#define EXECV _wexecv

namespace CWE78_OS_Command_Injection__wchar_t_console_w32_execv_84
{
CWE78_OS_Command_Injection__wchar_t_console_w32_execv_84_case1V1::CWE78_OS_Command_Injection__wchar_t_console_w32_execv_84_case1V1(wchar_t * dataCopy)
{
    data = dataCopy;
    /* ALT: Append a fixed string to data (not user / external input) */
    wcscat(data, L"*.*");
}

CWE78_OS_Command_Injection__wchar_t_console_w32_execv_84_case1V1::~CWE78_OS_Command_Injection__wchar_t_console_w32_execv_84_case1V1()
{
    {
        wchar_t *args[] = {COMMAND_INT_PATH, COMMAND_ARG1, COMMAND_ARG3, NULL};
        /* wexecv - specify the path where the command is located */
        /* NOTE: Execute command without validating input possibly leading to command injection */
        EXECV(COMMAND_INT_PATH, args);
    }
}
}
#endif /* OMITCASE1 */
