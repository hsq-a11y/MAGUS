/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__twoIntsStruct_calloc_22b.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source: calloc Allocate data using calloc()
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call free() on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the sink function */
extern int CWE401_Memory_Leak__twoIntsStruct_calloc_22_case0Global;

void CWE401_Memory_Leak__twoIntsStruct_calloc_22_case0Sink(twoIntsStruct * data)
{
    if(CWE401_Memory_Leak__twoIntsStruct_calloc_22_case0Global)
    {
        /* NOTE: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the sink functions. */
extern int CWE401_Memory_Leak__twoIntsStruct_calloc_22_case1V21Global;
extern int CWE401_Memory_Leak__twoIntsStruct_calloc_22_case1V22Global;
extern int CWE401_Memory_Leak__twoIntsStruct_calloc_22_case1V1Global;

/* case1V21() - use case0source and case1sink by setting the static variable to false instead of true */
void CWE401_Memory_Leak__twoIntsStruct_calloc_22_case1V21Sink(twoIntsStruct * data)
{
    if(CWE401_Memory_Leak__twoIntsStruct_calloc_22_case1V21Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: Deallocate memory */
        free(data);
    }
}

/* case1V22() - use case0source and case1sink by reversing the blocks in the if in the sink function */
void CWE401_Memory_Leak__twoIntsStruct_calloc_22_case1V22Sink(twoIntsStruct * data)
{
    if(CWE401_Memory_Leak__twoIntsStruct_calloc_22_case1V22Global)
    {
        /* ALT: Deallocate memory */
        free(data);
    }
}

/* case1V1() - use case1source and case0sink */
void CWE401_Memory_Leak__twoIntsStruct_calloc_22_case1V1Sink(twoIntsStruct * data)
{
    if(CWE401_Memory_Leak__twoIntsStruct_calloc_22_case1V1Global)
    {
        /* NOTE: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

#endif /* OMITCASE1 */
