/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__int_calloc_67b.c
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: calloc Allocate data using calloc()
 * Sinks:
 *    Case1Sink: Check to see if the data allocation failed and if not, use data
 *    Case0Sink : Don't check for NULL and use data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE690_NULL_Deref_From_Return__int_calloc_67_structType
{
    int * structFirst;
} CWE690_NULL_Deref_From_Return__int_calloc_67_structType;

#ifndef OMITCASE0

void CWE690_NULL_Deref_From_Return__int_calloc_67b_case0Sink(CWE690_NULL_Deref_From_Return__int_calloc_67_structType myStruct)
{
    int * data = myStruct.structFirst;
    /* NOTE: Initialize memory buffer without checking to see if the memory allocation function failed */
    data[0] = 5;
    printIntLine(data[0]);
    free(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE690_NULL_Deref_From_Return__int_calloc_67b_case1V2Sink(CWE690_NULL_Deref_From_Return__int_calloc_67_structType myStruct)
{
    int * data = myStruct.structFirst;
    /* ALT: Check to see if the memory allocation function was successful before initializing the memory buffer */
    if (data != NULL)
    {
        data[0] = 5;
        printIntLine(data[0]);
        free(data);
    }
}

#endif /* OMITCASE1 */
