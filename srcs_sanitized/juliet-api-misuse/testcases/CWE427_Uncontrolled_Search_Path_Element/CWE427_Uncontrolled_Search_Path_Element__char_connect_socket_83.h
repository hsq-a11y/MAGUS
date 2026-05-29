/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE427_Uncontrolled_Search_Path_Element__char_connect_socket_83.h
Label Definition File: CWE427_Uncontrolled_Search_Path_Element.label.xml
Template File: sources-sink-83.tmpl.h
*/
/*
 * @description
 * CWE: 427 Uncontrolled Search Path Element
 * Case0Source: connect_socket Read data using a connect socket (client side)
 * Case1Source: Use a hardcoded path
 * Sinks:
 *    Case0Sink : Set the environment variable
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#ifdef _WIN32
#define NEW_PATH "%SystemRoot%\\system32"
#define PUTENV _putenv
#else
#define NEW_PATH "/bin"
#define PUTENV putenv
#endif

namespace CWE427_Uncontrolled_Search_Path_Element__char_connect_socket_83
{

#ifndef OMITCASE0

class CWE427_Uncontrolled_Search_Path_Element__char_connect_socket_83_case0
{
public:
    CWE427_Uncontrolled_Search_Path_Element__char_connect_socket_83_case0(char * dataCopy);
    ~CWE427_Uncontrolled_Search_Path_Element__char_connect_socket_83_case0();

private:
    char * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE427_Uncontrolled_Search_Path_Element__char_connect_socket_83_case1V1
{
public:
    CWE427_Uncontrolled_Search_Path_Element__char_connect_socket_83_case1V1(char * dataCopy);
    ~CWE427_Uncontrolled_Search_Path_Element__char_connect_socket_83_case1V1();

private:
    char * data;
};

#endif /* OMITCASE1 */

}
