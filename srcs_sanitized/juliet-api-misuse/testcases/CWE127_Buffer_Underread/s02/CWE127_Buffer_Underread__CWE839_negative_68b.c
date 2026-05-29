/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__CWE839_negative_68b.c
Label Definition File: CWE127_Buffer_Underread__CWE839.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 127 Buffer Underread
 * Case0Source: negative Negative index value
 * Case1Source: Non-negative but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking to see if the value is negative
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

extern int CWE127_Buffer_Underread__CWE839_negative_68_case0Data;
extern int CWE127_Buffer_Underread__CWE839_negative_68_case1V1Data;
extern int CWE127_Buffer_Underread__CWE839_negative_68_case1V2Data;

#ifndef OMITCASE0

void CWE127_Buffer_Underread__CWE839_negative_68b_case0Sink()
{
    int data = CWE127_Buffer_Underread__CWE839_negative_68_case0Data;
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

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE127_Buffer_Underread__CWE839_negative_68b_case1V1Sink()
{
    int data = CWE127_Buffer_Underread__CWE839_negative_68_case1V1Data;
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

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE127_Buffer_Underread__CWE839_negative_68b_case1V2Sink()
{
    int data = CWE127_Buffer_Underread__CWE839_negative_68_case1V2Data;
    {
        int buffer[10] = { 0 };
        /* ALT: Properly validate the array index and prevent a buffer underread */
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
