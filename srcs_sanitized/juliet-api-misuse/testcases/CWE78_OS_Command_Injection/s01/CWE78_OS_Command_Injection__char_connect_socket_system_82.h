/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_connect_socket_system_82.h
Label Definition File: CWE78_OS_Command_Injection.one_string.label.xml
Template File: sources-sink-82.tmpl.h
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * Case0Source: connect_socket Read data using a connect socket (client side)
 * Case1Source: Fixed string
 *    Case0Sink : Execute command in data using system()
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define FULL_COMMAND "dir "
#else
#include <unistd.h>
#define FULL_COMMAND "ls "
#endif

namespace CWE78_OS_Command_Injection__char_connect_socket_system_82
{

class CWE78_OS_Command_Injection__char_connect_socket_system_82_base
{
public:
    /* pure virtual function */
    virtual void action(char * data) = 0;
};

#ifndef OMITCASE0

class CWE78_OS_Command_Injection__char_connect_socket_system_82_case0 : public CWE78_OS_Command_Injection__char_connect_socket_system_82_base
{
public:
    void action(char * data);
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE78_OS_Command_Injection__char_connect_socket_system_82_case1V1 : public CWE78_OS_Command_Injection__char_connect_socket_system_82_base
{
public:
    void action(char * data);
};

#endif /* OMITCASE1 */

}
