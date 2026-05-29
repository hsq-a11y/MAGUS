/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_fprintf_68b.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: listen_socket Read data using a listen socket (server side)
 * Case1Source: Copy a fixed string into data
 * Sinks: fprintf
 *    Case1Sink: fwprintf with "%s" as the second argument and data as the third
 *    Case0Sink : fwprintf with data as the second argument
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
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

extern wchar_t * CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_fprintf_68_case0Data;
extern wchar_t * CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_fprintf_68_case1V1Data;
extern wchar_t * CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_fprintf_68_case1V2Data;

#ifndef OMITCASE0

void CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_fprintf_68b_case0Sink()
{
    wchar_t * data = CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_fprintf_68_case0Data;
    /* NOTE: Do not specify the format allowing a possible format string vulnerability */
    fwprintf(stdout, data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_fprintf_68b_case1V1Sink()
{
    wchar_t * data = CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_fprintf_68_case1V1Data;
    /* NOTE: Do not specify the format allowing a possible format string vulnerability */
    fwprintf(stdout, data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_fprintf_68b_case1V2Sink()
{
    wchar_t * data = CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_fprintf_68_case1V2Data;
    /* ALT: Specify the format disallowing a format string vulnerability */
    fwprintf(stdout, L"%s\n", data);
}

#endif /* OMITCASE1 */
