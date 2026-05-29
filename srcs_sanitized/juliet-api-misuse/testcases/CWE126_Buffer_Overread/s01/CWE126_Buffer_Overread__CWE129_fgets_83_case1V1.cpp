/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__CWE129_fgets_83_case1V1.cpp
Label Definition File: CWE126_Buffer_Overread__CWE129.label.xml
Template File: sources-sinks-83_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 126 Buffer Overread
 * Case0Source: fgets Read data from the console using fgets()
 * Case1Source: Larger than zero but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE126_Buffer_Overread__CWE129_fgets_83.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)

namespace CWE126_Buffer_Overread__CWE129_fgets_83
{
CWE126_Buffer_Overread__CWE129_fgets_83_case1V1::CWE126_Buffer_Overread__CWE129_fgets_83_case1V1(int dataCopy)
{
    data = dataCopy;
    /* ALT: Use a value greater than 0, but less than 10 to avoid attempting to
     * access an index of the array in the sink that is out-of-bounds */
    data = 7;
}

CWE126_Buffer_Overread__CWE129_fgets_83_case1V1::~CWE126_Buffer_Overread__CWE129_fgets_83_case1V1()
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
