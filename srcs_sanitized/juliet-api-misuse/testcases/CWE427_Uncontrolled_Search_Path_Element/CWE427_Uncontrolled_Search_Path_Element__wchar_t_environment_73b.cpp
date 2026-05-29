/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_73b.cpp
Label Definition File: CWE427_Uncontrolled_Search_Path_Element.label.xml
Template File: sources-sink-73b.tmpl.cpp
*/
/*
 * @description
 * CWE: 427 Uncontrolled Search Path Element
 * Case0Source: environment Read input from an environment variable
 * Case1Source: Use a hardcoded path
 * Sinks:
 *    Case0Sink : Set the environment variable
 * Flow Variant: 73 Data flow: data passed in a list from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <list>

#include <wchar.h>
#ifdef _WIN32
#define NEW_PATH L"%SystemRoot%\\system32"
#define PUTENV _wputenv
#else
#define NEW_PATH L"/bin"
#define PUTENV putenv
#endif

using namespace std;

namespace CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_73
{

#ifndef OMITCASE0

void case0Sink(list<wchar_t *> dataList)
{
    /* copy data out of dataList */
    wchar_t * data = dataList.back();
    /* NOTE: Set a new environment variable with a path that is possibly insecure */
    PUTENV(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink(list<wchar_t *> dataList)
{
    wchar_t * data = dataList.back();
    /* NOTE: Set a new environment variable with a path that is possibly insecure */
    PUTENV(data);
}

#endif /* OMITCASE1 */

} /* close namespace */
