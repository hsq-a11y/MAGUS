/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__CWE839_fgets_83_case1V1.cpp
Label Definition File: CWE127_Buffer_Underread__CWE839.label.xml
Template File: sources-sinks-83_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 127 Buffer Underread
 * Case0Source: fgets Read data from the console using fgets()
 * Case1Source: Non-negative but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking to see if the value is negative
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE127_Buffer_Underread__CWE839_fgets_83.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)

namespace CWE127_Buffer_Underread__CWE839_fgets_83
{
CWE127_Buffer_Underread__CWE839_fgets_83_case1V1::CWE127_Buffer_Underread__CWE839_fgets_83_case1V1(int dataCopy)
{
    data = dataCopy;
    /* ALT: Use a value greater than 0, but less than 10 to avoid attempting to
     * access an index of the array in the sink that is out-of-bounds */
    data = 7;
}

CWE127_Buffer_Underread__CWE839_fgets_83_case1V1::~CWE127_Buffer_Underread__CWE839_fgets_83_case1V1()
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
#endif /* OMITCASE1 */
