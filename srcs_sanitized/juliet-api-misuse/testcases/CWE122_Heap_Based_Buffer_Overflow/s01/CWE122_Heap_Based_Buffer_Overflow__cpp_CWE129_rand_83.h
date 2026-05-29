/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_rand_83.h
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129.label.xml
Template File: sources-sinks-83.tmpl.h
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source: rand Set data to result of rand(), which may be zero
 * Case1Source: Larger than zero but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_rand_83
{

#ifndef OMITCASE0

class CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_rand_83_case0
{
public:
    CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_rand_83_case0(int dataCopy);
    ~CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_rand_83_case0();

private:
    int data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_rand_83_case1V1
{
public:
    CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_rand_83_case1V1(int dataCopy);
    ~CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_rand_83_case1V1();

private:
    int data;
};

class CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_rand_83_case1V2
{
public:
    CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_rand_83_case1V2(int dataCopy);
    ~CWE122_Heap_Based_Buffer_Overflow__cpp_CWE129_rand_83_case1V2();

private:
    int data;
};

#endif /* OMITCASE1 */

}
