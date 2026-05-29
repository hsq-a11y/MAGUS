/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_connect_socket_w32_vsnprintf_83.h
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-83.tmpl.h
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: connect_socket Read data using a connect socket (client side)
 * Case1Source: Copy a fixed string into data
 * Sinks: w32_vsnprintf
 *    Case1Sink: _vsnwprintf with a format string
 *    Case0Sink : _vsnwprintf without a format string
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE134_Uncontrolled_Format_String__wchar_t_connect_socket_w32_vsnprintf_83
{

#ifndef OMITCASE0

class CWE134_Uncontrolled_Format_String__wchar_t_connect_socket_w32_vsnprintf_83_case0
{
public:
    CWE134_Uncontrolled_Format_String__wchar_t_connect_socket_w32_vsnprintf_83_case0(wchar_t * dataCopy);
    ~CWE134_Uncontrolled_Format_String__wchar_t_connect_socket_w32_vsnprintf_83_case0();

private:
    wchar_t * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE134_Uncontrolled_Format_String__wchar_t_connect_socket_w32_vsnprintf_83_case1V1
{
public:
    CWE134_Uncontrolled_Format_String__wchar_t_connect_socket_w32_vsnprintf_83_case1V1(wchar_t * dataCopy);
    ~CWE134_Uncontrolled_Format_String__wchar_t_connect_socket_w32_vsnprintf_83_case1V1();

private:
    wchar_t * data;
};

class CWE134_Uncontrolled_Format_String__wchar_t_connect_socket_w32_vsnprintf_83_case1V2
{
public:
    CWE134_Uncontrolled_Format_String__wchar_t_connect_socket_w32_vsnprintf_83_case1V2(wchar_t * dataCopy);
    ~CWE134_Uncontrolled_Format_String__wchar_t_connect_socket_w32_vsnprintf_83_case1V2();

private:
    wchar_t * data;
};

#endif /* OMITCASE1 */

}
