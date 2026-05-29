/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_connect_socket_52b.c
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__malloc.label.xml
Template File: sources-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * Case0Source: connect_socket Read data using a connect socket (client side)
 * Case1Source: Small number greater than zero
 * Sinks:
 *    Case1Sink: Allocate memory with malloc() and check the size of the memory to be allocated
 *    Case0Sink : Allocate memory with malloc(), but incorrectly check the size of the memory to be allocated
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
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

#define HELLO_STRING L"hello"

#ifndef OMITCASE0

/* case0 function declaration */
void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_connect_socket_52c_case0Sink(size_t data);

void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_connect_socket_52b_case0Sink(size_t data)
{
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_connect_socket_52c_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_connect_socket_52c_case1V1Sink(size_t data);

void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_connect_socket_52b_case1V1Sink(size_t data)
{
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_connect_socket_52c_case1V1Sink(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_connect_socket_52c_case1V2Sink(size_t data);

void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_connect_socket_52b_case1V2Sink(size_t data)
{
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_connect_socket_52c_case1V2Sink(data);
}

#endif /* OMITCASE1 */
