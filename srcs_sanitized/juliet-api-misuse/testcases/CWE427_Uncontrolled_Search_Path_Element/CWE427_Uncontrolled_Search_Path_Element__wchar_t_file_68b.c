/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE427_Uncontrolled_Search_Path_Element__wchar_t_file_68b.c
Label Definition File: CWE427_Uncontrolled_Search_Path_Element.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 427 Uncontrolled Search Path Element
 * Case0Source: file Read input from a file
 * Case1Source: Use a hardcoded path
 * Sink:
 *    Case0Sink : Set the environment variable
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
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

#ifdef _WIN32
#define FILENAME "C:\\temp\\file.txt"
#else
#define FILENAME "/tmp/file.txt"
#endif

extern wchar_t * CWE427_Uncontrolled_Search_Path_Element__wchar_t_file_68_case0Data;
extern wchar_t * CWE427_Uncontrolled_Search_Path_Element__wchar_t_file_68_case1V1Data;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

void CWE427_Uncontrolled_Search_Path_Element__wchar_t_file_68b_case0Sink()
{
    wchar_t * data = CWE427_Uncontrolled_Search_Path_Element__wchar_t_file_68_case0Data;
    /* NOTE: Set a new environment variable with a path that is possibly insecure */
    PUTENV(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE427_Uncontrolled_Search_Path_Element__wchar_t_file_68b_case1V1Sink()
{
    wchar_t * data = CWE427_Uncontrolled_Search_Path_Element__wchar_t_file_68_case1V1Data;
    /* NOTE: Set a new environment variable with a path that is possibly insecure */
    PUTENV(data);
}

#endif /* OMITCASE1 */
