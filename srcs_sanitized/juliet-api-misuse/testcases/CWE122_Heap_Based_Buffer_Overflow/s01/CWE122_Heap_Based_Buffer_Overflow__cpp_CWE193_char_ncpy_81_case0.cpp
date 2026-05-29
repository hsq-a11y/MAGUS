/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_char_ncpy_81_case0.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193.label.xml
Template File: sources-sink-81_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate memory for a string, but do not allocate space for NULL terminator
 * Case1Source: Allocate enough memory for a string and the NULL terminator
 * Sinks: ncpy
 *    Case0Sink : Copy string to data using strncpy()
 * Flow Variant: 81 Data flow: data passed in a parameter to a virtual method called via a reference
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_char_ncpy_81.h"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_char_ncpy_81
{

void CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_char_ncpy_81_case0::action(char * data) const
{
    {
        char source[10+1] = SRC_STRING;
        /* Copy length + 1 to include NUL terminator from source */
        /* NOTE: data may not have enough space to hold source */
        strncpy(data, source, strlen(source) + 1);
        printLine(data);
        delete [] data;
    }
}

}
#endif /* OMITCASE0 */
