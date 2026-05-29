/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_connect_socket_snprintf_68b.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: connect_socket Read data using a connect socket (client side)
 * Case1Source: Copy a fixed string into data
 * Sinks: snprintf
 *    Case1Sink: snprintf with "%s" as the third argument and data as the fourth
 *    Case0Sink : snprintf with data as the third argument
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

#ifdef _WIN32
#define SNPRINTF _snprintf
#else
#define SNPRINTF snprintf
#endif

extern char * CWE134_Uncontrolled_Format_String__char_connect_socket_snprintf_68_case0Data;
extern char * CWE134_Uncontrolled_Format_String__char_connect_socket_snprintf_68_case1V1Data;
extern char * CWE134_Uncontrolled_Format_String__char_connect_socket_snprintf_68_case1V2Data;

#ifndef OMITCASE0

void CWE134_Uncontrolled_Format_String__char_connect_socket_snprintf_68b_case0Sink()
{
    char * data = CWE134_Uncontrolled_Format_String__char_connect_socket_snprintf_68_case0Data;
    {
        char dest[100] = "";
        /* NOTE: Do not specify the format allowing a possible format string vulnerability */
        SNPRINTF(dest, 100-1, data);
        printLine(dest);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE134_Uncontrolled_Format_String__char_connect_socket_snprintf_68b_case1V1Sink()
{
    char * data = CWE134_Uncontrolled_Format_String__char_connect_socket_snprintf_68_case1V1Data;
    {
        char dest[100] = "";
        /* NOTE: Do not specify the format allowing a possible format string vulnerability */
        SNPRINTF(dest, 100-1, data);
        printLine(dest);
    }
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE134_Uncontrolled_Format_String__char_connect_socket_snprintf_68b_case1V2Sink()
{
    char * data = CWE134_Uncontrolled_Format_String__char_connect_socket_snprintf_68_case1V2Data;
    {
        char dest[100] = "";
        /* ALT: Specify the format disallowing a format string vulnerability */
        SNPRINTF(dest, 100-1, "%s", data);
        printLine(dest);
    }
}

#endif /* OMITCASE1 */
