/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__struct_twoIntsStruct_calloc_54e.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-54e.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source: calloc Allocate data using calloc()
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call free() on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

void CWE401_Memory_Leak__struct_twoIntsStruct_calloc_54e_case0Sink(struct _twoIntsStruct * data)
{
    /* NOTE: No deallocation */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE401_Memory_Leak__struct_twoIntsStruct_calloc_54e_case1V1Sink(struct _twoIntsStruct * data)
{
    /* NOTE: No deallocation */
    ; /* empty statement needed for some flow variants */
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE401_Memory_Leak__struct_twoIntsStruct_calloc_54e_case1V2Sink(struct _twoIntsStruct * data)
{
    /* ALT: Deallocate memory */
    free(data);
}

#endif /* OMITCASE1 */
