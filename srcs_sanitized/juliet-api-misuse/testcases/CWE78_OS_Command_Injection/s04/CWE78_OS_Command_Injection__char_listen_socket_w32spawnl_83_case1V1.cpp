/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_listen_socket_w32spawnl_83_case1V1.cpp
Label Definition File: CWE78_OS_Command_Injection.strings.label.xml
Template File: sources-sink-83_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * Case0Source: listen_socket Read data using a listen socket (server side)
 * Case1Source: Fixed string
 * Sinks: w32spawnl
 *    Case0Sink : execute command with spawnl
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE78_OS_Command_Injection__char_listen_socket_w32spawnl_83.h"

#include <process.h>

namespace CWE78_OS_Command_Injection__char_listen_socket_w32spawnl_83
{
CWE78_OS_Command_Injection__char_listen_socket_w32spawnl_83_case1V1::CWE78_OS_Command_Injection__char_listen_socket_w32spawnl_83_case1V1(char * dataCopy)
{
    data = dataCopy;
    /* ALT: Append a fixed string to data (not user / external input) */
    strcat(data, "*.*");
}

CWE78_OS_Command_Injection__char_listen_socket_w32spawnl_83_case1V1::~CWE78_OS_Command_Injection__char_listen_socket_w32spawnl_83_case1V1()
{
    /* spawnl - specify the path where the command is located */
    /* NOTE: Execute command without validating input possibly leading to command injection */
    _spawnl(_P_WAIT, COMMAND_INT_PATH, COMMAND_INT_PATH, COMMAND_ARG1, COMMAND_ARG3, NULL);
}
}
#endif /* OMITCASE1 */
