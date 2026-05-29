/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__CWE839_rand_81.h
Label Definition File: CWE124_Buffer_Underwrite__CWE839.label.xml
Template File: sources-sinks-81.tmpl.h
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * Case0Source: rand Set data to result of rand(), which may be zero
 * Case1Source: Non-negative but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking the lower bound
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"

namespace CWE124_Buffer_Underwrite__CWE839_rand_81
{

class CWE124_Buffer_Underwrite__CWE839_rand_81_base
{
public:
    /* pure virtual function */
    virtual void action(int data) const = 0;
};

#ifndef OMITCASE0

class CWE124_Buffer_Underwrite__CWE839_rand_81_case0 : public CWE124_Buffer_Underwrite__CWE839_rand_81_base
{
public:
    void action(int data) const;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE124_Buffer_Underwrite__CWE839_rand_81_case1V1 : public CWE124_Buffer_Underwrite__CWE839_rand_81_base
{
public:
    void action(int data) const;
};

class CWE124_Buffer_Underwrite__CWE839_rand_81_case1V2 : public CWE124_Buffer_Underwrite__CWE839_rand_81_base
{
public:
    void action(int data) const;
};

#endif /* OMITCASE1 */

}
