/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_class_memcpy_84.h
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805.label.xml
Template File: sources-sink-84.tmpl.h
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate using new[] and set data pointer to a small buffer
 * Case1Source: Allocate using new[] and set data pointer to a large buffer
 * Sinks: memcpy
 *    Case0Sink : Copy TwoIntsClass array to data using memcpy
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_class_memcpy_84
{

#ifndef OMITCASE0

class CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_class_memcpy_84_case0
{
public:
    CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_class_memcpy_84_case0(TwoIntsClass * dataCopy);
    ~CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_class_memcpy_84_case0();

private:
    TwoIntsClass * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_class_memcpy_84_case1V1
{
public:
    CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_class_memcpy_84_case1V1(TwoIntsClass * dataCopy);
    ~CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_class_memcpy_84_case1V1();

private:
    TwoIntsClass * data;
};

#endif /* OMITCASE1 */

}
