/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_connect_socket_vfprintf_53b.c
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-53b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: connect_socket Read data using a connect socket (client side)
 * Case1Source: Copy a fixed string into data
 * Sinks: vfprintf
 *    Case1Sink: vfwprintf with a format string
 *    Case0Sink : vfwprintf without a format string
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include <stdarg.h>
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

#ifndef OMITCASE0

/* case0 function declaration */
void CWE134_Uncontrolled_Format_String__wchar_t_connect_socket_vfprintf_53c_case0Sink(wchar_t * data);

void CWE134_Uncontrolled_Format_String__wchar_t_connect_socket_vfprintf_53b_case0Sink(wchar_t * data)
{
    CWE134_Uncontrolled_Format_String__wchar_t_connect_socket_vfprintf_53c_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE134_Uncontrolled_Format_String__wchar_t_connect_socket_vfprintf_53c_case1V1Sink(wchar_t * data);

void CWE134_Uncontrolled_Format_String__wchar_t_connect_socket_vfprintf_53b_case1V1Sink(wchar_t * data)
{
    CWE134_Uncontrolled_Format_String__wchar_t_connect_socket_vfprintf_53c_case1V1Sink(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE134_Uncontrolled_Format_String__wchar_t_connect_socket_vfprintf_53c_case1V2Sink(wchar_t * data);

void CWE134_Uncontrolled_Format_String__wchar_t_connect_socket_vfprintf_53b_case1V2Sink(wchar_t * data)
{
    CWE134_Uncontrolled_Format_String__wchar_t_connect_socket_vfprintf_53c_case1V2Sink(data);
}

#endif /* OMITCASE1 */
