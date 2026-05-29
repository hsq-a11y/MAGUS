/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_loop_53c.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE805.label.xml
Template File: sources-sink-53c.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate using malloc() and set data pointer to a small buffer
 * Case1Source: Allocate using malloc() and set data pointer to a large buffer
 * Sink: loop
 *    Case0Sink : Copy twoIntsStruct array to data using a loop
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

/* case0 function declaration */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_loop_53d_case0Sink(twoIntsStruct * data);

void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_loop_53c_case0Sink(twoIntsStruct * data)
{
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_loop_53d_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declaration */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_loop_53d_case1V1Sink(twoIntsStruct * data);

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_loop_53c_case1V1Sink(twoIntsStruct * data)
{
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_loop_53d_case1V1Sink(data);
}

#endif /* OMITCASE1 */
