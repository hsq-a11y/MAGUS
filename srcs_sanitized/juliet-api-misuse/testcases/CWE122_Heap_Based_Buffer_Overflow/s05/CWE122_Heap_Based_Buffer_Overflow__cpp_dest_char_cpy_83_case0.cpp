/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_dest_char_cpy_83_case0.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_dest.label.xml
Template File: sources-sink-83_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate using new[] and set data pointer to a small buffer
 * Case1Source: Allocate using new[] and set data pointer to a large buffer
 * Sinks: cpy
 *    Case0Sink : Copy string to data using strcpy
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__cpp_dest_char_cpy_83.h"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_dest_char_cpy_83
{
CWE122_Heap_Based_Buffer_Overflow__cpp_dest_char_cpy_83_case0::CWE122_Heap_Based_Buffer_Overflow__cpp_dest_char_cpy_83_case0(char * dataCopy)
{
    data = dataCopy;
    /* NOTE: Allocate using new[] and point data to a small buffer that is smaller than the large buffer used in the sinks */
    data = new char[50];
    data[0] = '\0'; /* null terminate */
}

CWE122_Heap_Based_Buffer_Overflow__cpp_dest_char_cpy_83_case0::~CWE122_Heap_Based_Buffer_Overflow__cpp_dest_char_cpy_83_case0()
{
    {
        char source[100];
        memset(source, 'C', 100-1); /* fill with 'C's */
        source[100-1] = '\0'; /* null terminate */
        /* NOTE: Possible buffer overflow if source is larger than data */
        strcpy(data, source);
        printLine(data);
        delete [] data;
    }
}
}
#endif /* OMITCASE0 */
