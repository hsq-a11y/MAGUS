/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_83.h
Label Definition File: CWE427_Uncontrolled_Search_Path_Element.label.xml
Template File: sources-sink-83.tmpl.h
*/
/*
 * @description
 * CWE: 427 Uncontrolled Search Path Element
 * Case0Source: environment Read input from an environment variable
 * Case1Source: Use a hardcoded path
 * Sinks:
 *    Case0Sink : Set the environment variable
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#ifdef _WIN32
#define NEW_PATH L"%SystemRoot%\\system32"
#define PUTENV _wputenv
#else
#define NEW_PATH L"/bin"
#define PUTENV putenv
#endif

namespace CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_83
{

#ifndef OMITCASE0

class CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_83_case0
{
public:
    CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_83_case0(wchar_t * dataCopy);
    ~CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_83_case0();

private:
    wchar_t * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_83_case1V1
{
public:
    CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_83_case1V1(wchar_t * dataCopy);
    ~CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_83_case1V1();

private:
    wchar_t * data;
};

#endif /* OMITCASE1 */

}
