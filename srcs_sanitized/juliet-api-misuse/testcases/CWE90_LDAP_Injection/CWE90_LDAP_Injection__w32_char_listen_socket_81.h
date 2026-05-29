/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE90_LDAP_Injection__w32_char_listen_socket_81.h
Label Definition File: CWE90_LDAP_Injection__w32.label.xml
Template File: sources-sink-81.tmpl.h
*/
/*
 * @description
 * CWE: 90 LDAP Injection
 * Case0Source: listen_socket Read data using a listen socket (server side)
 * Case1Source: Use a fixed string
 * Sinks:
 *    Case0Sink : data concatenated into LDAP search, which could result in LDAP Injection
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"

namespace CWE90_LDAP_Injection__w32_char_listen_socket_81
{

class CWE90_LDAP_Injection__w32_char_listen_socket_81_base
{
public:
    /* pure virtual function */
    virtual void action(char * data) const = 0;
};

#ifndef OMITCASE0

class CWE90_LDAP_Injection__w32_char_listen_socket_81_case0 : public CWE90_LDAP_Injection__w32_char_listen_socket_81_base
{
public:
    void action(char * data) const;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE90_LDAP_Injection__w32_char_listen_socket_81_case1V1 : public CWE90_LDAP_Injection__w32_char_listen_socket_81_base
{
public:
    void action(char * data) const;
};

#endif /* OMITCASE1 */

}
