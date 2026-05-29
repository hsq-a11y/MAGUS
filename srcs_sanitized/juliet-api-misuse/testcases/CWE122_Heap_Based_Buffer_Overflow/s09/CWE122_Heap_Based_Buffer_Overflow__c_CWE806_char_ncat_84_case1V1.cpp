/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_ncat_84_case1V1.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE806.label.xml
Template File: sources-sink-84_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Initialize data as a large string
 * Case1Source: Initialize data as a small string
 * Sinks: ncat
 *    Case0Sink : Copy data to string using strncat
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_ncat_84.h"

namespace CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_ncat_84
{
CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_ncat_84_case1V1::CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_ncat_84_case1V1(char * dataCopy)
{
    data = dataCopy;
    /* ALT: Initialize data as a small buffer that as small or smaller than the small buffer used in the sink */
    memset(data, 'A', 50-1); /* fill with 'A's */
    data[50-1] = '\0'; /* null terminate */
}

CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_ncat_84_case1V1::~CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_ncat_84_case1V1()
{
    {
        char dest[50] = "";
        /* NOTE: Possible buffer overflow if data is larger than sizeof(dest)-strlen(dest)*/
        strncat(dest, data, strlen(data));
        dest[50-1] = '\0'; /* Ensure the destination buffer is null terminated */
        printLine(data);
        free(data);
    }
}
}
#endif /* OMITCASE1 */
