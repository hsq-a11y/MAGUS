/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__CWE839_negative_83.h
Label Definition File: CWE127_Buffer_Underread__CWE839.label.xml
Template File: sources-sinks-83.tmpl.h
*/
/*
 * @description
 * CWE: 127 Buffer Underread
 * Case0Source: negative Negative index value
 * Case1Source: Non-negative but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking to see if the value is negative
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"

namespace CWE127_Buffer_Underread__CWE839_negative_83
{

#ifndef OMITCASE0

class CWE127_Buffer_Underread__CWE839_negative_83_case0
{
public:
    CWE127_Buffer_Underread__CWE839_negative_83_case0(int dataCopy);
    ~CWE127_Buffer_Underread__CWE839_negative_83_case0();

private:
    int data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE127_Buffer_Underread__CWE839_negative_83_case1V1
{
public:
    CWE127_Buffer_Underread__CWE839_negative_83_case1V1(int dataCopy);
    ~CWE127_Buffer_Underread__CWE839_negative_83_case1V1();

private:
    int data;
};

class CWE127_Buffer_Underread__CWE839_negative_83_case1V2
{
public:
    CWE127_Buffer_Underread__CWE839_negative_83_case1V2(int dataCopy);
    ~CWE127_Buffer_Underread__CWE839_negative_83_case1V2();

private:
    int data;
};

#endif /* OMITCASE1 */

}
