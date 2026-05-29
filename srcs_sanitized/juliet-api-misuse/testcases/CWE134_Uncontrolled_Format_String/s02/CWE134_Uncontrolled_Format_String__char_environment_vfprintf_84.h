/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_environment_vfprintf_84.h
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-84.tmpl.h
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: environment Read input from an environment variable
 * Case1Source: Copy a fixed string into data
 * Sinks: vfprintf
 *    Case1Sink: vfprintf with a format string
 *    Case0Sink : vfprintf without a format string
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE134_Uncontrolled_Format_String__char_environment_vfprintf_84
{

#ifndef OMITCASE0

class CWE134_Uncontrolled_Format_String__char_environment_vfprintf_84_case0
{
public:
    CWE134_Uncontrolled_Format_String__char_environment_vfprintf_84_case0(char * dataCopy);
    ~CWE134_Uncontrolled_Format_String__char_environment_vfprintf_84_case0();

private:
    char * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE134_Uncontrolled_Format_String__char_environment_vfprintf_84_case1V1
{
public:
    CWE134_Uncontrolled_Format_String__char_environment_vfprintf_84_case1V1(char * dataCopy);
    ~CWE134_Uncontrolled_Format_String__char_environment_vfprintf_84_case1V1();

private:
    char * data;
};

class CWE134_Uncontrolled_Format_String__char_environment_vfprintf_84_case1V2
{
public:
    CWE134_Uncontrolled_Format_String__char_environment_vfprintf_84_case1V2(char * dataCopy);
    ~CWE134_Uncontrolled_Format_String__char_environment_vfprintf_84_case1V2();

private:
    char * data;
};

#endif /* OMITCASE1 */

}
