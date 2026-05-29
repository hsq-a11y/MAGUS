/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE427_Uncontrolled_Search_Path_Element__wchar_t_listen_socket_83_case1V1.cpp
Label Definition File: CWE427_Uncontrolled_Search_Path_Element.label.xml
Template File: sources-sink-83_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 427 Uncontrolled Search Path Element
 * Case0Source: listen_socket Read data using a listen socket (server side)
 * Case1Source: Use a hardcoded path
 * Sinks:
 *    Case0Sink : Set the environment variable
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE427_Uncontrolled_Search_Path_Element__wchar_t_listen_socket_83.h"

namespace CWE427_Uncontrolled_Search_Path_Element__wchar_t_listen_socket_83
{
CWE427_Uncontrolled_Search_Path_Element__wchar_t_listen_socket_83_case1V1::CWE427_Uncontrolled_Search_Path_Element__wchar_t_listen_socket_83_case1V1(wchar_t * dataCopy)
{
    data = dataCopy;
    /* ALT: Set the path as the "system" path */
    wcscat(data, NEW_PATH);
}

CWE427_Uncontrolled_Search_Path_Element__wchar_t_listen_socket_83_case1V1::~CWE427_Uncontrolled_Search_Path_Element__wchar_t_listen_socket_83_case1V1()
{
    /* NOTE: Set a new environment variable with a path that is possibly insecure */
    PUTENV(data);
}
}
#endif /* OMITCASE1 */
