/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memcpy_84_case1V1.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE193.label.xml
Template File: sources-sink-84_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate memory for a string, but do not allocate space for NULL terminator
 * Case1Source: Allocate enough memory for a string and the NULL terminator
 * Sinks: memcpy
 *    Case0Sink : Copy string to data using memcpy()
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memcpy_84.h"

namespace CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memcpy_84
{
CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memcpy_84_case1V1::CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memcpy_84_case1V1(char * dataCopy)
{
    data = dataCopy;
    /* ALT: Allocate space for a null terminator */
    data = (char *)malloc((10+1)*sizeof(char));
    if (data == NULL) {exit(-1);}
}

CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memcpy_84_case1V1::~CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memcpy_84_case1V1()
{
    {
        char source[10+1] = SRC_STRING;
        /* Copy length + 1 to include NUL terminator from source */
        /* NOTE: data may not have enough space to hold source */
        memcpy(data, source, (strlen(source) + 1) * sizeof(char));
        printLine(data);
        free(data);
    }
}
}
#endif /* OMITCASE1 */
