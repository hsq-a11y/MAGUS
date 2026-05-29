/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__CWE839_fscanf_68b.c
Label Definition File: CWE124_Buffer_Underwrite__CWE839.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * Case0Source: fscanf Read data from the console using fscanf()
 * Case1Source: Non-negative but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking the lower bound
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

extern int CWE124_Buffer_Underwrite__CWE839_fscanf_68_case0Data;
extern int CWE124_Buffer_Underwrite__CWE839_fscanf_68_case1V1Data;
extern int CWE124_Buffer_Underwrite__CWE839_fscanf_68_case1V2Data;

#ifndef OMITCASE0

void CWE124_Buffer_Underwrite__CWE839_fscanf_68b_case0Sink()
{
    int data = CWE124_Buffer_Underwrite__CWE839_fscanf_68_case0Data;
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

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE124_Buffer_Underwrite__CWE839_fscanf_68b_case1V1Sink()
{
    int data = CWE124_Buffer_Underwrite__CWE839_fscanf_68_case1V1Data;
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

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE124_Buffer_Underwrite__CWE839_fscanf_68b_case1V2Sink()
{
    int data = CWE124_Buffer_Underwrite__CWE839_fscanf_68_case1V2Data;
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

#endif /* OMITCASE1 */
