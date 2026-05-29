/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_char_memmove_84_case1V1.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193.label.xml
Template File: sources-sink-84_case1V1.tmpl.cpp
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
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_char_memmove_84.h"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_char_memmove_84
{
CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_char_memmove_84_case1V1::CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_char_memmove_84_case1V1(char * dataCopy)
{
    data = dataCopy;
    /* ALT: Allocate space for a null terminator */
    data = new char[10+1];
}

CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_char_memmove_84_case1V1::~CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_char_memmove_84_case1V1()
{
    {
        char source[10+1] = SRC_STRING;
        /* Copy length + 1 to include NUL terminator from source */
        /* NOTE: data may not have enough space to hold source */
        memmove(data, source, (strlen(source) + 1) * sizeof(char));
        printLine(data);
        delete [] data;
    }
}
}
#endif /* OMITCASE1 */
