/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE90_LDAP_Injection__w32_wchar_t_console_82.h
Label Definition File: CWE90_LDAP_Injection__w32.label.xml
Template File: sources-sink-82.tmpl.h
*/
/*
 * @description
 * CWE: 90 LDAP Injection
 * Case0Source: console Read input from the console
 * Case1Source: Use a fixed string
 *    Case0Sink : data concatenated into LDAP search, which could result in LDAP Injection
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"

namespace CWE90_LDAP_Injection__w32_wchar_t_console_82
{

class CWE90_LDAP_Injection__w32_wchar_t_console_82_base
{
public:
    /* pure virtual function */
    virtual void action(wchar_t * data) = 0;
};

#ifndef OMITCASE0

class CWE90_LDAP_Injection__w32_wchar_t_console_82_case0 : public CWE90_LDAP_Injection__w32_wchar_t_console_82_base
{
public:
    void action(wchar_t * data);
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE90_LDAP_Injection__w32_wchar_t_console_82_case1V1 : public CWE90_LDAP_Injection__w32_wchar_t_console_82_base
{
public:
    void action(wchar_t * data);
};

#endif /* OMITCASE1 */

}
