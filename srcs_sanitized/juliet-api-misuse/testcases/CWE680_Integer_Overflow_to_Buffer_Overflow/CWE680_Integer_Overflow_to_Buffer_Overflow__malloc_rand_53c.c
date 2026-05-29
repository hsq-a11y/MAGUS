/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_53c.c
Label Definition File: CWE680_Integer_Overflow_to_Buffer_Overflow__malloc.label.xml
Template File: sources-sink-53c.tmpl.c
*/
/*
 * @description
 * CWE: 680 Integer Overflow to Buffer Overflow
 * Case0Source: rand Set data to result of rand(), which may be zero
 * Case1Source: Small number greater than zero that will not cause an integer overflow in the sink
 * Sink:
 *    Case0Sink : Attempt to allocate array using length value from source
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

/* case0 function declaration */
void CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_53d_case0Sink(int data);

void CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_53c_case0Sink(int data)
{
    CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_53d_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declaration */
void CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_53d_case1V1Sink(int data);

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_53c_case1V1Sink(int data)
{
    CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_53d_case1V1Sink(data);
}

#endif /* OMITCASE1 */
