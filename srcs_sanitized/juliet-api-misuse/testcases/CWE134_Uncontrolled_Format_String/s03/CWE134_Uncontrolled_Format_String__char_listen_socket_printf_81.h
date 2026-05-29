/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_listen_socket_printf_81.h
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-81.tmpl.h
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: listen_socket Read data using a listen socket (server side)
 * Case1Source: Copy a fixed string into data
 * Sinks: printf
 *    Case1Sink: printf with "%s" as the first argument and data as the second
 *    Case0Sink : printf with only data as an argument
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE134_Uncontrolled_Format_String__char_listen_socket_printf_81
{

class CWE134_Uncontrolled_Format_String__char_listen_socket_printf_81_base
{
public:
    /* pure virtual function */
    virtual void action(char * data) const = 0;
};

#ifndef OMITCASE0

class CWE134_Uncontrolled_Format_String__char_listen_socket_printf_81_case0 : public CWE134_Uncontrolled_Format_String__char_listen_socket_printf_81_base
{
public:
    void action(char * data) const;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE134_Uncontrolled_Format_String__char_listen_socket_printf_81_case1V1 : public CWE134_Uncontrolled_Format_String__char_listen_socket_printf_81_base
{
public:
    void action(char * data) const;
};

class CWE134_Uncontrolled_Format_String__char_listen_socket_printf_81_case1V2 : public CWE134_Uncontrolled_Format_String__char_listen_socket_printf_81_base
{
public:
    void action(char * data) const;
};

#endif /* OMITCASE1 */

}
