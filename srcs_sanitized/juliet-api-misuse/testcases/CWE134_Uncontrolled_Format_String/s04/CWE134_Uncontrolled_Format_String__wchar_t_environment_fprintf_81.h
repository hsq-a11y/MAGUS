/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_81.h
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-81.tmpl.h
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: environment Read input from an environment variable
 * Case1Source: Copy a fixed string into data
 * Sinks: fprintf
 *    Case1Sink: fwprintf with "%s" as the second argument and data as the third
 *    Case0Sink : fwprintf with data as the second argument
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_81
{

class CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_81_base
{
public:
    /* pure virtual function */
    virtual void action(wchar_t * data) const = 0;
};

#ifndef OMITCASE0

class CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_81_case0 : public CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_81_base
{
public:
    void action(wchar_t * data) const;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_81_case1V1 : public CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_81_base
{
public:
    void action(wchar_t * data) const;
};

class CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_81_case1V2 : public CWE134_Uncontrolled_Format_String__wchar_t_environment_fprintf_81_base
{
public:
    void action(wchar_t * data) const;
};

#endif /* OMITCASE1 */

}
