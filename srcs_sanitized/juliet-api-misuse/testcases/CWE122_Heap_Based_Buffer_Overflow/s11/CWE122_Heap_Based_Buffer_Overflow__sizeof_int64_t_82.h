/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_82.h
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__sizeof.label.xml
Template File: sources-sink-82.tmpl.h
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Initialize the source buffer using the size of a pointer
 * Case1Source: Initialize the source buffer using the size of the DataElementType
 *    Case0Sink : Print then free data
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"

namespace CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_82
{

class CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_82_base
{
public:
    /* pure virtual function */
    virtual void action(int64_t * data) = 0;
};

#ifndef OMITCASE0

class CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_82_case0 : public CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_82_base
{
public:
    void action(int64_t * data);
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_82_case1V1 : public CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_82_base
{
public:
    void action(int64_t * data);
};

#endif /* OMITCASE1 */

}
