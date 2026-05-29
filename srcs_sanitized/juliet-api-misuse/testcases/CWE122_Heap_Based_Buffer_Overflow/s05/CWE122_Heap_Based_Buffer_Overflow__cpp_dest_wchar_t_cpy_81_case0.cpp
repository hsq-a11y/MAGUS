/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_dest_wchar_t_cpy_81_case0.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_dest.label.xml
Template File: sources-sink-81_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate using new[] and set data pointer to a small buffer
 * Case1Source: Allocate using new[] and set data pointer to a large buffer
 * Sinks: cpy
 *    Case0Sink : Copy string to data using wcscpy
 * Flow Variant: 81 Data flow: data passed in a parameter to a virtual method called via a reference
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__cpp_dest_wchar_t_cpy_81.h"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_dest_wchar_t_cpy_81
{

void CWE122_Heap_Based_Buffer_Overflow__cpp_dest_wchar_t_cpy_81_case0::action(wchar_t * data) const
{
    {
        wchar_t source[100];
        wmemset(source, L'C', 100-1); /* fill with L'C's */
        source[100-1] = L'\0'; /* null terminate */
        /* NOTE: Possible buffer overflow if source is larger than data */
        wcscpy(data, source);
        printWLine(data);
        delete [] data;
    }
}

}
#endif /* OMITCASE0 */
