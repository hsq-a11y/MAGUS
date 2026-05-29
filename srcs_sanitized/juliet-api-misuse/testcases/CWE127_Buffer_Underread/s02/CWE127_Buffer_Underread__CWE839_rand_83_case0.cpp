/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__CWE839_rand_83_case0.cpp
Label Definition File: CWE127_Buffer_Underread__CWE839.label.xml
Template File: sources-sinks-83_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 127 Buffer Underread
 * Case0Source: rand Set data to result of rand(), which may be zero
 * Case1Source: Non-negative but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking to see if the value is negative
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE127_Buffer_Underread__CWE839_rand_83.h"

namespace CWE127_Buffer_Underread__CWE839_rand_83
{
CWE127_Buffer_Underread__CWE839_rand_83_case0::CWE127_Buffer_Underread__CWE839_rand_83_case0(int dataCopy)
{
    data = dataCopy;
    /* NOTE: Set data to a random value */
    data = RAND32();
}

CWE127_Buffer_Underread__CWE839_rand_83_case0::~CWE127_Buffer_Underread__CWE839_rand_83_case0()
{
    {
        int buffer[10] = { 0 };
        /* NOTE: Attempt to access a negative index of the array
         * This check does not check to see if the array index is negative */
        if (data < 10)
        {
            printIntLine(buffer[data]);
        }
        else
        {
            printLine("ERROR: Array index is too big.");
        }
    }
}
}
#endif /* OMITCASE0 */
