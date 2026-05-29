/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__CWE839_connect_socket_68b.c
Label Definition File: CWE124_Buffer_Underwrite__CWE839.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * Case0Source: connect_socket Read data using a connect socket (client side)
 * Case1Source: Non-negative but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking the lower bound
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#include <winsock2.h>
#include <windows.h>
#include <direct.h>
#pragma comment(lib, "ws2_32") /* include ws2_32.lib when linking */
#define CLOSE_SOCKET closesocket
#else /* NOT _WIN32 */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define CLOSE_SOCKET close
#define SOCKET int
#endif

#define TCP_PORT 27015
#define IP_ADDRESS "127.0.0.1"
#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)

extern int CWE124_Buffer_Underwrite__CWE839_connect_socket_68_case0Data;
extern int CWE124_Buffer_Underwrite__CWE839_connect_socket_68_case1V1Data;
extern int CWE124_Buffer_Underwrite__CWE839_connect_socket_68_case1V2Data;

#ifndef OMITCASE0

void CWE124_Buffer_Underwrite__CWE839_connect_socket_68b_case0Sink()
{
    int data = CWE124_Buffer_Underwrite__CWE839_connect_socket_68_case0Data;
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
void CWE124_Buffer_Underwrite__CWE839_connect_socket_68b_case1V1Sink()
{
    int data = CWE124_Buffer_Underwrite__CWE839_connect_socket_68_case1V1Data;
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
void CWE124_Buffer_Underwrite__CWE839_connect_socket_68b_case1V2Sink()
{
    int data = CWE124_Buffer_Underwrite__CWE839_connect_socket_68_case1V2Data;
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
