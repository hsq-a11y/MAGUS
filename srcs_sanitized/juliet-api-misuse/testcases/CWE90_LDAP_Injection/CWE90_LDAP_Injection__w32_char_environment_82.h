/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE90_LDAP_Injection__w32_char_environment_82.h
Label Definition File: CWE90_LDAP_Injection__w32.label.xml
Template File: sources-sink-82.tmpl.h
*/
/*
 * @description
 * CWE: 90 LDAP Injection
 * Case0Source: environment Read input from an environment variable
 * Case1Source: Use a fixed string
 *    Case0Sink : data concatenated into LDAP search, which could result in LDAP Injection
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"

namespace CWE90_LDAP_Injection__w32_char_environment_82
{

class CWE90_LDAP_Injection__w32_char_environment_82_base
{
public:
    /* pure virtual function */
    virtual void action(char * data) = 0;
};

#ifndef OMITCASE0

class CWE90_LDAP_Injection__w32_char_environment_82_case0 : public CWE90_LDAP_Injection__w32_char_environment_82_base
{
public:
    void action(char * data);
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE90_LDAP_Injection__w32_char_environment_82_case1V1 : public CWE90_LDAP_Injection__w32_char_environment_82_base
{
public:
    void action(char * data);
};

#endif /* OMITCASE1 */

}
