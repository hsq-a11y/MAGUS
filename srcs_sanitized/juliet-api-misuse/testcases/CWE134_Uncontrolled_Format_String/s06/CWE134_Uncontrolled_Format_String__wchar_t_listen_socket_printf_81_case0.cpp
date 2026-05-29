/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_printf_81_case0.cpp
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-81_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: listen_socket Read data using a listen socket (server side)
 * Case1Source: Copy a fixed string into data
 * Sinks: printf
 *    Case1Sink: wprintf with "%s" as the first argument and data as the second
 *    Case0Sink : wprintf with only data as an argument
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_printf_81.h"

namespace CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_printf_81
{

void CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_printf_81_case0::action(wchar_t * data) const
{
    /* NOTE: Do not specify the format allowing a possible format string vulnerability */
    wprintf(data);
}

}
#endif /* OMITCASE0 */
