/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_22b.c
Label Definition File: CWE680_Integer_Overflow_to_Buffer_Overflow__malloc.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 680 Integer Overflow to Buffer Overflow
 * Case0Source: rand Set data to result of rand(), which may be zero
 * Case1Source: Small number greater than zero that will not cause an integer overflow in the sink
 * Sink:
 *    Case0Sink : Attempt to allocate array using length value from source
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the source function */
extern int CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_22_case0Global;

int CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_22_case0Source(int data)
{
    if(CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_22_case0Global)
    {
        /* NOTE: Set data to a random value */
        data = RAND32();
    }
    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the source functions. */
extern int CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_22_case1V11Global;
extern int CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_22_case1V12Global;

/* case1V11() - use case1source and case0sink by setting the static variable to false instead of true */
int CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_22_case1V11Source(int data)
{
    if(CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_22_case1V11Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: Set data to a relatively small number greater than zero */
        data = 20;
    }
    return data;
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the if in the source function */
int CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_22_case1V12Source(int data)
{
    if(CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_22_case1V12Global)
    {
        /* ALT: Set data to a relatively small number greater than zero */
        data = 20;
    }
    return data;
}

#endif /* OMITCASE1 */
