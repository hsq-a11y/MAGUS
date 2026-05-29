/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_environment_printf_84_case1V1.cpp
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-84_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: environment Read input from an environment variable
 * Case1Source: Copy a fixed string into data
 * Sinks: printf
 *    Case1Sink: printf with "%s" as the first argument and data as the second
 *    Case0Sink : printf with only data as an argument
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE134_Uncontrolled_Format_String__char_environment_printf_84.h"

#define ENV_VARIABLE "ADD"

#ifdef _WIN32
#define GETENV getenv
#else
#define GETENV getenv
#endif

namespace CWE134_Uncontrolled_Format_String__char_environment_printf_84
{
CWE134_Uncontrolled_Format_String__char_environment_printf_84_case1V1::CWE134_Uncontrolled_Format_String__char_environment_printf_84_case1V1(char * dataCopy)
{
    data = dataCopy;
    /* ALT: Use a fixed string that does not contain a format specifier */
    strcpy(data, "fixedstringtest");
}

CWE134_Uncontrolled_Format_String__char_environment_printf_84_case1V1::~CWE134_Uncontrolled_Format_String__char_environment_printf_84_case1V1()
{
    /* NOTE: Do not specify the format allowing a possible format string vulnerability */
    printf(data);
}
}
#endif /* OMITCASE1 */
