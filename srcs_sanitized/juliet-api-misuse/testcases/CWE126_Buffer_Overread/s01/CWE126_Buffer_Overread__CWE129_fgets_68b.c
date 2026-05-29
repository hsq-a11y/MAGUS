/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__CWE129_fgets_68b.c
Label Definition File: CWE126_Buffer_Overread__CWE129.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Overread
 * Case0Source: fgets Read data from the console using fgets()
 * Case1Source: Larger than zero but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)

extern int CWE126_Buffer_Overread__CWE129_fgets_68_case0Data;
extern int CWE126_Buffer_Overread__CWE129_fgets_68_case1V1Data;
extern int CWE126_Buffer_Overread__CWE129_fgets_68_case1V2Data;

#ifndef OMITCASE0

void CWE126_Buffer_Overread__CWE129_fgets_68b_case0Sink()
{
    int data = CWE126_Buffer_Overread__CWE129_fgets_68_case0Data;
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
void CWE126_Buffer_Overread__CWE129_fgets_68b_case1V1Sink()
{
    int data = CWE126_Buffer_Overread__CWE129_fgets_68_case1V1Data;
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
void CWE126_Buffer_Overread__CWE129_fgets_68b_case1V2Sink()
{
    int data = CWE126_Buffer_Overread__CWE129_fgets_68_case1V2Data;
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
