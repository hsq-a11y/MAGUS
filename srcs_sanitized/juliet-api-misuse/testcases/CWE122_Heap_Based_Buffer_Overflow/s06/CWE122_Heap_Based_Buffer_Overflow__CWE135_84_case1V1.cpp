/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__CWE135_84_case1V1.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__CWE135.label.xml
Template File: sources-sinks-84_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Void pointer to a wchar_t array
 * Case1Source: Void pointer to a char array
 * Sinks:
 *    Case1Sink: Allocate memory using wcslen() and copy data
 *    Case0Sink : Allocate memory using strlen() and copy data
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__CWE135_84.h"

namespace CWE122_Heap_Based_Buffer_Overflow__CWE135_84
{
CWE122_Heap_Based_Buffer_Overflow__CWE135_84_case1V1::CWE122_Heap_Based_Buffer_Overflow__CWE135_84_case1V1(void * dataCopy)
{
    data = dataCopy;
    {
        char * dataCase1Buffer = (char *)malloc(50*sizeof(char));
        if (dataCase1Buffer == NULL) {exit(-1);}
        memset(dataCase1Buffer, 'A', 50-1);
        dataCase1Buffer[50-1] = '\0';
        /* ALT: Set data to point to a char string */
        data = (void *)dataCase1Buffer;
    }
}

CWE122_Heap_Based_Buffer_Overflow__CWE135_84_case1V1::~CWE122_Heap_Based_Buffer_Overflow__CWE135_84_case1V1()
{
    {
        /* NOTE: treating pointer as a char* when it may point to a wide string */
        size_t dataLen = strlen((char *)data);
        void * dest = (void *)calloc(dataLen+1, 1);
        if (dest == NULL) {exit(-1);}
        (void)strcpy((char *)dest, (char *)data);
        printLine((char *)dest);
        free(dest);
    }
}
}
#endif /* OMITCASE1 */
