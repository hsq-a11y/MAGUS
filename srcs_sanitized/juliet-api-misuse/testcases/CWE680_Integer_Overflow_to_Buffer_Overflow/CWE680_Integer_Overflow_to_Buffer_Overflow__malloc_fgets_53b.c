/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fgets_53b.c
Label Definition File: CWE680_Integer_Overflow_to_Buffer_Overflow__malloc.label.xml
Template File: sources-sink-53b.tmpl.c
*/
/*
 * @description
 * CWE: 680 Integer Overflow to Buffer Overflow
 * Case0Source: fgets Read data from the console using fgets()
 * Case1Source: Small number greater than zero that will not cause an integer overflow in the sink
 * Sink:
 *    Case0Sink : Attempt to allocate array using length value from source
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

/* case0 function declaration */
void CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fgets_53c_case0Sink(int data);

void CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fgets_53b_case0Sink(int data)
{
    CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fgets_53c_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declaration */
void CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fgets_53c_case1V1Sink(int data);

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fgets_53b_case1V1Sink(int data)
{
    CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fgets_53c_case1V1Sink(data);
}

#endif /* OMITCASE1 */
