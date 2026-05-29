/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__CWE129_large_81_case1V1.cpp
Label Definition File: CWE126_Buffer_Overread__CWE129.label.xml
Template File: sources-sinks-81_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 126 Buffer Overread
 * Case0Source: large Large index value that is greater than 10-1
 * Case1Source: Larger than zero but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE126_Buffer_Overread__CWE129_large_81.h"

namespace CWE126_Buffer_Overread__CWE129_large_81
{

void CWE126_Buffer_Overread__CWE129_large_81_case1V1::action(int data) const
{
    {
        int buffer[10] = { 0 };
        /* NOTE: Attempt to access an index of the array that is above the upper bound
         * This check does not check the upper bounds of the array index */
        if (data >= 0)
        {
            printIntLine(buffer[data]);
        }
        else
        {
            printLine("ERROR: Array index is negative");
        }
    }
}

}
#endif /* OMITCASE1 */
