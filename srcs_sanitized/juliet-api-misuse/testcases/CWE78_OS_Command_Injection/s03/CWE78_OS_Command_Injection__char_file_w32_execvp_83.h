/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_file_w32_execvp_83.h
Label Definition File: CWE78_OS_Command_Injection.strings.label.xml
Template File: sources-sink-83.tmpl.h
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * Case0Source: file Read input from a file
 * Case1Source: Fixed string
 * Sinks: w32_execvp
 *    Case0Sink : execute command with execvp
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
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

namespace CWE78_OS_Command_Injection__char_file_w32_execvp_83
{

#ifndef OMITCASE0

class CWE78_OS_Command_Injection__char_file_w32_execvp_83_case0
{
public:
    CWE78_OS_Command_Injection__char_file_w32_execvp_83_case0(char * dataCopy);
    ~CWE78_OS_Command_Injection__char_file_w32_execvp_83_case0();

private:
    char * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE78_OS_Command_Injection__char_file_w32_execvp_83_case1V1
{
public:
    CWE78_OS_Command_Injection__char_file_w32_execvp_83_case1V1(char * dataCopy);
    ~CWE78_OS_Command_Injection__char_file_w32_execvp_83_case1V1();

private:
    char * data;
};

#endif /* OMITCASE1 */

}
