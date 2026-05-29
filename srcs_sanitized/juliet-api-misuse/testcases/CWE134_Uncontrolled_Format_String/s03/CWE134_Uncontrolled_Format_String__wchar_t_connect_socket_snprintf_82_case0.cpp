/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_connect_socket_snprintf_82_case0.cpp
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-82_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: connect_socket Read data using a connect socket (client side)
 * Case1Source: Copy a fixed string into data
 * Sinks: snprintf
 *    Case1Sink: snwprintf with "%s" as the third argument and data as the fourth
 *    Case0Sink : snwprintf with data as the third argument
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE134_Uncontrolled_Format_String__wchar_t_connect_socket_snprintf_82.h"

#ifdef _WIN32
#define SNPRINTF _snwprintf
#else
#define SNPRINTF snprintf
#endif

namespace CWE134_Uncontrolled_Format_String__wchar_t_connect_socket_snprintf_82
{

void CWE134_Uncontrolled_Format_String__wchar_t_connect_socket_snprintf_82_case0::action(wchar_t * data)
{
    {
        wchar_t dest[100] = L"";
        /* NOTE: Do not specify the format allowing a possible format string vulnerability */
        SNPRINTF(dest, 100-1, data);
        printWLine(dest);
    }
}

}
#endif /* OMITCASE0 */
