/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_63b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__sizeof.label.xml
Template File: sources-sink-63b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Initialize the source buffer using the size of a pointer
 * Case1Source: Initialize the source buffer using the size of the DataElementType
 * Sinks:
 *    Case0Sink : Print then free data
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

void CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_63b_case0Sink(int64_t * * dataPtr)
{
    int64_t * data = *dataPtr;
    /* NOTE: Attempt to use data, which may not have enough memory allocated */
    printLongLongLine(*data);
    free(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_63b_case1V1Sink(int64_t * * dataPtr)
{
    int64_t * data = *dataPtr;
    /* NOTE: Attempt to use data, which may not have enough memory allocated */
    printLongLongLine(*data);
    free(data);
}

#endif /* OMITCASE1 */
