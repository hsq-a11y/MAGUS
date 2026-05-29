/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__CWE839_rand_83_case1V2.cpp
Label Definition File: CWE124_Buffer_Underwrite__CWE839.label.xml
Template File: sources-sinks-83_case1V2.tmpl.cpp
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * Case0Source: rand Set data to result of rand(), which may be zero
 * Case1Source: Non-negative but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking the lower bound
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE124_Buffer_Underwrite__CWE839_rand_83.h"

namespace CWE124_Buffer_Underwrite__CWE839_rand_83
{
CWE124_Buffer_Underwrite__CWE839_rand_83_case1V2::CWE124_Buffer_Underwrite__CWE839_rand_83_case1V2(int dataCopy)
{
    data = dataCopy;
    /* NOTE: Set data to a random value */
    data = RAND32();
}

CWE124_Buffer_Underwrite__CWE839_rand_83_case1V2::~CWE124_Buffer_Underwrite__CWE839_rand_83_case1V2()
{
    {
        int i;
        int buffer[10] = { 0 };
        /* ALT: Properly validate the array index and prevent a buffer underwrite */
        if (data >= 0 && data < (10))
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
            printLine("ERROR: Array index is out-of-bounds");
        }
    }
}
}
#endif /* OMITCASE1 */
