/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__char_calloc_68b.c
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: calloc Allocate data using calloc()
 * Sinks:
 *    Case1Sink: Check to see if the data allocation failed and if not, use data
 *    Case0Sink : Don't check for NULL and use data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

extern char * CWE690_NULL_Deref_From_Return__char_calloc_68_case0DataForCase0Sink;

extern char * CWE690_NULL_Deref_From_Return__char_calloc_68_case0DataForCase1Sink;

#ifndef OMITCASE0

void CWE690_NULL_Deref_From_Return__char_calloc_68b_case0Sink()
{
    char * data = CWE690_NULL_Deref_From_Return__char_calloc_68_case0DataForCase0Sink;
    /* NOTE: Initialize memory buffer without checking to see if the memory allocation function failed */
    strcpy(data, "Initialize");
    printLine(data);
    free(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

void CWE690_NULL_Deref_From_Return__char_calloc_68b_case1V2Sink()
{
    char * data = CWE690_NULL_Deref_From_Return__char_calloc_68_case0DataForCase1Sink;
    /* ALT: Check to see if the memory allocation function was successful before initializing the memory buffer */
    if (data != NULL)
    {
        strcpy(data, "Initialize");
        printLine(data);
        free(data);
    }
}

#endif /* OMITCASE1 */
