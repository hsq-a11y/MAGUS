/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_ncat_52b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE805.string.label.xml
Template File: sources-sink-52b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate using malloc() and set data pointer to a small buffer
 * Case1Source: Allocate using malloc() and set data pointer to a large buffer
 * Sink: ncat
 *    Case0Sink : Copy string to data using strncat
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

/* case0 function declaration */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_ncat_52c_case0Sink(char * data);

void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_ncat_52b_case0Sink(char * data)
{
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_ncat_52c_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declaration */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_ncat_52c_case1V1Sink(char * data);

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_ncat_52b_case1V1Sink(char * data)
{
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_ncat_52c_case1V1Sink(data);
}

#endif /* OMITCASE1 */
