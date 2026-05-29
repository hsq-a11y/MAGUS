/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__wchar_t_connect_socket_popen_81.h
Label Definition File: CWE78_OS_Command_Injection.one_string.label.xml
Template File: sources-sink-81.tmpl.h
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * Case0Source: connect_socket Read data using a connect socket (client side)
 * Case1Source: Fixed string
 * Sinks: popen
 *    Case0Sink : Execute command in data using popen()
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
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

namespace CWE78_OS_Command_Injection__wchar_t_connect_socket_popen_81
{

class CWE78_OS_Command_Injection__wchar_t_connect_socket_popen_81_base
{
public:
    /* pure virtual function */
    virtual void action(wchar_t * data) const = 0;
};

#ifndef OMITCASE0

class CWE78_OS_Command_Injection__wchar_t_connect_socket_popen_81_case0 : public CWE78_OS_Command_Injection__wchar_t_connect_socket_popen_81_base
{
public:
    void action(wchar_t * data) const;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE78_OS_Command_Injection__wchar_t_connect_socket_popen_81_case1V1 : public CWE78_OS_Command_Injection__wchar_t_connect_socket_popen_81_base
{
public:
    void action(wchar_t * data) const;
};

#endif /* OMITCASE1 */

}
