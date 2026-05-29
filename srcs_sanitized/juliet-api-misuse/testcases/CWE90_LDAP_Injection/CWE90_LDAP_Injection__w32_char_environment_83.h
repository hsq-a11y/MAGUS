/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE90_LDAP_Injection__w32_char_environment_83.h
Label Definition File: CWE90_LDAP_Injection__w32.label.xml
Template File: sources-sink-83.tmpl.h
*/
/*
 * @description
 * CWE: 90 LDAP Injection
 * Case0Source: environment Read input from an environment variable
 * Case1Source: Use a fixed string
 * Sinks:
 *    Case0Sink : data concatenated into LDAP search, which could result in LDAP Injection
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"

namespace CWE90_LDAP_Injection__w32_char_environment_83
{

#ifndef OMITCASE0

class CWE90_LDAP_Injection__w32_char_environment_83_case0
{
public:
    CWE90_LDAP_Injection__w32_char_environment_83_case0(char * dataCopy);
    ~CWE90_LDAP_Injection__w32_char_environment_83_case0();

private:
    char * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE90_LDAP_Injection__w32_char_environment_83_case1V1
{
public:
    CWE90_LDAP_Injection__w32_char_environment_83_case1V1(char * dataCopy);
    ~CWE90_LDAP_Injection__w32_char_environment_83_case1V1();

private:
    char * data;
};

#endif /* OMITCASE1 */

}
