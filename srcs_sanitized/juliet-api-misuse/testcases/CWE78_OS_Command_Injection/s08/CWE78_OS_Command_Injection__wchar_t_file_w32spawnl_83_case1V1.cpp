/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__wchar_t_file_w32spawnl_83_case1V1.cpp
Label Definition File: CWE78_OS_Command_Injection.strings.label.xml
Template File: sources-sink-83_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * Case0Source: file Read input from a file
 * Case1Source: Fixed string
 * Sinks: w32spawnl
 *    Case0Sink : execute command with wspawnl
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE78_OS_Command_Injection__wchar_t_file_w32spawnl_83.h"

#include <process.h>

namespace CWE78_OS_Command_Injection__wchar_t_file_w32spawnl_83
{
CWE78_OS_Command_Injection__wchar_t_file_w32spawnl_83_case1V1::CWE78_OS_Command_Injection__wchar_t_file_w32spawnl_83_case1V1(wchar_t * dataCopy)
{
    data = dataCopy;
    /* ALT: Append a fixed string to data (not user / external input) */
    wcscat(data, L"*.*");
}

CWE78_OS_Command_Injection__wchar_t_file_w32spawnl_83_case1V1::~CWE78_OS_Command_Injection__wchar_t_file_w32spawnl_83_case1V1()
{
    /* wspawnl - specify the path where the command is located */
    /* NOTE: Execute command without validating input possibly leading to command injection */
    _wspawnl(_P_WAIT, COMMAND_INT_PATH, COMMAND_INT_PATH, COMMAND_ARG1, COMMAND_ARG3, NULL);
}
}
#endif /* OMITCASE1 */
