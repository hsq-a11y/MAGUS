/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_82.h
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__CWE131.label.xml
Template File: sources-sink-82.tmpl.h
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate memory without using sizeof(int)
 * Case1Source: Allocate memory using sizeof(int)
 *    Case0Sink : Copy array to data using memcpy()
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"

namespace CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_82
{

class CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_82_base
{
public:
    /* pure virtual function */
    virtual void action(int * data) = 0;
};

#ifndef OMITCASE0

class CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_82_case0 : public CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_82_base
{
public:
    void action(int * data);
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_82_case1V1 : public CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_82_base
{
public:
    void action(int * data);
};

#endif /* OMITCASE1 */

}
