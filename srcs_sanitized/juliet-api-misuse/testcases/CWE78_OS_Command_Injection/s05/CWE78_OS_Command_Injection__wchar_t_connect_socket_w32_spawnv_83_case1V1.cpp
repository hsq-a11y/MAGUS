/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__wchar_t_connect_socket_w32_spawnv_83_case1V1.cpp
Label Definition File: CWE78_OS_Command_Injection.strings.label.xml
Template File: sources-sink-83_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * Case0Source: connect_socket Read data using a connect socket (client side)
 * Case1Source: Fixed string
 * Sinks: w32_spawnv
 *    Case0Sink : execute command with wspawnv
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE78_OS_Command_Injection__wchar_t_connect_socket_w32_spawnv_83.h"

#include <process.h>

namespace CWE78_OS_Command_Injection__wchar_t_connect_socket_w32_spawnv_83
{
CWE78_OS_Command_Injection__wchar_t_connect_socket_w32_spawnv_83_case1V1::CWE78_OS_Command_Injection__wchar_t_connect_socket_w32_spawnv_83_case1V1(wchar_t * dataCopy)
{
    data = dataCopy;
    /* ALT: Append a fixed string to data (not user / external input) */
    wcscat(data, L"*.*");
}

CWE78_OS_Command_Injection__wchar_t_connect_socket_w32_spawnv_83_case1V1::~CWE78_OS_Command_Injection__wchar_t_connect_socket_w32_spawnv_83_case1V1()
{
    {
        wchar_t *args[] = {COMMAND_INT_PATH, COMMAND_ARG1, COMMAND_ARG3, NULL};
        /* wspawnv - specify the path where the command is located */
        /* NOTE: Execute command without validating input possibly leading to command injection */
        _wspawnv(_P_WAIT, COMMAND_INT_PATH, args);
    }
}
}
#endif /* OMITCASE1 */
