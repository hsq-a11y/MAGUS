/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int64_t_memmove_83.h
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805.label.xml
Template File: sources-sink-83.tmpl.h
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate using new[] and set data pointer to a small buffer
 * Case1Source: Allocate using new[] and set data pointer to a large buffer
 * Sinks: memmove
 *    Case0Sink : Copy int64_t array to data using memmove
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int64_t_memmove_83
{

#ifndef OMITCASE0

class CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int64_t_memmove_83_case0
{
public:
    CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int64_t_memmove_83_case0(int64_t * dataCopy);
    ~CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int64_t_memmove_83_case0();

private:
    int64_t * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int64_t_memmove_83_case1V1
{
public:
    CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int64_t_memmove_83_case1V1(int64_t * dataCopy);
    ~CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int64_t_memmove_83_case1V1();

private:
    int64_t * data;
};

#endif /* OMITCASE1 */

}
