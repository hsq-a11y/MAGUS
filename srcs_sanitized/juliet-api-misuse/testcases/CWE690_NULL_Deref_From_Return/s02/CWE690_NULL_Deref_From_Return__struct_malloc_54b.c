/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__struct_malloc_54b.c
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-54b.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: malloc Allocate data using malloc()
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
void CWE690_NULL_Deref_From_Return__struct_malloc_54c_case0Sink(twoIntsStruct * data);

void CWE690_NULL_Deref_From_Return__struct_malloc_54b_case0Sink(twoIntsStruct * data)
{
    CWE690_NULL_Deref_From_Return__struct_malloc_54c_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE690_NULL_Deref_From_Return__struct_malloc_54c_case1V2Sink(twoIntsStruct * data);

void CWE690_NULL_Deref_From_Return__struct_malloc_54b_case1V2Sink(twoIntsStruct * data)
{
    CWE690_NULL_Deref_From_Return__struct_malloc_54c_case1V2Sink(data);
}

#endif /* OMITCASE1 */
