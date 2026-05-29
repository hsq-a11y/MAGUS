/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_file_fprintf_67b.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: file Read input from a file
 * Case1Source: Copy a fixed string into data
 * Sinks: fprintf
 *    Case1Sink: fwprintf with "%s" as the second argument and data as the third
 *    Case0Sink : fwprintf with data as the second argument
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
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

typedef struct _CWE134_Uncontrolled_Format_String__wchar_t_file_fprintf_67_structType
{
    wchar_t * structFirst;
} CWE134_Uncontrolled_Format_String__wchar_t_file_fprintf_67_structType;

#ifndef OMITCASE0

void CWE134_Uncontrolled_Format_String__wchar_t_file_fprintf_67b_case0Sink(CWE134_Uncontrolled_Format_String__wchar_t_file_fprintf_67_structType myStruct)
{
    wchar_t * data = myStruct.structFirst;
    /* NOTE: Do not specify the format allowing a possible format string vulnerability */
    fwprintf(stdout, data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE134_Uncontrolled_Format_String__wchar_t_file_fprintf_67b_case1V1Sink(CWE134_Uncontrolled_Format_String__wchar_t_file_fprintf_67_structType myStruct)
{
    wchar_t * data = myStruct.structFirst;
    /* NOTE: Do not specify the format allowing a possible format string vulnerability */
    fwprintf(stdout, data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE134_Uncontrolled_Format_String__wchar_t_file_fprintf_67b_case1V2Sink(CWE134_Uncontrolled_Format_String__wchar_t_file_fprintf_67_structType myStruct)
{
    wchar_t * data = myStruct.structFirst;
    /* ALT: Specify the format disallowing a format string vulnerability */
    fwprintf(stdout, L"%s\n", data);
}

#endif /* OMITCASE1 */
