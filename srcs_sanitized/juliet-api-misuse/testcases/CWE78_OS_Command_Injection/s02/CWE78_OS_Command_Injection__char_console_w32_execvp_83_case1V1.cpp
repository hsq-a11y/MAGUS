/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_console_w32_execvp_83_case1V1.cpp
Label Definition File: CWE78_OS_Command_Injection.strings.label.xml
Template File: sources-sink-83_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * Case0Source: console Read input from the console
 * Case1Source: Fixed string
 * Sinks: w32_execvp
 *    Case0Sink : execute command with execvp
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE78_OS_Command_Injection__char_console_w32_execvp_83.h"

#include <process.h>
#define EXECVP _execvp

namespace CWE78_OS_Command_Injection__char_console_w32_execvp_83
{
CWE78_OS_Command_Injection__char_console_w32_execvp_83_case1V1::CWE78_OS_Command_Injection__char_console_w32_execvp_83_case1V1(char * dataCopy)
{
    data = dataCopy;
    /* ALT: Append a fixed string to data (not user / external input) */
    strcat(data, "*.*");
}

CWE78_OS_Command_Injection__char_console_w32_execvp_83_case1V1::~CWE78_OS_Command_Injection__char_console_w32_execvp_83_case1V1()
{
    {
        char *args[] = {COMMAND_INT_PATH, COMMAND_ARG1, COMMAND_ARG3, NULL};
        /* execvp - searches for the location of the command among
         * the directories specified by the PATH environment variable */
        /* NOTE: Execute command without validating input possibly leading to command injection */
        EXECVP(COMMAND_INT, args);
    }
}
}
#endif /* OMITCASE1 */
