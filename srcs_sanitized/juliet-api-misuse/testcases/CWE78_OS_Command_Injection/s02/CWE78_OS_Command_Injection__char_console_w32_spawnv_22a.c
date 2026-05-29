/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_console_w32_spawnv_22a.c
Label Definition File: CWE78_OS_Command_Injection.strings.label.xml
Template File: sources-sink-22a.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * Case0Source: console Read input from the console
 * Case1Source: Fixed string
 * Sink: w32_spawnv
 *    Case0Sink : execute command with spawnv
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

#include <process.h>

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the source function */
int CWE78_OS_Command_Injection__char_console_w32_spawnv_22_case0Global = 0;

char * CWE78_OS_Command_Injection__char_console_w32_spawnv_22_case0Source(char * data);

void CWE78_OS_Command_Injection__char_console_w32_spawnv_22_case0()
{
    char * data;
    char dataBuffer[100] = COMMAND_ARG2;
    data = dataBuffer;
    CWE78_OS_Command_Injection__char_console_w32_spawnv_22_case0Global = 1; /* true */
    data = CWE78_OS_Command_Injection__char_console_w32_spawnv_22_case0Source(data);
    {
        char *args[] = {COMMAND_INT_PATH, COMMAND_ARG1, COMMAND_ARG3, NULL};
        /* spawnv - specify the path where the command is located */
        /* NOTE: Execute command without validating input possibly leading to command injection */
        _spawnv(_P_WAIT, COMMAND_INT_PATH, args);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the source functions. */
int CWE78_OS_Command_Injection__char_console_w32_spawnv_22_case1V11Global = 0;
int CWE78_OS_Command_Injection__char_console_w32_spawnv_22_case1V12Global = 0;

/* case1V11() - use case1source and case0sink by setting the static variable to false instead of true */
char * CWE78_OS_Command_Injection__char_console_w32_spawnv_22_case1V11Source(char * data);

static void case1V11()
{
    char * data;
    char dataBuffer[100] = COMMAND_ARG2;
    data = dataBuffer;
    CWE78_OS_Command_Injection__char_console_w32_spawnv_22_case1V11Global = 0; /* false */
    data = CWE78_OS_Command_Injection__char_console_w32_spawnv_22_case1V11Source(data);
    {
        char *args[] = {COMMAND_INT_PATH, COMMAND_ARG1, COMMAND_ARG3, NULL};
        /* spawnv - specify the path where the command is located */
        /* NOTE: Execute command without validating input possibly leading to command injection */
        _spawnv(_P_WAIT, COMMAND_INT_PATH, args);
    }
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the if in the source function */
char * CWE78_OS_Command_Injection__char_console_w32_spawnv_22_case1V12Source(char * data);

static void case1V12()
{
    char * data;
    char dataBuffer[100] = COMMAND_ARG2;
    data = dataBuffer;
    CWE78_OS_Command_Injection__char_console_w32_spawnv_22_case1V12Global = 1; /* true */
    data = CWE78_OS_Command_Injection__char_console_w32_spawnv_22_case1V12Source(data);
    {
        char *args[] = {COMMAND_INT_PATH, COMMAND_ARG1, COMMAND_ARG3, NULL};
        /* spawnv - specify the path where the command is located */
        /* NOTE: Execute command without validating input possibly leading to command injection */
        _spawnv(_P_WAIT, COMMAND_INT_PATH, args);
    }
}

void CWE78_OS_Command_Injection__char_console_w32_spawnv_22_case1()
{
    case1V11();
    case1V12();
}

#endif /* OMITCASE1 */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITCASE1
    printLine("Calling case1()...");
    CWE78_OS_Command_Injection__char_console_w32_spawnv_22_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE78_OS_Command_Injection__char_console_w32_spawnv_22_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
