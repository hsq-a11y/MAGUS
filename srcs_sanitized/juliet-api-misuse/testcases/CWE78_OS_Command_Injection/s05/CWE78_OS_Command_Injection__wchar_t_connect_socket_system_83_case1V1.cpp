/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__wchar_t_connect_socket_system_83_case1V1.cpp
Label Definition File: CWE78_OS_Command_Injection.one_string.label.xml
Template File: sources-sink-83_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * Case0Source: connect_socket Read data using a connect socket (client side)
 * Case1Source: Fixed string
 * Sinks: system
 *    Case0Sink : Execute command in data using system()
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE78_OS_Command_Injection__wchar_t_connect_socket_system_83.h"

#ifdef _WIN32
#define SYSTEM _wsystem
#else /* NOT _WIN32 */
#define SYSTEM system
#endif

namespace CWE78_OS_Command_Injection__wchar_t_connect_socket_system_83
{
CWE78_OS_Command_Injection__wchar_t_connect_socket_system_83_case1V1::CWE78_OS_Command_Injection__wchar_t_connect_socket_system_83_case1V1(wchar_t * dataCopy)
{
    data = dataCopy;
    /* ALT: Append a fixed string to data (not user / external input) */
    wcscat(data, L"*.*");
}

CWE78_OS_Command_Injection__wchar_t_connect_socket_system_83_case1V1::~CWE78_OS_Command_Injection__wchar_t_connect_socket_system_83_case1V1()
{
    /* NOTE: Execute command in data possibly leading to command injection */
    if (SYSTEM(data) != 0)
    {
        printLine("command execution failed!");
        exit(1);
    }
}
}
#endif /* OMITCASE1 */
