/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_dest_wchar_t_cpy_83.h
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_dest.label.xml
Template File: sources-sink-83.tmpl.h
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate using new[] and set data pointer to a small buffer
 * Case1Source: Allocate using new[] and set data pointer to a large buffer
 * Sinks: cpy
 *    Case0Sink : Copy string to data using wcscpy
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_dest_wchar_t_cpy_83
{

#ifndef OMITCASE0

class CWE122_Heap_Based_Buffer_Overflow__cpp_dest_wchar_t_cpy_83_case0
{
public:
    CWE122_Heap_Based_Buffer_Overflow__cpp_dest_wchar_t_cpy_83_case0(wchar_t * dataCopy);
    ~CWE122_Heap_Based_Buffer_Overflow__cpp_dest_wchar_t_cpy_83_case0();

private:
    wchar_t * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE122_Heap_Based_Buffer_Overflow__cpp_dest_wchar_t_cpy_83_case1V1
{
public:
    CWE122_Heap_Based_Buffer_Overflow__cpp_dest_wchar_t_cpy_83_case1V1(wchar_t * dataCopy);
    ~CWE122_Heap_Based_Buffer_Overflow__cpp_dest_wchar_t_cpy_83_case1V1();

private:
    wchar_t * data;
};

#endif /* OMITCASE1 */

}
