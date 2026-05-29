/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_84_case1V1.cpp
Label Definition File: CWE427_Uncontrolled_Search_Path_Element.label.xml
Template File: sources-sink-84_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 427 Uncontrolled Search Path Element
 * Case0Source: environment Read input from an environment variable
 * Case1Source: Use a hardcoded path
 * Sinks:
 *    Case0Sink : Set the environment variable
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_84.h"

namespace CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_84
{
CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_84_case1V1::CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_84_case1V1(wchar_t * dataCopy)
{
    data = dataCopy;
    /* ALT: Set the path as the "system" path */
    wcscat(data, NEW_PATH);
}

CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_84_case1V1::~CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_84_case1V1()
{
    /* NOTE: Set a new environment variable with a path that is possibly insecure */
    PUTENV(data);
}
}
#endif /* OMITCASE1 */
