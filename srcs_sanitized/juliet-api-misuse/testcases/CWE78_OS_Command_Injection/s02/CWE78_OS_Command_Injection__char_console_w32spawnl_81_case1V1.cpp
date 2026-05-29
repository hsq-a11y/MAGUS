/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_console_w32spawnl_81_case1V1.cpp
Label Definition File: CWE78_OS_Command_Injection.strings.label.xml
Template File: sources-sink-81_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * Case0Source: console Read input from the console
 * Case1Source: Fixed string
 * Sinks: w32spawnl
 *    Case0Sink : execute command with spawnl
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE78_OS_Command_Injection__char_console_w32spawnl_81.h"

#include <process.h>

namespace CWE78_OS_Command_Injection__char_console_w32spawnl_81
{

void CWE78_OS_Command_Injection__char_console_w32spawnl_81_case1V1::action(char * data) const
{
    /* spawnl - specify the path where the command is located */
    /* NOTE: Execute command without validating input possibly leading to command injection */
    _spawnl(_P_WAIT, COMMAND_INT_PATH, COMMAND_INT_PATH, COMMAND_ARG1, COMMAND_ARG3, NULL);
}

}
#endif /* OMITCASE1 */
