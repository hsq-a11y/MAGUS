/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__wchar_t_listen_socket_popen_81_case0.cpp
Label Definition File: CWE78_OS_Command_Injection.one_string.label.xml
Template File: sources-sink-81_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * Case0Source: listen_socket Read data using a listen socket (server side)
 * Case1Source: Fixed string
 * Sinks: popen
 *    Case0Sink : Execute command in data using popen()
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE78_OS_Command_Injection__wchar_t_listen_socket_popen_81.h"

/* define POPEN as _popen on Windows and popen otherwise */
#ifdef _WIN32
#define POPEN _wpopen
#define PCLOSE _pclose
#else /* NOT _WIN32 */
#define POPEN popen
#define PCLOSE pclose
#endif

namespace CWE78_OS_Command_Injection__wchar_t_listen_socket_popen_81
{

void CWE78_OS_Command_Injection__wchar_t_listen_socket_popen_81_case0::action(wchar_t * data) const
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
