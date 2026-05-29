/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__wchar_t_console_execlp_81_case0.cpp
Label Definition File: CWE78_OS_Command_Injection.strings.label.xml
Template File: sources-sink-81_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * Case0Source: console Read input from the console
 * Case1Source: Fixed string
 * Sinks: execlp
 *    Case0Sink : execute command with wexeclp
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE78_OS_Command_Injection__wchar_t_console_execlp_81.h"

#ifdef _WIN32
#include <process.h>
#define EXECLP _wexeclp
#else /* NOT _WIN32 */
#define EXECLP execlp
#endif

namespace CWE78_OS_Command_Injection__wchar_t_console_execlp_81
{

void CWE78_OS_Command_Injection__wchar_t_console_execlp_81_case0::action(wchar_t * data) const
{
    /* wexeclp - searches for the location of the command among
     * the directories specified by the PATH environment variable */
    /* NOTE: Execute command without validating input possibly leading to command injection */
    EXECLP(COMMAND_INT, COMMAND_INT, COMMAND_ARG1, COMMAND_ARG3, NULL);
}

}
#endif /* OMITCASE0 */
