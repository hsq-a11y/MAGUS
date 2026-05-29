/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__CWE839_connect_socket_81_case1V2.cpp
Label Definition File: CWE124_Buffer_Underwrite__CWE839.label.xml
Template File: sources-sinks-81_case1V2.tmpl.cpp
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * Case0Source: connect_socket Read data using a connect socket (client side)
 * Case1Source: Non-negative but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking the lower bound
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE124_Buffer_Underwrite__CWE839_connect_socket_81.h"

namespace CWE124_Buffer_Underwrite__CWE839_connect_socket_81
{

void CWE124_Buffer_Underwrite__CWE839_connect_socket_81_case1V2::action(int data) const
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
