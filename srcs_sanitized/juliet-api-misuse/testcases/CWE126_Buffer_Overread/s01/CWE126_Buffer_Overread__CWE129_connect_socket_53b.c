/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__CWE129_connect_socket_53b.c
Label Definition File: CWE126_Buffer_Overread__CWE129.label.xml
Template File: sources-sinks-53b.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Overread
 * Case0Source: connect_socket Read data using a connect socket (client side)
 * Case1Source: Larger than zero but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
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

#ifndef OMITCASE0

/* case0 function declaration */
void CWE126_Buffer_Overread__CWE129_connect_socket_53c_case0Sink(int data);

void CWE126_Buffer_Overread__CWE129_connect_socket_53b_case0Sink(int data)
{
    CWE126_Buffer_Overread__CWE129_connect_socket_53c_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE126_Buffer_Overread__CWE129_connect_socket_53c_case1V1Sink(int data);

void CWE126_Buffer_Overread__CWE129_connect_socket_53b_case1V1Sink(int data)
{
    CWE126_Buffer_Overread__CWE129_connect_socket_53c_case1V1Sink(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE126_Buffer_Overread__CWE129_connect_socket_53c_case1V2Sink(int data);

void CWE126_Buffer_Overread__CWE129_connect_socket_53b_case1V2Sink(int data)
{
    CWE126_Buffer_Overread__CWE129_connect_socket_53c_case1V2Sink(data);
}

#endif /* OMITCASE1 */
