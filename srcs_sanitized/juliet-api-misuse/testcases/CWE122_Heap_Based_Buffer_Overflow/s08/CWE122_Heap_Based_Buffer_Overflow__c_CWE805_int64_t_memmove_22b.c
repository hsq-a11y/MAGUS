/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memmove_22b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE805.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate using malloc() and set data pointer to a small buffer
 * Case1Source: Allocate using malloc() and set data pointer to a large buffer
 * Sink: memmove
 *    Case0Sink : Copy int64_t array to data using memmove
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the source function */
extern int CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memmove_22_case0Global;

int64_t * CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memmove_22_case0Source(int64_t * data)
{
    if(CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memmove_22_case0Global)
    {
        /* NOTE: Allocate and point data to a small buffer that is smaller than the large buffer used in the sinks */
        data = (int64_t *)malloc(50*sizeof(int64_t));
        if (data == NULL) {exit(-1);}
    }
    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the source functions. */
extern int CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memmove_22_case1V11Global;
extern int CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memmove_22_case1V12Global;

/* case1V11() - use case1source and case0sink by setting the static variable to false instead of true */
int64_t * CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memmove_22_case1V11Source(int64_t * data)
{
    if(CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memmove_22_case1V11Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: Allocate and point data to a large buffer that is at least as large as the large buffer used in the sink */
        data = (int64_t *)malloc(100*sizeof(int64_t));
        if (data == NULL) {exit(-1);}
    }
    return data;
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the if in the source function */
int64_t * CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memmove_22_case1V12Source(int64_t * data)
{
    if(CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memmove_22_case1V12Global)
    {
        /* ALT: Allocate and point data to a large buffer that is at least as large as the large buffer used in the sink */
        data = (int64_t *)malloc(100*sizeof(int64_t));
        if (data == NULL) {exit(-1);}
    }
    return data;
}

#endif /* OMITCASE1 */
