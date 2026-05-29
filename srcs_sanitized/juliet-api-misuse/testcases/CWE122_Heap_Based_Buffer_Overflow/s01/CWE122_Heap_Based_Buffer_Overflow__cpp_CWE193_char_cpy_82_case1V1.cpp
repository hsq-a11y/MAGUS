/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_char_cpy_82_case1V1.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193.label.xml
Template File: sources-sink-82_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate memory for a string, but do not allocate space for NULL terminator
 * Case1Source: Allocate enough memory for a string and the NULL terminator
 * Sinks: cpy
 *    Case0Sink : Copy string to data using strcpy()
 * Flow Variant: 82 Data flow: data passed in a parameter to a virtual method called via a pointer
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_char_cpy_82.h"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_char_cpy_82
{

void CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_char_cpy_82_case1V1::action(char * data)
{
    {
        char source[10+1] = SRC_STRING;
        /* NOTE: data may not have enough space to hold source */
        strcpy(data, source);
        printLine(data);
        delete [] data;
    }
}

}
#endif /* OMITCASE1 */
