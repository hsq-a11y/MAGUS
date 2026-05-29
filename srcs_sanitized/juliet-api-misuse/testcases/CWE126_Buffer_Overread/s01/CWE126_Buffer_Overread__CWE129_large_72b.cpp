/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__CWE129_large_72b.cpp
Label Definition File: CWE126_Buffer_Overread__CWE129.label.xml
Template File: sources-sinks-72b.tmpl.cpp
*/
/*
 * @description
 * CWE: 126 Buffer Overread
 * Case0Source: large Large index value that is greater than 10-1
 * Case1Source: Larger than zero but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 72 Data flow: data passed in a vector from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <vector>

using namespace std;

namespace CWE126_Buffer_Overread__CWE129_large_72
{

#ifndef OMITCASE0

void case0Sink(vector<int> dataVector)
{
    /* copy data out of dataVector */
    int data = dataVector[2];
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

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink(vector<int> dataVector)
{
    int data = dataVector[2];
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

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Sink(vector<int> dataVector)
{
    int data = dataVector[2];
    {
        int buffer[10] = { 0 };
        /* ALT: Properly validate the array index and prevent a buffer overread */
        if (data >= 0 && data < (10))
        {
            printIntLine(buffer[data]);
        }
        else
        {
            printLine("ERROR: Array index is out-of-bounds");
        }
    }
}

#endif /* OMITCASE1 */

} /* close namespace */
