/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__CWE839_listen_socket_53c.c
Label Definition File: CWE127_Buffer_Underread__CWE839.label.xml
Template File: sources-sinks-53c.tmpl.c
*/
/*
 * @description
 * CWE: 127 Buffer Underread
 * Case0Source: listen_socket Read data using a listen socket (server side)
 * Case1Source: Non-negative but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking to see if the value is negative
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
#else
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
#define LISTEN_BACKLOG 5
#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)

#ifndef OMITCASE0

/* case0 function declaration */
void CWE127_Buffer_Underread__CWE839_listen_socket_53d_case0Sink(int data);

void CWE127_Buffer_Underread__CWE839_listen_socket_53c_case0Sink(int data)
{
    CWE127_Buffer_Underread__CWE839_listen_socket_53d_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE127_Buffer_Underread__CWE839_listen_socket_53d_case1V1Sink(int data);

void CWE127_Buffer_Underread__CWE839_listen_socket_53c_case1V1Sink(int data)
{
    CWE127_Buffer_Underread__CWE839_listen_socket_53d_case1V1Sink(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE127_Buffer_Underread__CWE839_listen_socket_53d_case1V2Sink(int data);

void CWE127_Buffer_Underread__CWE839_listen_socket_53c_case1V2Sink(int data)
{
    CWE127_Buffer_Underread__CWE839_listen_socket_53d_case1V2Sink(data);
}

#endif /* OMITCASE1 */
