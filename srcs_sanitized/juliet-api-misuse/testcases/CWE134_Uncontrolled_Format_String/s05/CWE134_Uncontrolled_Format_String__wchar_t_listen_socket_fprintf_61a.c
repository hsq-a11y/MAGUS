/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_fprintf_61a.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-61a.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * Case0Source: listen_socket Read data using a listen socket (server side)
 * Case1Source: Copy a fixed string into data
 * Sinks: fprintf
 *    Case1Sink: fwprintf with "%s" as the second argument and data as the third
 *    Case0Sink : fwprintf with data as the second argument
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
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

#ifndef OMITCASE0

/* case0 function declaration */
wchar_t * CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_fprintf_61b_case0Source(wchar_t * data);

void CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_fprintf_61_case0()
{
    wchar_t * data;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    data = CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_fprintf_61b_case0Source(data);
    /* NOTE: Do not specify the format allowing a possible format string vulnerability */
    fwprintf(stdout, data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
wchar_t * CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_fprintf_61b_case1V1Source(wchar_t * data);

static void case1V1()
{
    wchar_t * data;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    data = CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_fprintf_61b_case1V1Source(data);
    /* NOTE: Do not specify the format allowing a possible format string vulnerability */
    fwprintf(stdout, data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
wchar_t * CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_fprintf_61b_case1V2Source(wchar_t * data);

static void case1V2()
{
    wchar_t * data;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    data = CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_fprintf_61b_case1V2Source(data);
    /* ALT: Specify the format disallowing a format string vulnerability */
    fwprintf(stdout, L"%s\n", data);
}

void CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_fprintf_61_case1()
{
    case1V1();
    case1V2();
}

#endif /* OMITCASE1 */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITCASE1
    printLine("Calling case1()...");
    CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_fprintf_61_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_fprintf_61_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
