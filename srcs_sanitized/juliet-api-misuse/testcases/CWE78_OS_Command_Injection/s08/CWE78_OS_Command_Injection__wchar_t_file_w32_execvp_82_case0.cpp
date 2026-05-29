/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__wchar_t_file_w32_execvp_82_case0.cpp
Label Definition File: CWE78_OS_Command_Injection.strings.label.xml
Template File: sources-sink-82_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * Case0Source: file Read input from a file
 * Case1Source: Fixed string
 * Sinks: w32_execvp
 *    Case0Sink : execute command with wexecvp
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE78_OS_Command_Injection__wchar_t_file_w32_execvp_82.h"

#include <process.h>
#define EXECVP _wexecvp

namespace CWE78_OS_Command_Injection__wchar_t_file_w32_execvp_82
{

void CWE78_OS_Command_Injection__wchar_t_file_w32_execvp_82_case0::action(wchar_t * data)
{
    {
        wchar_t *args[] = {COMMAND_INT_PATH, COMMAND_ARG1, COMMAND_ARG3, NULL};
        /* wexecvp - searches for the location of the command among
         * the directories specified by the PATH environment variable */
        /* NOTE: Execute command without validating input possibly leading to command injection */
        EXECVP(COMMAND_INT, args);
    }
}

}
#endif /* OMITCASE0 */
