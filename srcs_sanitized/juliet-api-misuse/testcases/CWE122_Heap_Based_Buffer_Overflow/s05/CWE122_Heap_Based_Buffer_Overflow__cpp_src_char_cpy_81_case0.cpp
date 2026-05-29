/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_src_char_cpy_81_case0.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_src.label.xml
Template File: sources-sink-81_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Initialize data as a large string
 * Case1Source: Initialize data as a small string
 * Sinks: cpy
 *    Case0Sink : Copy data to string using strcpy
 * Flow Variant: 81 Data flow: data passed in a parameter to a virtual method called via a reference
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__cpp_src_char_cpy_81.h"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_src_char_cpy_81
{

void CWE122_Heap_Based_Buffer_Overflow__cpp_src_char_cpy_81_case0::action(char * data) const
{
    {
        char dest[50] = "";
        /* NOTE: Possible buffer overflow if data is larger than dest */
        strcpy(dest, data);
        printLine(data);
        delete [] data;
    }
}

}
#endif /* OMITCASE0 */
