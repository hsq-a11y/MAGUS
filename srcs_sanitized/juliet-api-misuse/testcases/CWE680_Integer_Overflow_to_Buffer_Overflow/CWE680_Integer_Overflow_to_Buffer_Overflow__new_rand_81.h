/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE680_Integer_Overflow_to_Buffer_Overflow__new_rand_81.h
Label Definition File: CWE680_Integer_Overflow_to_Buffer_Overflow__new.label.xml
Template File: sources-sink-81.tmpl.h
*/
/*
 * @description
 * CWE: 680 Integer Overflow to Buffer Overflow
 * Case0Source: rand Set data to result of rand(), which may be zero
 * Case1Source: Small number greater than zero that will not cause an integer overflow in the sink
 * Sinks:
 *    Case0Sink : Attempt to allocate array using length value from source
 * Flow Variant: 81 Data flow: data passed in a parameter to a virtual method called via a reference
 *
 * */

#include "std_testcase.h"

namespace CWE680_Integer_Overflow_to_Buffer_Overflow__new_rand_81
{

class CWE680_Integer_Overflow_to_Buffer_Overflow__new_rand_81_base
{
public:
    /* pure virtual function */
    virtual void action(int data) const = 0;
};

#ifndef OMITCASE0

class CWE680_Integer_Overflow_to_Buffer_Overflow__new_rand_81_case0 : public CWE680_Integer_Overflow_to_Buffer_Overflow__new_rand_81_base
{
public:
    void action(int data) const;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE680_Integer_Overflow_to_Buffer_Overflow__new_rand_81_case1V1 : public CWE680_Integer_Overflow_to_Buffer_Overflow__new_rand_81_base
{
public:
    void action(int data) const;
};

#endif /* OMITCASE1 */

}
