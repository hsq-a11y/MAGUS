/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_environment_w32_execvp_22b.c
Label Definition File: CWE78_OS_Command_Injection.strings.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * Case0Source: environment Read input from an environment variable
 * Case1Source: Fixed string
 * Sink: w32_execvp
 *    Case0Sink : execute command with execvp
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define COMMAND_INT_PATH "%WINDIR%\\system32\\cmd.exe"
#define COMMAND_INT "cmd.exe"
#define COMMAND_ARG1 "/c"
#define COMMAND_ARG2 "dir "
#define COMMAND_ARG3 data
#else /* NOT _WIN32 */
#include <unistd.h>
#define COMMAND_INT_PATH "/bin/sh"
#define COMMAND_INT "sh"
#define COMMAND_ARG1 "-c"
#define COMMAND_ARG2 "ls "
#define COMMAND_ARG3 data
#endif

#define ENV_VARIABLE "ADD"

#ifdef _WIN32
#define GETENV getenv
#else
#define GETENV getenv
#endif

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the source function */
extern int CWE78_OS_Command_Injection__char_environment_w32_execvp_22_case0Global;

char * CWE78_OS_Command_Injection__char_environment_w32_execvp_22_case0Source(char * data)
{
    if(CWE78_OS_Command_Injection__char_environment_w32_execvp_22_case0Global)
    {
        {
            /* Append input from an environment variable to data */
            size_t dataLen = strlen(data);
            char * environment = GETENV(ENV_VARIABLE);
            /* If there is data in the environment variable */
            if (environment != NULL)
            {
                /* NOTE: Read data from an environment variable */
                strncat(data+dataLen, environment, 100-dataLen-1);
            }
        }
    }
    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the source functions. */
extern int CWE78_OS_Command_Injection__char_environment_w32_execvp_22_case1V11Global;
extern int CWE78_OS_Command_Injection__char_environment_w32_execvp_22_case1V12Global;

/* case1V11() - use case1source and case0sink by setting the static variable to false instead of true */
char * CWE78_OS_Command_Injection__char_environment_w32_execvp_22_case1V11Source(char * data)
{
    if(CWE78_OS_Command_Injection__char_environment_w32_execvp_22_case1V11Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: Append a fixed string to data (not user / external input) */
        strcat(data, "*.*");
    }
    return data;
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the if in the source function */
char * CWE78_OS_Command_Injection__char_environment_w32_execvp_22_case1V12Source(char * data)
{
    if(CWE78_OS_Command_Injection__char_environment_w32_execvp_22_case1V12Global)
    {
        /* ALT: Append a fixed string to data (not user / external input) */
        strcat(data, "*.*");
    }
    return data;
}

#endif /* OMITCASE1 */
