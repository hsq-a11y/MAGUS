/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_61b.c
Label Definition File: CWE680_Integer_Overflow_to_Buffer_Overflow__malloc.label.xml
Template File: sources-sink-61b.tmpl.c
*/
/*
 * @description
 * CWE: 680 Integer Overflow to Buffer Overflow
 * Case0Source: rand Set data to result of rand(), which may be zero
 * Case1Source: Small number greater than zero that will not cause an integer overflow in the sink
 * Sinks:
 *    Case0Sink : Attempt to allocate array using length value from source
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

int CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_61b_case0Source(int data)
{
    /* NOTE: Set data to a random value */
    data = RAND32();
    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
int CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_61b_case1V1Source(int data)
{
    /* ALT: Set data to a relatively small number greater than zero */
    data = 20;
    return data;
}

#endif /* OMITCASE1 */
