/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_class_loop_82.h
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805.label.xml
Template File: sources-sink-82.tmpl.h
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate using new[] and set data pointer to a small buffer
 * Case1Source: Allocate using new[] and set data pointer to a large buffer
 * Sinks: loop
 *    Case0Sink : Copy TwoIntsClass array to data using a loop
 * Flow Variant: 82 Data flow: data passed in a parameter to a virtual method called via a pointer
 *
 * */

#include "std_testcase.h"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_class_loop_82
{

class CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_class_loop_82_base
{
public:
    /* pure virtual function */
    virtual void action(TwoIntsClass * data) = 0;
};

#ifndef OMITCASE0

class CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_class_loop_82_case0 : public CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_class_loop_82_base
{
public:
    void action(TwoIntsClass * data);
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_class_loop_82_case1V1 : public CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_class_loop_82_base
{
public:
    void action(TwoIntsClass * data);
};

#endif /* OMITCASE1 */

}
