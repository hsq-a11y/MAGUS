/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__wchar_t_file_w32_spawnlp_84_case1V1.cpp
Label Definition File: CWE78_OS_Command_Injection.strings.label.xml
Template File: sources-sink-84_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * Case0Source: file Read input from a file
 * Case1Source: Fixed string
 * Sinks: w32_spawnlp
 *    Case0Sink : execute command with wspawnlp
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE78_OS_Command_Injection__wchar_t_file_w32_spawnlp_84.h"

#include <process.h>

namespace CWE78_OS_Command_Injection__wchar_t_file_w32_spawnlp_84
{
CWE78_OS_Command_Injection__wchar_t_file_w32_spawnlp_84_case1V1::CWE78_OS_Command_Injection__wchar_t_file_w32_spawnlp_84_case1V1(wchar_t * dataCopy)
{
    data = dataCopy;
    /* ALT: Append a fixed string to data (not user / external input) */
    wcscat(data, L"*.*");
}

CWE78_OS_Command_Injection__wchar_t_file_w32_spawnlp_84_case1V1::~CWE78_OS_Command_Injection__wchar_t_file_w32_spawnlp_84_case1V1()
{
    /* wspawnlp - searches for the location of the command among
     * the directories specified by the PATH environment variable */
    /* NOTE: Execute command without validating input possibly leading to command injection */
    _wspawnlp(_P_WAIT, COMMAND_INT, COMMAND_INT, COMMAND_ARG1, COMMAND_ARG3, NULL);
}
}
#endif /* OMITCASE1 */
