/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE427_Uncontrolled_Search_Path_Element__wchar_t_console_67b.c
Label Definition File: CWE427_Uncontrolled_Search_Path_Element.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 427 Uncontrolled Search Path Element
 * Case0Source: console Read input from the console
 * Case1Source: Use a hardcoded path
 * Sinks:
 *    Case0Sink : Set the environment variable
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#ifdef _WIN32
#define NEW_PATH L"%SystemRoot%\\system32"
#define PUTENV _wputenv
#else
#define NEW_PATH L"/bin"
#define PUTENV putenv
#endif

typedef struct _CWE427_Uncontrolled_Search_Path_Element__wchar_t_console_67_structType
{
    wchar_t * structFirst;
} CWE427_Uncontrolled_Search_Path_Element__wchar_t_console_67_structType;

#ifndef OMITCASE0

void CWE427_Uncontrolled_Search_Path_Element__wchar_t_console_67b_case0Sink(CWE427_Uncontrolled_Search_Path_Element__wchar_t_console_67_structType myStruct)
{
    wchar_t * data = myStruct.structFirst;
    /* NOTE: Set a new environment variable with a path that is possibly insecure */
    PUTENV(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE427_Uncontrolled_Search_Path_Element__wchar_t_console_67b_case1V1Sink(CWE427_Uncontrolled_Search_Path_Element__wchar_t_console_67_structType myStruct)
{
    wchar_t * data = myStruct.structFirst;
    /* NOTE: Set a new environment variable with a path that is possibly insecure */
    PUTENV(data);
}

#endif /* OMITCASE1 */
