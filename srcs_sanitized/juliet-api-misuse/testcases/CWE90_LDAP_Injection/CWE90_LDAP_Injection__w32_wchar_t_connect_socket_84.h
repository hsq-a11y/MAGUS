/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE90_LDAP_Injection__w32_wchar_t_connect_socket_84.h
Label Definition File: CWE90_LDAP_Injection__w32.label.xml
Template File: sources-sink-84.tmpl.h
*/
/*
 * @description
 * CWE: 90 LDAP Injection
 * Case0Source: connect_socket Read data using a connect socket (client side)
 * Case1Source: Use a fixed string
 * Sinks:
 *    Case0Sink : data concatenated into LDAP search, which could result in LDAP Injection
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"

namespace CWE90_LDAP_Injection__w32_wchar_t_connect_socket_84
{

#ifndef OMITCASE0

class CWE90_LDAP_Injection__w32_wchar_t_connect_socket_84_case0
{
public:
    CWE90_LDAP_Injection__w32_wchar_t_connect_socket_84_case0(wchar_t * dataCopy);
    ~CWE90_LDAP_Injection__w32_wchar_t_connect_socket_84_case0();

private:
    wchar_t * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE90_LDAP_Injection__w32_wchar_t_connect_socket_84_case1V1
{
public:
    CWE90_LDAP_Injection__w32_wchar_t_connect_socket_84_case1V1(wchar_t * dataCopy);
    ~CWE90_LDAP_Injection__w32_wchar_t_connect_socket_84_case1V1();

private:
    wchar_t * data;
};

#endif /* OMITCASE1 */

}
