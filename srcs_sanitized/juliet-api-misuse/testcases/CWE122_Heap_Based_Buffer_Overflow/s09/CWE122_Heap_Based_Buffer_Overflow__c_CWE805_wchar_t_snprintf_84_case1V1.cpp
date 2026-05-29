/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE805_wchar_t_snprintf_84_case1V1.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE805.string.label.xml
Template File: sources-sink-84_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate using malloc() and set data pointer to a small buffer
 * Case1Source: Allocate using malloc() and set data pointer to a large buffer
 * Sinks: swprintf
 *    Case0Sink : Copy string to data using swprintf
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__c_CWE805_wchar_t_snprintf_84.h"

#ifdef _WIN32
#define SNPRINTF _snwprintf
#else
#define SNPRINTF swprintf
#endif

namespace CWE122_Heap_Based_Buffer_Overflow__c_CWE805_wchar_t_snprintf_84
{
CWE122_Heap_Based_Buffer_Overflow__c_CWE805_wchar_t_snprintf_84_case1V1::CWE122_Heap_Based_Buffer_Overflow__c_CWE805_wchar_t_snprintf_84_case1V1(wchar_t * dataCopy)
{
    data = dataCopy;
    /* ALT: Allocate and point data to a large buffer that is at least as large as the large buffer used in the sink */
    data = (wchar_t *)malloc(100*sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
    data[0] = L'\0'; /* null terminate */
}

CWE122_Heap_Based_Buffer_Overflow__c_CWE805_wchar_t_snprintf_84_case1V1::~CWE122_Heap_Based_Buffer_Overflow__c_CWE805_wchar_t_snprintf_84_case1V1()
{
    {
        wchar_t source[100];
        wmemset(source, L'C', 100-1); /* fill with L'C's */
        source[100-1] = L'\0'; /* null terminate */
        /* NOTE: Possible buffer overflow if source is larger than data */
        SNPRINTF(data, 100, L"%s", source);
        printWLine(data);
        free(data);
    }
}
}
#endif /* OMITCASE1 */
