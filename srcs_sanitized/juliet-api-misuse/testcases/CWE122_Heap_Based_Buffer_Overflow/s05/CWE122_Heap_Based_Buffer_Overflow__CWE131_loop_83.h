/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_83.h
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__CWE131.label.xml
Template File: sources-sink-83.tmpl.h
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate memory without using sizeof(int)
 * Case1Source: Allocate memory using sizeof(int)
 * Sinks: loop
 *    Case0Sink : Copy array to data using a loop
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"

namespace CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_83
{

#ifndef OMITCASE0

class CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_83_case0
{
public:
    CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_83_case0(int * dataCopy);
    ~CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_83_case0();

private:
    int * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_83_case1V1
{
public:
    CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_83_case1V1(int * dataCopy);
    ~CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_83_case1V1();

private:
    int * data;
};

#endif /* OMITCASE1 */

}
