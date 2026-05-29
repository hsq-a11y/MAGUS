/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_vprintf_82.h
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-82.tmpl.h
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: listen_socket Read data using a listen socket (server side)
 * Case1Source: Copy a fixed string into data
 * Sinks: vprintf
 *    Case1Sink: vwprintf with a format string
 *    Case0Sink : vwprintf without a format string
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_vprintf_82
{

class CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_vprintf_82_base
{
public:
    /* pure virtual function */
    virtual void action(wchar_t * data) = 0;
};

#ifndef OMITCASE0

class CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_vprintf_82_case0 : public CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_vprintf_82_base
{
public:
    void action(wchar_t * data);
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_vprintf_82_case1V1 : public CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_vprintf_82_base
{
public:
    void action(wchar_t * data);
};

class CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_vprintf_82_case1V2 : public CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_vprintf_82_base
{
public:
    void action(wchar_t * data);
};

#endif /* OMITCASE1 */

}
