/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__CWE839_rand_84.h
Label Definition File: CWE124_Buffer_Underwrite__CWE839.label.xml
Template File: sources-sinks-84.tmpl.h
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * Case0Source: rand Set data to result of rand(), which may be zero
 * Case1Source: Non-negative but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking the lower bound
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"

namespace CWE124_Buffer_Underwrite__CWE839_rand_84
{

#ifndef OMITCASE0

class CWE124_Buffer_Underwrite__CWE839_rand_84_case0
{
public:
    CWE124_Buffer_Underwrite__CWE839_rand_84_case0(int dataCopy);
    ~CWE124_Buffer_Underwrite__CWE839_rand_84_case0();

private:
    int data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE124_Buffer_Underwrite__CWE839_rand_84_case1V1
{
public:
    CWE124_Buffer_Underwrite__CWE839_rand_84_case1V1(int dataCopy);
    ~CWE124_Buffer_Underwrite__CWE839_rand_84_case1V1();

private:
    int data;
};

class CWE124_Buffer_Underwrite__CWE839_rand_84_case1V2
{
public:
    CWE124_Buffer_Underwrite__CWE839_rand_84_case1V2(int dataCopy);
    ~CWE124_Buffer_Underwrite__CWE839_rand_84_case1V2();

private:
    int data;
};

#endif /* OMITCASE1 */

}
