/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__CWE839_negative_84_case0.cpp
Label Definition File: CWE124_Buffer_Underwrite__CWE839.label.xml
Template File: sources-sinks-84_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * Case0Source: negative Negative index value
 * Case1Source: Non-negative but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking the lower bound
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE124_Buffer_Underwrite__CWE839_negative_84.h"

namespace CWE124_Buffer_Underwrite__CWE839_negative_84
{
CWE124_Buffer_Underwrite__CWE839_negative_84_case0::CWE124_Buffer_Underwrite__CWE839_negative_84_case0(int dataCopy)
{
    data = dataCopy;
    /* NOTE: Use an invalid index */
    data = -5;
}

CWE124_Buffer_Underwrite__CWE839_negative_84_case0::~CWE124_Buffer_Underwrite__CWE839_negative_84_case0()
{
    {
        int i;
        int buffer[10] = { 0 };
        /* NOTE: Attempt to access a negative index of the array
        * This code does not check to see if the array index is negative */
        if (data < 10)
        {
            buffer[data] = 1;
            /* Print the array values */
            for(i = 0; i < 10; i++)
            {
                printIntLine(buffer[i]);
            }
        }
        else
        {
            printLine("ERROR: Array index is negative.");
        }
    }
}
}
#endif /* OMITCASE0 */
