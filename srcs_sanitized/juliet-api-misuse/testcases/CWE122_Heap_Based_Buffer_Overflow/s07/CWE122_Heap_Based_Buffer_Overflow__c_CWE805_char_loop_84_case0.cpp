/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_loop_84_case0.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE805.string.label.xml
Template File: sources-sink-84_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate using malloc() and set data pointer to a small buffer
 * Case1Source: Allocate using malloc() and set data pointer to a large buffer
 * Sinks: loop
 *    Case0Sink : Copy string to data using a loop
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_loop_84.h"

namespace CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_loop_84
{
CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_loop_84_case0::CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_loop_84_case0(char * dataCopy)
{
    data = dataCopy;
    /* NOTE: Allocate and point data to a small buffer that is smaller than the large buffer used in the sinks */
    data = (char *)malloc(50*sizeof(char));
    if (data == NULL) {exit(-1);}
    data[0] = '\0'; /* null terminate */
}

CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_loop_84_case0::~CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_loop_84_case0()
{
    {
        size_t i;
        char source[100];
        memset(source, 'C', 100-1); /* fill with 'C's */
        source[100-1] = '\0'; /* null terminate */
        /* NOTE: Possible buffer overflow if source is larger than data */
        for (i = 0; i < 100; i++)
        {
            data[i] = source[i];
        }
        data[100-1] = '\0'; /* Ensure the destination buffer is null terminated */
        printLine(data);
        free(data);
    }
}
}
#endif /* OMITCASE0 */
