/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_environment_snprintf_82.h
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-82.tmpl.h
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: environment Read input from an environment variable
 * Case1Source: Copy a fixed string into data
 * Sinks: snprintf
 *    Case1Sink: snwprintf with "%s" as the third argument and data as the fourth
 *    Case0Sink : snwprintf with data as the third argument
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE134_Uncontrolled_Format_String__wchar_t_environment_snprintf_82
{

class CWE134_Uncontrolled_Format_String__wchar_t_environment_snprintf_82_base
{
public:
    /* pure virtual function */
    virtual void action(wchar_t * data) = 0;
};

#ifndef OMITCASE0

class CWE134_Uncontrolled_Format_String__wchar_t_environment_snprintf_82_case0 : public CWE134_Uncontrolled_Format_String__wchar_t_environment_snprintf_82_base
{
public:
    void action(wchar_t * data);
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE134_Uncontrolled_Format_String__wchar_t_environment_snprintf_82_case1V1 : public CWE134_Uncontrolled_Format_String__wchar_t_environment_snprintf_82_base
{
public:
    void action(wchar_t * data);
};

class CWE134_Uncontrolled_Format_String__wchar_t_environment_snprintf_82_case1V2 : public CWE134_Uncontrolled_Format_String__wchar_t_environment_snprintf_82_base
{
public:
    void action(wchar_t * data);
};

#endif /* OMITCASE1 */

}
