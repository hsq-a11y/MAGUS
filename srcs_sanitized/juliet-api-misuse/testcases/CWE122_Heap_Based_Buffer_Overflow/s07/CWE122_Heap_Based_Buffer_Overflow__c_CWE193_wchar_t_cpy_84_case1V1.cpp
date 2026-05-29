/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_cpy_84_case1V1.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE193.label.xml
Template File: sources-sink-84_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate memory for a string, but do not allocate space for NULL terminator
 * Case1Source: Allocate enough memory for a string and the NULL terminator
 * Sinks: cpy
 *    Case0Sink : Copy string to data using wcscpy()
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_cpy_84.h"

namespace CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_cpy_84
{
CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_cpy_84_case1V1::CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_cpy_84_case1V1(wchar_t * dataCopy)
{
    data = dataCopy;
    /* ALT: Allocate space for a null terminator */
    data = (wchar_t *)malloc((10+1)*sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
}

CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_cpy_84_case1V1::~CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_cpy_84_case1V1()
{
    {
        wchar_t source[10+1] = SRC_STRING;
        /* NOTE: data may not have enough space to hold source */
        wcscpy(data, source);
        printWLine(data);
        free(data);
    }
}
}
#endif /* OMITCASE1 */
