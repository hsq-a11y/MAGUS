/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fixed_82.h
Label Definition File: CWE680_Integer_Overflow_to_Buffer_Overflow__malloc.label.xml
Template File: sources-sink-82.tmpl.h
*/
/*
 * @description
 * CWE: 680 Integer Overflow to Buffer Overflow
 * Case0Source: fixed Fixed value that will cause an integer overflow in the sink
 * Case1Source: Small number greater than zero that will not cause an integer overflow in the sink
 *    Case0Sink : Attempt to allocate array using length value from source
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"

namespace CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fixed_82
{

class CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fixed_82_base
{
public:
    /* pure virtual function */
    virtual void action(int data) = 0;
};

#ifndef OMITCASE0

class CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fixed_82_case0 : public CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fixed_82_base
{
public:
    void action(int data);
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fixed_82_case1V1 : public CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fixed_82_base
{
public:
    void action(int data);
};

#endif /* OMITCASE1 */

}
