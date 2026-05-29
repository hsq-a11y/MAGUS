/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__wchar_t_environment_system_83.h
Label Definition File: CWE78_OS_Command_Injection.one_string.label.xml
Template File: sources-sink-83.tmpl.h
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * Case0Source: environment Read input from an environment variable
 * Case1Source: Fixed string
 * Sinks: system
 *    Case0Sink : Execute command in data using system()
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define FULL_COMMAND L"dir "
#else
#include <unistd.h>
#define FULL_COMMAND L"ls "
#endif

namespace CWE78_OS_Command_Injection__wchar_t_environment_system_83
{

#ifndef OMITCASE0

class CWE78_OS_Command_Injection__wchar_t_environment_system_83_case0
{
public:
    CWE78_OS_Command_Injection__wchar_t_environment_system_83_case0(wchar_t * dataCopy);
    ~CWE78_OS_Command_Injection__wchar_t_environment_system_83_case0();

private:
    wchar_t * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE78_OS_Command_Injection__wchar_t_environment_system_83_case1V1
{
public:
    CWE78_OS_Command_Injection__wchar_t_environment_system_83_case1V1(wchar_t * dataCopy);
    ~CWE78_OS_Command_Injection__wchar_t_environment_system_83_case1V1();

private:
    wchar_t * data;
};

#endif /* OMITCASE1 */

}
