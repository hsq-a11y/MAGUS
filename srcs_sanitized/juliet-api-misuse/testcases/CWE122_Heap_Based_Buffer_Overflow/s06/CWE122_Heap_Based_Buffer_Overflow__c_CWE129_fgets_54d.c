/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fgets_54d.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE129.label.xml
Template File: sources-sinks-54d.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source: fgets Read data from the console using fgets()
 * Case1Source: Larger than zero but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)

#ifndef OMITCASE0

/* case0 function declaration */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fgets_54e_case0Sink(int data);

void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fgets_54d_case0Sink(int data)
{
    CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fgets_54e_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fgets_54e_case1V1Sink(int data);

void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fgets_54d_case1V1Sink(int data)
{
    CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fgets_54e_case1V1Sink(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fgets_54e_case1V2Sink(int data);

void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fgets_54d_case1V2Sink(int data)
{
    CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fgets_54e_case1V2Sink(data);
}

#endif /* OMITCASE1 */
