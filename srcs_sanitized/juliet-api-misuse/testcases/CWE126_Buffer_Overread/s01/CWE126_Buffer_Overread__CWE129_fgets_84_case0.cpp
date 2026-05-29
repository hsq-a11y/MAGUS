/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__CWE129_fgets_84_case0.cpp
Label Definition File: CWE126_Buffer_Overread__CWE129.label.xml
Template File: sources-sinks-84_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 126 Buffer Overread
 * Case0Source: fgets Read data from the console using fgets()
 * Case1Source: Larger than zero but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE126_Buffer_Overread__CWE129_fgets_84.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)

namespace CWE126_Buffer_Overread__CWE129_fgets_84
{
CWE126_Buffer_Overread__CWE129_fgets_84_case0::CWE126_Buffer_Overread__CWE129_fgets_84_case0(int dataCopy)
{
    data = dataCopy;
    {
        char inputBuffer[CHAR_ARRAY_SIZE] = "";
        /* NOTE: Read data from the console using fgets() */
        if (fgets(inputBuffer, CHAR_ARRAY_SIZE, stdin) != NULL)
        {
            /* Convert to int */
            data = atoi(inputBuffer);
        }
        else
        {
            printLine("fgets() failed.");
        }
    }
}

CWE126_Buffer_Overread__CWE129_fgets_84_case0::~CWE126_Buffer_Overread__CWE129_fgets_84_case0()
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
#endif /* OMITCASE0 */
