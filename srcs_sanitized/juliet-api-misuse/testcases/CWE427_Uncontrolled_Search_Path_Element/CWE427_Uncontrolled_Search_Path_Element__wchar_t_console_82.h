/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE427_Uncontrolled_Search_Path_Element__wchar_t_console_82.h
Label Definition File: CWE427_Uncontrolled_Search_Path_Element.label.xml
Template File: sources-sink-82.tmpl.h
*/
/*
 * @description
 * CWE: 427 Uncontrolled Search Path Element
 * Case0Source: console Read input from the console
 * Case1Source: Use a hardcoded path
 *    Case0Sink : Set the environment variable
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
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

namespace CWE427_Uncontrolled_Search_Path_Element__wchar_t_console_82
{

class CWE427_Uncontrolled_Search_Path_Element__wchar_t_console_82_base
{
public:
    /* pure virtual function */
    virtual void action(wchar_t * data) = 0;
};

#ifndef OMITCASE0

class CWE427_Uncontrolled_Search_Path_Element__wchar_t_console_82_case0 : public CWE427_Uncontrolled_Search_Path_Element__wchar_t_console_82_base
{
public:
    void action(wchar_t * data);
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE427_Uncontrolled_Search_Path_Element__wchar_t_console_82_case1V1 : public CWE427_Uncontrolled_Search_Path_Element__wchar_t_console_82_base
{
public:
    void action(wchar_t * data);
};

#endif /* OMITCASE1 */

}
