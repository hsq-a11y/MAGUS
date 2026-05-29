/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_file_snprintf_67b.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: file Read input from a file
 * Case1Source: Copy a fixed string into data
 * Sinks: snprintf
 *    Case1Sink: snprintf with "%s" as the third argument and data as the fourth
 *    Case0Sink : snprintf with data as the third argument
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

#ifdef _WIN32
#define SNPRINTF _snprintf
#else
#define SNPRINTF snprintf
#endif

typedef struct _CWE134_Uncontrolled_Format_String__char_file_snprintf_67_structType
{
    char * structFirst;
} CWE134_Uncontrolled_Format_String__char_file_snprintf_67_structType;

#ifndef OMITCASE0

void CWE134_Uncontrolled_Format_String__char_file_snprintf_67b_case0Sink(CWE134_Uncontrolled_Format_String__char_file_snprintf_67_structType myStruct)
{
    char * data = myStruct.structFirst;
    {
        char dest[100] = "";
        /* NOTE: Do not specify the format allowing a possible format string vulnerability */
        SNPRINTF(dest, 100-1, data);
        printLine(dest);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE134_Uncontrolled_Format_String__char_file_snprintf_67b_case1V1Sink(CWE134_Uncontrolled_Format_String__char_file_snprintf_67_structType myStruct)
{
    char * data = myStruct.structFirst;
    {
        char dest[100] = "";
        /* NOTE: Do not specify the format allowing a possible format string vulnerability */
        SNPRINTF(dest, 100-1, data);
        printLine(dest);
    }
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE134_Uncontrolled_Format_String__char_file_snprintf_67b_case1V2Sink(CWE134_Uncontrolled_Format_String__char_file_snprintf_67_structType myStruct)
{
    char * data = myStruct.structFirst;
    {
        char dest[100] = "";
        /* ALT: Specify the format disallowing a format string vulnerability */
        SNPRINTF(dest, 100-1, "%s", data);
        printLine(dest);
    }
}

#endif /* OMITCASE1 */
