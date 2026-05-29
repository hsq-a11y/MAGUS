/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_connect_socket_w32_spawnvp_84_case1V1.cpp
Label Definition File: CWE78_OS_Command_Injection.strings.label.xml
Template File: sources-sink-84_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * Case0Source: connect_socket Read data using a connect socket (client side)
 * Case1Source: Fixed string
 * Sinks: w32_spawnvp
 *    Case0Sink : execute command with spawnvp
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE78_OS_Command_Injection__char_connect_socket_w32_spawnvp_84.h"

#include <process.h>

namespace CWE78_OS_Command_Injection__char_connect_socket_w32_spawnvp_84
{
CWE78_OS_Command_Injection__char_connect_socket_w32_spawnvp_84_case1V1::CWE78_OS_Command_Injection__char_connect_socket_w32_spawnvp_84_case1V1(char * dataCopy)
{
    data = dataCopy;
    /* ALT: Append a fixed string to data (not user / external input) */
    strcat(data, "*.*");
}

CWE78_OS_Command_Injection__char_connect_socket_w32_spawnvp_84_case1V1::~CWE78_OS_Command_Injection__char_connect_socket_w32_spawnvp_84_case1V1()
{
    {
        char *args[] = {COMMAND_INT_PATH, COMMAND_ARG1, COMMAND_ARG3, NULL};
        /* spawnvp - searches for the location of the command among
         * the directories specified by the PATH environment variable */
        /* NOTE: Execute command without validating input possibly leading to command injection */
        _spawnvp(_P_WAIT, COMMAND_INT, args);
    }
}
}
#endif /* OMITCASE1 */
