/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_82_case0.cpp
Label Definition File: CWE427_Uncontrolled_Search_Path_Element.label.xml
Template File: sources-sink-82_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 427 Uncontrolled Search Path Element
 * Case0Source: environment Read input from an environment variable
 * Case1Source: Use a hardcoded path
 * Sinks:
 *    Case0Sink : Set the environment variable
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_82.h"

namespace CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_82
{

void CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_82_case0::action(wchar_t * data)
{
    /* NOTE: Set a new environment variable with a path that is possibly insecure */
    PUTENV(data);
}

}
#endif /* OMITCASE0 */
