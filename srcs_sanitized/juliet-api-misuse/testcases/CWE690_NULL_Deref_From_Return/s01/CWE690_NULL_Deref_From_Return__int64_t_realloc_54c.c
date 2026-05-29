/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__int64_t_realloc_54c.c
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-54c.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: realloc Allocate data using realloc()
 * Sinks:
 *    Case1Sink: Check to see if the data allocation failed and if not, use data
 *    Case0Sink : Don't check for NULL and use data
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

/* case0 function declaration */
void CWE690_NULL_Deref_From_Return__int64_t_realloc_54d_case0Sink(int64_t * data);

void CWE690_NULL_Deref_From_Return__int64_t_realloc_54c_case0Sink(int64_t * data)
{
    CWE690_NULL_Deref_From_Return__int64_t_realloc_54d_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE690_NULL_Deref_From_Return__int64_t_realloc_54d_case1V2Sink(int64_t * data);

void CWE690_NULL_Deref_From_Return__int64_t_realloc_54c_case1V2Sink(int64_t * data)
{
    CWE690_NULL_Deref_From_Return__int64_t_realloc_54d_case1V2Sink(data);
}

#endif /* OMITCASE1 */
