/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_listen_socket_54d.c
Label Definition File: CWE761_Free_Pointer_Not_at_Start_of_Buffer.label.xml
Template File: source-sinks-54d.tmpl.c
*/
/*
 * @description
 * CWE: 761 Free Pointer not at Start of Buffer
 * Case0Source: listen_socket Read data using a listen socket (server side)
 * Sinks:
 *    Case1Sink: free() memory correctly at the start of the buffer
 *    Case0Sink : free() memory not at the start of the buffer
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

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

#define SEARCH_CHAR 'S'

#ifndef OMITCASE0

/* case0 function declaration */
void CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_listen_socket_54e_case0Sink(char * data);

void CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_listen_socket_54d_case0Sink(char * data)
{
    CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_listen_socket_54e_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_listen_socket_54e_case1V2Sink(char * data);

void CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_listen_socket_54d_case1V2Sink(char * data)
{
    CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_listen_socket_54e_case1V2Sink(data);
}

#endif /* OMITCASE1 */
