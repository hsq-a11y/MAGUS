/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__CWE135_83_case0.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__CWE135.label.xml
Template File: sources-sinks-83_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Void pointer to a wchar_t array
 * Case1Source: Void pointer to a char array
 * Sinks:
 *    Case1Sink: Allocate memory using wcslen() and copy data
 *    Case0Sink : Allocate memory using strlen() and copy data
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__CWE135_83.h"

namespace CWE122_Heap_Based_Buffer_Overflow__CWE135_83
{
CWE122_Heap_Based_Buffer_Overflow__CWE135_83_case0::CWE122_Heap_Based_Buffer_Overflow__CWE135_83_case0(void * dataCopy)
{
    data = dataCopy;
    {
        wchar_t * dataCase0Buffer = (wchar_t *)malloc(50*sizeof(wchar_t));
        if (dataCase0Buffer == NULL) {exit(-1);}
        wmemset(dataCase0Buffer, L'A', 50-1);
        dataCase0Buffer[50-1] = L'\0';
        /* NOTE: Set data to point to a wide string */
        data = (void *)dataCase0Buffer;
    }
}

CWE122_Heap_Based_Buffer_Overflow__CWE135_83_case0::~CWE122_Heap_Based_Buffer_Overflow__CWE135_83_case0()
{
    {
        /* NOTE: treating pointer as a char* when it may point to a wide string */
        size_t dataLen = strlen((char *)data);
        void * dest = (void *)calloc(dataLen+1, sizeof(wchar_t));
        if (dest == NULL) {exit(-1);}
        (void)wcscpy((wchar_t *)dest, (wchar_t *)data);
        printLine((char *)dest);
        free(dest);
    }
}
}
#endif /* OMITCASE0 */
