/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__CWE839_connect_socket_22b.c
Label Definition File: CWE124_Buffer_Underwrite__CWE839.label.xml
Template File: sources-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * Case0Source: connect_socket Read data using a connect socket (client side)
 * Case1Source: Non-negative but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking the lower bound
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the sink function */
extern int CWE124_Buffer_Underwrite__CWE839_connect_socket_22_case0Global;

void CWE124_Buffer_Underwrite__CWE839_connect_socket_22_case0Sink(int data)
{
    if(CWE124_Buffer_Underwrite__CWE839_connect_socket_22_case0Global)
    {
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
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the sink functions. */
extern int CWE124_Buffer_Underwrite__CWE839_connect_socket_22_case1V21Global;
extern int CWE124_Buffer_Underwrite__CWE839_connect_socket_22_case1V22Global;
extern int CWE124_Buffer_Underwrite__CWE839_connect_socket_22_case1V1Global;

/* case1V21() - use case0source and case1sink by setting the static variable to false instead of true */
void CWE124_Buffer_Underwrite__CWE839_connect_socket_22_case1V21Sink(int data)
{
    if(CWE124_Buffer_Underwrite__CWE839_connect_socket_22_case1V21Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
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

/* case1V22() - use case0source and case1sink by reversing the blocks in the if in the sink function */
void CWE124_Buffer_Underwrite__CWE839_connect_socket_22_case1V22Sink(int data)
{
    if(CWE124_Buffer_Underwrite__CWE839_connect_socket_22_case1V22Global)
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

/* case1V1() - use case1source and case0sink */
void CWE124_Buffer_Underwrite__CWE839_connect_socket_22_case1V1Sink(int data)
{
    if(CWE124_Buffer_Underwrite__CWE839_connect_socket_22_case1V1Global)
    {
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
}

#endif /* OMITCASE1 */
