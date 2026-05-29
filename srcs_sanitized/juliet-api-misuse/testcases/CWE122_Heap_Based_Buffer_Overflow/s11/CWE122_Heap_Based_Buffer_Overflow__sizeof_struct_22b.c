/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_22b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__sizeof.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Initialize the source buffer using the size of a pointer
 * Case1Source: Initialize the source buffer using the size of the DataElementType
 * Sink:
 *    Case0Sink : Print then free data
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the source function */
extern int CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_22_case0Global;

twoIntsStruct * CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_22_case0Source(twoIntsStruct * data)
{
    if(CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_22_case0Global)
    {
        /* INCIDENTAL: CWE-467 (Use of sizeof() on a pointer type) */
        /* NOTE: Using sizeof the pointer and not the data type in malloc() */
        data = (twoIntsStruct *)malloc(sizeof(data));
        if (data == NULL) {exit(-1);}
        data->intOne = 1;
        data->intTwo = 2;
    }
    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the source functions. */
extern int CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_22_case1V11Global;
extern int CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_22_case1V12Global;

/* case1V11() - use case1source and case0sink by setting the static variable to false instead of true */
twoIntsStruct * CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_22_case1V11Source(twoIntsStruct * data)
{
    if(CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_22_case1V11Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: Using sizeof the data type in malloc() */
        data = (twoIntsStruct *)malloc(sizeof(*data));
        if (data == NULL) {exit(-1);}
        data->intOne = 1;
        data->intTwo = 2;
    }
    return data;
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the if in the source function */
twoIntsStruct * CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_22_case1V12Source(twoIntsStruct * data)
{
    if(CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_22_case1V12Global)
    {
        /* ALT: Using sizeof the data type in malloc() */
        data = (twoIntsStruct *)malloc(sizeof(*data));
        if (data == NULL) {exit(-1);}
        data->intOne = 1;
        data->intTwo = 2;
    }
    return data;
}

#endif /* OMITCASE1 */
