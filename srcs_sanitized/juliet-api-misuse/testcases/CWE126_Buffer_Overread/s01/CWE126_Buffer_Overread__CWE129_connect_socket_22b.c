/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__CWE129_connect_socket_22b.c
Label Definition File: CWE126_Buffer_Overread__CWE129.label.xml
Template File: sources-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Overread
 * Case0Source: connect_socket Read data using a connect socket (client side)
 * Case1Source: Larger than zero but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the sink function */
extern int CWE126_Buffer_Overread__CWE129_connect_socket_22_case0Global;

void CWE126_Buffer_Overread__CWE129_connect_socket_22_case0Sink(int data)
{
    if(CWE126_Buffer_Overread__CWE129_connect_socket_22_case0Global)
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

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the sink functions. */
extern int CWE126_Buffer_Overread__CWE129_connect_socket_22_case1V21Global;
extern int CWE126_Buffer_Overread__CWE129_connect_socket_22_case1V22Global;
extern int CWE126_Buffer_Overread__CWE129_connect_socket_22_case1V1Global;

/* case1V21() - use case0source and case1sink by setting the static variable to false instead of true */
void CWE126_Buffer_Overread__CWE129_connect_socket_22_case1V21Sink(int data)
{
    if(CWE126_Buffer_Overread__CWE129_connect_socket_22_case1V21Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
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
}

/* case1V22() - use case0source and case1sink by reversing the blocks in the if in the sink function */
void CWE126_Buffer_Overread__CWE129_connect_socket_22_case1V22Sink(int data)
{
    if(CWE126_Buffer_Overread__CWE129_connect_socket_22_case1V22Global)
    {
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
}

/* case1V1() - use case1source and case0sink */
void CWE126_Buffer_Overread__CWE129_connect_socket_22_case1V1Sink(int data)
{
    if(CWE126_Buffer_Overread__CWE129_connect_socket_22_case1V1Global)
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
