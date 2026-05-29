/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_environment_printf_83.h
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-83.tmpl.h
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: environment Read input from an environment variable
 * Case1Source: Copy a fixed string into data
 * Sinks: printf
 *    Case1Sink: wprintf with "%s" as the first argument and data as the second
 *    Case0Sink : wprintf with only data as an argument
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE134_Uncontrolled_Format_String__wchar_t_environment_printf_83
{

#ifndef OMITCASE0

class CWE134_Uncontrolled_Format_String__wchar_t_environment_printf_83_case0
{
public:
    CWE134_Uncontrolled_Format_String__wchar_t_environment_printf_83_case0(wchar_t * dataCopy);
    ~CWE134_Uncontrolled_Format_String__wchar_t_environment_printf_83_case0();

private:
    wchar_t * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE134_Uncontrolled_Format_String__wchar_t_environment_printf_83_case1V1
{
public:
    CWE134_Uncontrolled_Format_String__wchar_t_environment_printf_83_case1V1(wchar_t * dataCopy);
    ~CWE134_Uncontrolled_Format_String__wchar_t_environment_printf_83_case1V1();

private:
    wchar_t * data;
};

class CWE134_Uncontrolled_Format_String__wchar_t_environment_printf_83_case1V2
{
public:
    CWE134_Uncontrolled_Format_String__wchar_t_environment_printf_83_case1V2(wchar_t * dataCopy);
    ~CWE134_Uncontrolled_Format_String__wchar_t_environment_printf_83_case1V2();

private:
    wchar_t * data;
};

#endif /* OMITCASE1 */

}
