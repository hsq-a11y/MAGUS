/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_console_printf_82.h
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-82.tmpl.h
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: console Read input from the console
 * Case1Source: Copy a fixed string into data
 * Sinks: printf
 *    Case1Sink: wprintf with "%s" as the first argument and data as the second
 *    Case0Sink : wprintf with only data as an argument
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE134_Uncontrolled_Format_String__wchar_t_console_printf_82
{

class CWE134_Uncontrolled_Format_String__wchar_t_console_printf_82_base
{
public:
    /* pure virtual function */
    virtual void action(wchar_t * data) = 0;
};

#ifndef OMITCASE0

class CWE134_Uncontrolled_Format_String__wchar_t_console_printf_82_case0 : public CWE134_Uncontrolled_Format_String__wchar_t_console_printf_82_base
{
public:
    void action(wchar_t * data);
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE134_Uncontrolled_Format_String__wchar_t_console_printf_82_case1V1 : public CWE134_Uncontrolled_Format_String__wchar_t_console_printf_82_base
{
public:
    void action(wchar_t * data);
};

class CWE134_Uncontrolled_Format_String__wchar_t_console_printf_82_case1V2 : public CWE134_Uncontrolled_Format_String__wchar_t_console_printf_82_base
{
public:
    void action(wchar_t * data);
};

#endif /* OMITCASE1 */

}
