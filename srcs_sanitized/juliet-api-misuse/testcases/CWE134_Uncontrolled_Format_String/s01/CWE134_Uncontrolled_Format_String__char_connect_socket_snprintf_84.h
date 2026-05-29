/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_connect_socket_snprintf_84.h
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-84.tmpl.h
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: connect_socket Read data using a connect socket (client side)
 * Case1Source: Copy a fixed string into data
 * Sinks: snprintf
 *    Case1Sink: snprintf with "%s" as the third argument and data as the fourth
 *    Case0Sink : snprintf with data as the third argument
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE134_Uncontrolled_Format_String__char_connect_socket_snprintf_84
{

#ifndef OMITCASE0

class CWE134_Uncontrolled_Format_String__char_connect_socket_snprintf_84_case0
{
public:
    CWE134_Uncontrolled_Format_String__char_connect_socket_snprintf_84_case0(char * dataCopy);
    ~CWE134_Uncontrolled_Format_String__char_connect_socket_snprintf_84_case0();

private:
    char * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE134_Uncontrolled_Format_String__char_connect_socket_snprintf_84_case1V1
{
public:
    CWE134_Uncontrolled_Format_String__char_connect_socket_snprintf_84_case1V1(char * dataCopy);
    ~CWE134_Uncontrolled_Format_String__char_connect_socket_snprintf_84_case1V1();

private:
    char * data;
};

class CWE134_Uncontrolled_Format_String__char_connect_socket_snprintf_84_case1V2
{
public:
    CWE134_Uncontrolled_Format_String__char_connect_socket_snprintf_84_case1V2(char * dataCopy);
    ~CWE134_Uncontrolled_Format_String__char_connect_socket_snprintf_84_case1V2();

private:
    char * data;
};

#endif /* OMITCASE1 */

}
