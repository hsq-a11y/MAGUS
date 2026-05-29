/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_listen_socket_system_52b.c
Label Definition File: CWE78_OS_Command_Injection.one_string.label.xml
Template File: sources-sink-52b.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * Case0Source: listen_socket Read data using a listen socket (server side)
 * Case1Source: Fixed string
 * Sink: system
 *    Case0Sink : Execute command in data using system()
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define FULL_COMMAND "dir "
#else
#include <unistd.h>
#define FULL_COMMAND "ls "
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
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define CLOSE_SOCKET close
#define SOCKET int
#endif

#define TCP_PORT 27015
#define LISTEN_BACKLOG 5

#ifdef _WIN32
#define SYSTEM system
#else /* NOT _WIN32 */
#define SYSTEM system
#endif

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

/* case0 function declaration */
void CWE78_OS_Command_Injection__char_listen_socket_system_52c_case0Sink(char * data);

void CWE78_OS_Command_Injection__char_listen_socket_system_52b_case0Sink(char * data)
{
    CWE78_OS_Command_Injection__char_listen_socket_system_52c_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declaration */
void CWE78_OS_Command_Injection__char_listen_socket_system_52c_case1V1Sink(char * data);

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE78_OS_Command_Injection__char_listen_socket_system_52b_case1V1Sink(char * data)
{
    CWE78_OS_Command_Injection__char_listen_socket_system_52c_case1V1Sink(data);
}

#endif /* OMITCASE1 */
