/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__wchar_t_environment_popen_82_case0.cpp
Label Definition File: CWE78_OS_Command_Injection.one_string.label.xml
Template File: sources-sink-82_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * Case0Source: environment Read input from an environment variable
 * Case1Source: Fixed string
 * Sinks: popen
 *    Case0Sink : Execute command in data using popen()
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE78_OS_Command_Injection__wchar_t_environment_popen_82.h"

/* define POPEN as _popen on Windows and popen otherwise */
#ifdef _WIN32
#define POPEN _wpopen
#define PCLOSE _pclose
#else /* NOT _WIN32 */
#define POPEN popen
#define PCLOSE pclose
#endif

namespace CWE78_OS_Command_Injection__wchar_t_environment_popen_82
{

void CWE78_OS_Command_Injection__wchar_t_environment_popen_82_case0::action(wchar_t * data)
{
    {
        FILE *pipe;
        /* NOTE: Execute command in data possibly leading to command injection */
        pipe = POPEN(data, L"w");
        if (pipe != NULL)
        {
            PCLOSE(pipe);
        }
    }
}

}
#endif /* OMITCASE0 */
