/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_file_printf_82_case1V1.cpp
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-82_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: file Read input from a file
 * Case1Source: Copy a fixed string into data
 * Sinks: printf
 *    Case1Sink: printf with "%s" as the first argument and data as the second
 *    Case0Sink : printf with only data as an argument
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE134_Uncontrolled_Format_String__char_file_printf_82.h"

namespace CWE134_Uncontrolled_Format_String__char_file_printf_82
{

void CWE134_Uncontrolled_Format_String__char_file_printf_82_case1V1::action(char * data)
{
    /* NOTE: Do not specify the format allowing a possible format string vulnerability */
    printf(data);
}

}
#endif /* OMITCASE1 */
