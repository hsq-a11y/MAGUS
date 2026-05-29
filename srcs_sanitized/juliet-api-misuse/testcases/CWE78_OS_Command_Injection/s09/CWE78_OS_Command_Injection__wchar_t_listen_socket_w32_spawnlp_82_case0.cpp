/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__wchar_t_listen_socket_w32_spawnlp_82_case0.cpp
Label Definition File: CWE78_OS_Command_Injection.strings.label.xml
Template File: sources-sink-82_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * Case0Source: listen_socket Read data using a listen socket (server side)
 * Case1Source: Fixed string
 * Sinks: w32_spawnlp
 *    Case0Sink : execute command with wspawnlp
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE78_OS_Command_Injection__wchar_t_listen_socket_w32_spawnlp_82.h"

#include <process.h>

namespace CWE78_OS_Command_Injection__wchar_t_listen_socket_w32_spawnlp_82
{

void CWE78_OS_Command_Injection__wchar_t_listen_socket_w32_spawnlp_82_case0::action(wchar_t * data)
{
    /* wspawnlp - searches for the location of the command among
     * the directories specified by the PATH environment variable */
    /* NOTE: Execute command without validating input possibly leading to command injection */
    _wspawnlp(_P_WAIT, COMMAND_INT, COMMAND_INT, COMMAND_ARG1, COMMAND_ARG3, NULL);
}

}
#endif /* OMITCASE0 */
