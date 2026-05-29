/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_connect_socket_system_84.h
Label Definition File: CWE78_OS_Command_Injection.one_string.label.xml
Template File: sources-sink-84.tmpl.h
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * Case0Source: connect_socket Read data using a connect socket (client side)
 * Case1Source: Fixed string
 * Sinks: system
 *    Case0Sink : Execute command in data using system()
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
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

namespace CWE78_OS_Command_Injection__char_connect_socket_system_84
{

#ifndef OMITCASE0

class CWE78_OS_Command_Injection__char_connect_socket_system_84_case0
{
public:
    CWE78_OS_Command_Injection__char_connect_socket_system_84_case0(char * dataCopy);
    ~CWE78_OS_Command_Injection__char_connect_socket_system_84_case0();

private:
    char * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE78_OS_Command_Injection__char_connect_socket_system_84_case1V1
{
public:
    CWE78_OS_Command_Injection__char_connect_socket_system_84_case1V1(char * dataCopy);
    ~CWE78_OS_Command_Injection__char_connect_socket_system_84_case1V1();

private:
    char * data;
};

#endif /* OMITCASE1 */

}
