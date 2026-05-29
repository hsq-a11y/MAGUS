/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__int64_t_realloc_61b.c
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: realloc Allocate data using realloc()
 * Sinks:
 *    Case1Sink: Check to see if the data allocation failed and if not, use data
 *    Case0Sink : Don't check for NULL and use data
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

int64_t * CWE690_NULL_Deref_From_Return__int64_t_realloc_61b_case0Source(int64_t * data)
{
    /* NOTE: Allocate memory without checking if the memory allocation function failed */
    data = (int64_t *)realloc(data, 1*sizeof(int64_t));
    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2() uses the Case0Source with the Case1Sink */
int64_t * CWE690_NULL_Deref_From_Return__int64_t_realloc_61b_case1V2Source(int64_t * data)
{
    /* NOTE: Allocate memory without checking if the memory allocation function failed */
    data = (int64_t *)realloc(data, 1*sizeof(int64_t));
    return data;
}

#endif /* OMITCASE1 */
