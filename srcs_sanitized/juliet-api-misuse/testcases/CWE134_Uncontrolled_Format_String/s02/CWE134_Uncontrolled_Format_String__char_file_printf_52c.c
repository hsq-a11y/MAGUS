/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_file_printf_52c.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-52c.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: file Read input from a file
 * Case1Source: Copy a fixed string into data
 * Sinks: printf
 *    Case1Sink: printf with "%s" as the first argument and data as the second
 *    Case0Sink : printf with only data as an argument
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#ifdef _WIN32
#define FILENAME "C:\\temp\\file.txt"
#else
#define FILENAME "/tmp/file.txt"
#endif

#ifndef OMITCASE0

void CWE134_Uncontrolled_Format_String__char_file_printf_52c_case0Sink(char * data)
{
    /* NOTE: Do not specify the format allowing a possible format string vulnerability */
    printf(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE134_Uncontrolled_Format_String__char_file_printf_52c_case1V1Sink(char * data)
{
    /* NOTE: Do not specify the format allowing a possible format string vulnerability */
    printf(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE134_Uncontrolled_Format_String__char_file_printf_52c_case1V2Sink(char * data)
{
    /* ALT: Specify the format disallowing a format string vulnerability */
    printf("%s\n", data);
}

#endif /* OMITCASE1 */
