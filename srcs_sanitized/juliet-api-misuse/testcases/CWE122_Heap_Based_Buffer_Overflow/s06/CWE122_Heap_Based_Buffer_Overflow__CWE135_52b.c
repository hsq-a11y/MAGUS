/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__CWE135_52b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__CWE135.label.xml
Template File: sources-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Void pointer to a wchar_t array
 * Case1Source: Void pointer to a char array
 * Sinks:
 *    Case1Sink: Allocate memory using wcslen() and copy data
 *    Case0Sink : Allocate memory using strlen() and copy data
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

/* case0 function declaration */
void CWE122_Heap_Based_Buffer_Overflow__CWE135_52c_case0Sink(void * data);

void CWE122_Heap_Based_Buffer_Overflow__CWE135_52b_case0Sink(void * data)
{
    CWE122_Heap_Based_Buffer_Overflow__CWE135_52c_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE122_Heap_Based_Buffer_Overflow__CWE135_52c_case1V1Sink(void * data);

void CWE122_Heap_Based_Buffer_Overflow__CWE135_52b_case1V1Sink(void * data)
{
    CWE122_Heap_Based_Buffer_Overflow__CWE135_52c_case1V1Sink(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE122_Heap_Based_Buffer_Overflow__CWE135_52c_case1V2Sink(void * data);

void CWE122_Heap_Based_Buffer_Overflow__CWE135_52b_case1V2Sink(void * data)
{
    CWE122_Heap_Based_Buffer_Overflow__CWE135_52c_case1V2Sink(data);
}

#endif /* OMITCASE1 */
