/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_84_case0.cpp
Label Definition File: CWE427_Uncontrolled_Search_Path_Element.label.xml
Template File: sources-sink-84_case0.tmpl.cpp
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
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_84.h"

#define ENV_VARIABLE L"ADD"

#ifdef _WIN32
#define GETENV _wgetenv
#else
#define GETENV getenv
#endif

namespace CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_84
{
CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_84_case0::CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_84_case0(wchar_t * dataCopy)
{
    data = dataCopy;
    {
        /* Append input from an environment variable to data */
        size_t dataLen = wcslen(data);
        wchar_t * environment = GETENV(ENV_VARIABLE);
        /* If there is data in the environment variable */
        if (environment != NULL)
        {
            /* NOTE: Read data from an environment variable */
            wcsncat(data+dataLen, environment, 250-dataLen-1);
        }
    }
}

CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_84_case0::~CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_84_case0()
{
    /* NOTE: Set a new environment variable with a path that is possibly insecure */
    PUTENV(data);
}
}
#endif /* OMITCASE0 */
