/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_wchar_t_memmove_84_case0.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193.label.xml
Template File: sources-sink-84_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate memory for a string, but do not allocate space for NULL terminator
 * Case1Source: Allocate enough memory for a string and the NULL terminator
 * Sinks: memmove
 *    Case0Sink : Copy string to data using memmove()
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_wchar_t_memmove_84.h"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_wchar_t_memmove_84
{
CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_wchar_t_memmove_84_case0::CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_wchar_t_memmove_84_case0(wchar_t * dataCopy)
{
    data = dataCopy;
    /* NOTE: Did not leave space for a null terminator */
    data = new wchar_t[10];
}

CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_wchar_t_memmove_84_case0::~CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_wchar_t_memmove_84_case0()
{
    {
        wchar_t source[10+1] = SRC_STRING;
        /* Copy length + 1 to include NUL terminator from source */
        /* NOTE: data may not have enough space to hold source */
        memmove(data, source, (wcslen(source) + 1) * sizeof(wchar_t));
        printWLine(data);
        delete [] data;
    }
}
}
#endif /* OMITCASE0 */
