/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE427_Uncontrolled_Search_Path_Element__char_file_54c.c
Label Definition File: CWE427_Uncontrolled_Search_Path_Element.label.xml
Template File: sources-sink-54c.tmpl.c
*/
/*
 * @description
 * CWE: 427 Uncontrolled Search Path Element
 * Case0Source: file Read input from a file
 * Case1Source: Use a hardcoded path
 * Sink:
 *    Case0Sink : Set the environment variable
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#ifdef _WIN32
#define NEW_PATH "%SystemRoot%\\system32"
#define PUTENV _putenv
#else
#define NEW_PATH "/bin"
#define PUTENV putenv
#endif

#ifdef _WIN32
#define FILENAME "C:\\temp\\file.txt"
#else
#define FILENAME "/tmp/file.txt"
#endif

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

/* case0 function declaration */
void CWE427_Uncontrolled_Search_Path_Element__char_file_54d_case0Sink(char * data);

void CWE427_Uncontrolled_Search_Path_Element__char_file_54c_case0Sink(char * data)
{
    CWE427_Uncontrolled_Search_Path_Element__char_file_54d_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declaration */
void CWE427_Uncontrolled_Search_Path_Element__char_file_54d_case1V1Sink(char * data);

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE427_Uncontrolled_Search_Path_Element__char_file_54c_case1V1Sink(char * data)
{
    CWE427_Uncontrolled_Search_Path_Element__char_file_54d_case1V1Sink(data);
}

#endif /* OMITCASE1 */
