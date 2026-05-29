/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_char_loop_83.h
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805.string.label.xml
Template File: sources-sink-83.tmpl.h
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate using new[] and set data pointer to a small buffer
 * Case1Source: Allocate using new[] and set data pointer to a large buffer
 * Sinks: loop
 *    Case0Sink : Copy string to data using a loop
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_char_loop_83
{

#ifndef OMITCASE0

class CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_char_loop_83_case0
{
public:
    CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_char_loop_83_case0(char * dataCopy);
    ~CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_char_loop_83_case0();

private:
    char * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_char_loop_83_case1V1
{
public:
    CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_char_loop_83_case1V1(char * dataCopy);
    ~CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_char_loop_83_case1V1();

private:
    char * data;
};

#endif /* OMITCASE1 */

}
