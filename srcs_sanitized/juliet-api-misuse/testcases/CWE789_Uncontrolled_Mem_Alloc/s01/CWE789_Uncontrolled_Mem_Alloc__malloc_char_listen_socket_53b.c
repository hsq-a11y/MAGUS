/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__malloc_char_listen_socket_53b.c
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__malloc.label.xml
Template File: sources-sinks-53b.tmpl.c
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * Case0Source: listen_socket Read data using a listen socket (server side)
 * Case1Source: Small number greater than zero
 * Sinks:
 *    Case1Sink: Allocate memory with malloc() and check the size of the memory to be allocated
 *    Case0Sink : Allocate memory with malloc(), but incorrectly check the size of the memory to be allocated
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

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

#define HELLO_STRING "hello"

#ifndef OMITCASE0

/* case0 function declaration */
void CWE789_Uncontrolled_Mem_Alloc__malloc_char_listen_socket_53c_case0Sink(size_t data);

void CWE789_Uncontrolled_Mem_Alloc__malloc_char_listen_socket_53b_case0Sink(size_t data)
{
    CWE789_Uncontrolled_Mem_Alloc__malloc_char_listen_socket_53c_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE789_Uncontrolled_Mem_Alloc__malloc_char_listen_socket_53c_case1V1Sink(size_t data);

void CWE789_Uncontrolled_Mem_Alloc__malloc_char_listen_socket_53b_case1V1Sink(size_t data)
{
    CWE789_Uncontrolled_Mem_Alloc__malloc_char_listen_socket_53c_case1V1Sink(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE789_Uncontrolled_Mem_Alloc__malloc_char_listen_socket_53c_case1V2Sink(size_t data);

void CWE789_Uncontrolled_Mem_Alloc__malloc_char_listen_socket_53b_case1V2Sink(size_t data)
{
    CWE789_Uncontrolled_Mem_Alloc__malloc_char_listen_socket_53c_case1V2Sink(data);
}

#endif /* OMITCASE1 */
