/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_file_w32_spawnv_82_case0.cpp
Label Definition File: CWE78_OS_Command_Injection.strings.label.xml
Template File: sources-sink-82_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * Case0Source: file Read input from a file
 * Case1Source: Fixed string
 * Sinks: w32_spawnv
 *    Case0Sink : execute command with spawnv
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE78_OS_Command_Injection__char_file_w32_spawnv_82.h"

#include <process.h>

namespace CWE78_OS_Command_Injection__char_file_w32_spawnv_82
{

void CWE78_OS_Command_Injection__char_file_w32_spawnv_82_case0::action(char * data)
{
    {
        char *args[] = {COMMAND_INT_PATH, COMMAND_ARG1, COMMAND_ARG3, NULL};
        /* spawnv - specify the path where the command is located */
        /* NOTE: Execute command without validating input possibly leading to command injection */
        _spawnv(_P_WAIT, COMMAND_INT_PATH, args);
    }
}

}
#endif /* OMITCASE0 */
