/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_52b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE129.label.xml
Template File: sources-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source: large Large index value that is greater than 10-1
 * Case1Source: Larger than zero but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

/* case0 function declaration */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_52c_case0Sink(int data);

void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_52b_case0Sink(int data)
{
    CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_52c_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_52c_case1V1Sink(int data);

void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_52b_case1V1Sink(int data)
{
    CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_52c_case1V1Sink(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_52c_case1V2Sink(int data);

void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_52b_case1V2Sink(int data)
{
    CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_52c_case1V2Sink(data);
}

#endif /* OMITCASE1 */
