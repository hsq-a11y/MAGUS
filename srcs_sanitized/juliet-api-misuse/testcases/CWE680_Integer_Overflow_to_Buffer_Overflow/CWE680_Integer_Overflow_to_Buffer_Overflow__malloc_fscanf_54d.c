/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fscanf_54d.c
Label Definition File: CWE680_Integer_Overflow_to_Buffer_Overflow__malloc.label.xml
Template File: sources-sink-54d.tmpl.c
*/
/*
 * @description
 * CWE: 680 Integer Overflow to Buffer Overflow
 * Case0Source: fscanf Read data from the console using fscanf()
 * Case1Source: Small number greater than zero that will not cause an integer overflow in the sink
 * Sink:
 *    Case0Sink : Attempt to allocate array using length value from source
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

/* case0 function declaration */
void CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fscanf_54e_case0Sink(int data);

void CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fscanf_54d_case0Sink(int data)
{
    CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fscanf_54e_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declaration */
void CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fscanf_54e_case1V1Sink(int data);

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fscanf_54d_case1V1Sink(int data)
{
    CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fscanf_54e_case1V1Sink(data);
}

#endif /* OMITCASE1 */
