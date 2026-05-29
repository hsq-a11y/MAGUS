/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_wchar_t_ncpy_84_case0.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805.string.label.xml
Template File: sources-sink-84_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate using new[] and set data pointer to a small buffer
 * Case1Source: Allocate using new[] and set data pointer to a large buffer
 * Sinks: ncpy
 *    Case0Sink : Copy string to data using wcsncpy
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_wchar_t_ncpy_84.h"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_wchar_t_ncpy_84
{
CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_wchar_t_ncpy_84_case0::CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_wchar_t_ncpy_84_case0(wchar_t * dataCopy)
{
    data = dataCopy;
    /* NOTE: Allocate using new[] and point data to a small buffer that is smaller than the large buffer used in the sinks */
    data = new wchar_t[50];
    data[0] = L'\0'; /* null terminate */
}

CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_wchar_t_ncpy_84_case0::~CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_wchar_t_ncpy_84_case0()
{
    {
        wchar_t source[100];
        wmemset(source, L'C', 100-1); /* fill with L'C's */
        source[100-1] = L'\0'; /* null terminate */
        /* NOTE: Possible buffer overflow if source is larger than data */
        wcsncpy(data, source, 100-1);
        data[100-1] = L'\0'; /* Ensure the destination buffer is null terminated */
        printWLine(data);
        delete [] data;
    }
}
}
#endif /* OMITCASE0 */
