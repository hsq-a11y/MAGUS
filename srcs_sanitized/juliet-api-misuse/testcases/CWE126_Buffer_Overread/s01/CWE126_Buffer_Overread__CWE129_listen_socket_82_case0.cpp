/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__CWE129_listen_socket_82_case0.cpp
Label Definition File: CWE126_Buffer_Overread__CWE129.label.xml
Template File: sources-sinks-82_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 126 Buffer Overread
 * Case0Source: listen_socket Read data using a listen socket (server side)
 * Case1Source: Larger than zero but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE126_Buffer_Overread__CWE129_listen_socket_82.h"

namespace CWE126_Buffer_Overread__CWE129_listen_socket_82
{

void CWE126_Buffer_Overread__CWE129_listen_socket_82_case0::action(int data)
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
