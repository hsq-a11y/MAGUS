/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_84.h
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__sizeof.label.xml
Template File: sources-sink-84.tmpl.h
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Initialize the source buffer using the size of a pointer
 * Case1Source: Initialize the source buffer using the size of the DataElementType
 * Sinks:
 *    Case0Sink : Print then free data
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"

namespace CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_84
{

#ifndef OMITCASE0

class CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_84_case0
{
public:
    CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_84_case0(twoIntsStruct * dataCopy);
    ~CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_84_case0();

private:
    twoIntsStruct * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_84_case1V1
{
public:
    CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_84_case1V1(twoIntsStruct * dataCopy);
    ~CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_84_case1V1();

private:
    twoIntsStruct * data;
};

#endif /* OMITCASE1 */

}
