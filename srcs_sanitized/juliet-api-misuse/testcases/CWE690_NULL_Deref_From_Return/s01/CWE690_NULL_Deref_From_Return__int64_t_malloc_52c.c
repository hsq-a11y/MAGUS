/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__int64_t_malloc_52c.c
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-52c.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: malloc Allocate data using malloc()
 * Sinks:
 *    Case1Sink: Check to see if the data allocation failed and if not, use data
 *    Case0Sink : Don't check for NULL and use data
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

void CWE690_NULL_Deref_From_Return__int64_t_malloc_52c_case0Sink(int64_t * data)
{
    /* NOTE: Initialize memory buffer without checking to see if the memory allocation function failed */
    data[0] = 5LL;
    printLongLongLine(data[0]);
    free(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

void CWE690_NULL_Deref_From_Return__int64_t_malloc_52c_case1V2Sink(int64_t * data)
{
    /* ALT: Check to see if the memory allocation function was successful before initializing the memory buffer */
    if (data != NULL)
    {
        data[0] = 5LL;
        printLongLongLine(data[0]);
        free(data);
    }
}

#endif /* OMITCASE1 */
