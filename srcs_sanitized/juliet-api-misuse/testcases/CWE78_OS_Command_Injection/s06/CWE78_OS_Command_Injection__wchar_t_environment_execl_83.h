/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__wchar_t_environment_execl_83.h
Label Definition File: CWE78_OS_Command_Injection.strings.label.xml
Template File: sources-sink-83.tmpl.h
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * Case0Source: environment Read input from an environment variable
 * Case1Source: Fixed string
 * Sinks: execl
 *    Case0Sink : execute command with wexecl
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define COMMAND_INT_PATH L"%WINDIR%\\system32\\cmd.exe"
#define COMMAND_INT L"cmd.exe"
#define COMMAND_ARG1 L"/c"
#define COMMAND_ARG2 L"dir "
#define COMMAND_ARG3 data
#else /* NOT _WIN32 */
#include <unistd.h>
#define COMMAND_INT_PATH L"/bin/sh"
#define COMMAND_INT L"sh"
#define COMMAND_ARG1 L"-c"
#define COMMAND_ARG2 L"ls "
#define COMMAND_ARG3 data
#endif

namespace CWE78_OS_Command_Injection__wchar_t_environment_execl_83
{

#ifndef OMITCASE0

class CWE78_OS_Command_Injection__wchar_t_environment_execl_83_case0
{
public:
    CWE78_OS_Command_Injection__wchar_t_environment_execl_83_case0(wchar_t * dataCopy);
    ~CWE78_OS_Command_Injection__wchar_t_environment_execl_83_case0();

private:
    wchar_t * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE78_OS_Command_Injection__wchar_t_environment_execl_83_case1V1
{
public:
    CWE78_OS_Command_Injection__wchar_t_environment_execl_83_case1V1(wchar_t * dataCopy);
    ~CWE78_OS_Command_Injection__wchar_t_environment_execl_83_case1V1();

private:
    wchar_t * data;
};

#endif /* OMITCASE1 */

}
