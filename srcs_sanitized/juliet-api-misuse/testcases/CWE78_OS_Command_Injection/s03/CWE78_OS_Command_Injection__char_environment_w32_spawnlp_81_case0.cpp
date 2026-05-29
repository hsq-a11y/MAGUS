/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_environment_w32_spawnlp_81_case0.cpp
Label Definition File: CWE78_OS_Command_Injection.strings.label.xml
Template File: sources-sink-81_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * Case0Source: environment Read input from an environment variable
 * Case1Source: Fixed string
 * Sinks: w32_spawnlp
 *    Case0Sink : execute command with spawnlp
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE78_OS_Command_Injection__char_environment_w32_spawnlp_81.h"

#include <process.h>

namespace CWE78_OS_Command_Injection__char_environment_w32_spawnlp_81
{

void CWE78_OS_Command_Injection__char_environment_w32_spawnlp_81_case0::action(char * data) const
{
    /* spawnlp - searches for the location of the command among
     * the directories specified by the PATH environment variable */
    /* NOTE: Execute command without validating input possibly leading to command injection */
    _spawnlp(_P_WAIT, COMMAND_INT, COMMAND_INT, COMMAND_ARG1, COMMAND_ARG3, NULL);
}

}
#endif /* OMITCASE0 */
