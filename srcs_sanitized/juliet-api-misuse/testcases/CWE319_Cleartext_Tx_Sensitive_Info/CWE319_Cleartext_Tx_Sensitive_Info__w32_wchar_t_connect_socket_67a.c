/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_67a.c
Label Definition File: CWE319_Cleartext_Tx_Sensitive_Info__w32.label.xml
Template File: sources-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 319 Cleartext Transmission of Sensitive Information
 * Case0Source: connect_socket Read the password using a connect socket (client side)
 * Case1Source: Use a hardcoded password (one that was not sent over the network)
 * Sinks:
 *    Case1Sink: Decrypt the password before using it in an authentication API call to show that it was transferred as ciphertext
 *    Case0Sink : Use the password directly from the source in an authentication API call to show that it was transferred as plaintext
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <winsock2.h>
#include <windows.h>
#include <direct.h>
#pragma comment(lib, "ws2_32") /* include ws2_32.lib when linking */

#define TCP_PORT 27015
#define IP_ADDRESS "127.0.0.1"

#pragma comment(lib, "advapi32.lib")

#define HASH_INPUT "ABCDEFG123456" /* INCIDENTAL: Hardcoded crypto */

typedef struct _CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_67_structType
{
    wchar_t * structFirst;
} CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_67_structType;

#ifndef OMITCASE0

/* case0 function declaration */
void CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_67b_case0Sink(CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_67_structType myStruct);

void CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_67_case0()
{
    wchar_t * password;
    CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_67_structType myStruct;
    wchar_t passwordBuffer[100] = L"";
    password = passwordBuffer;
    {
        WSADATA wsaData;
        int wsaDataInit = 0;
        int recvResult;
        struct sockaddr_in service;
        wchar_t *replace;
        SOCKET connectSocket = INVALID_SOCKET;
        size_t passwordLen = wcslen(password);
        do
        {
            if (WSAStartup(MAKEWORD(2,2), &wsaData) != NO_ERROR)
            {
                break;
            }
            wsaDataInit = 1;
            connectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            if (connectSocket == INVALID_SOCKET)
            {
                break;
            }
            memset(&service, 0, sizeof(service));
            service.sin_family = AF_INET;
            service.sin_addr.s_addr = inet_addr(IP_ADDRESS);
            service.sin_port = htons(TCP_PORT);
            if (connect(connectSocket, (struct sockaddr*)&service, sizeof(service)) == SOCKET_ERROR)
            {
                break;
            }
            /* Abort on error or the connection was closed, make sure to recv one
             * less char than is in the recv_buf in order to append a terminator */
            /* NOTE: Reading sensitive data from the network */
            recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(wchar_t), 0);
            if (recvResult == SOCKET_ERROR || recvResult == 0)
            {
                break;
            }
            /* Append null terminator */
            password[passwordLen + recvResult / sizeof(wchar_t)] = L'\0';
            /* Eliminate CRLF */
            replace = wcschr(password, L'\r');
            if (replace)
            {
                *replace = L'\0';
            }
            replace = wcschr(password, L'\n');
            if (replace)
            {
                *replace = L'\0';
            }
        }
        while (0);
        if (connectSocket != INVALID_SOCKET)
        {
            closesocket(connectSocket);
        }
        if (wsaDataInit)
        {
            WSACleanup();
        }
    }
    myStruct.structFirst = password;
    CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_67b_case0Sink(myStruct);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_67b_case1V1Sink(CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_67_structType myStruct);

static void case1V1()
{
    wchar_t * password;
    CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_67_structType myStruct;
    wchar_t passwordBuffer[100] = L"";
    password = passwordBuffer;
    /* ALT: Use a hardcoded password (it was not sent over the network)
    * INCIDENTAL NOTE: CWE-259 Hard Coded Password */
    wcscpy(password, L"Password1234!");
    myStruct.structFirst = password;
    CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_67b_case1V1Sink(myStruct);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_67b_case1V2Sink(CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_67_structType myStruct);

static void case1V2()
{
    wchar_t * password;
    CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_67_structType myStruct;
    wchar_t passwordBuffer[100] = L"";
    password = passwordBuffer;
    {
        WSADATA wsaData;
        int wsaDataInit = 0;
        int recvResult;
        struct sockaddr_in service;
        wchar_t *replace;
        SOCKET connectSocket = INVALID_SOCKET;
        size_t passwordLen = wcslen(password);
        do
        {
            if (WSAStartup(MAKEWORD(2,2), &wsaData) != NO_ERROR)
            {
                break;
            }
            wsaDataInit = 1;
            connectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            if (connectSocket == INVALID_SOCKET)
            {
                break;
            }
            memset(&service, 0, sizeof(service));
            service.sin_family = AF_INET;
            service.sin_addr.s_addr = inet_addr(IP_ADDRESS);
            service.sin_port = htons(TCP_PORT);
            if (connect(connectSocket, (struct sockaddr*)&service, sizeof(service)) == SOCKET_ERROR)
            {
                break;
            }
            /* Abort on error or the connection was closed, make sure to recv one
             * less char than is in the recv_buf in order to append a terminator */
            /* NOTE: Reading sensitive data from the network */
            recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(wchar_t), 0);
            if (recvResult == SOCKET_ERROR || recvResult == 0)
            {
                break;
            }
            /* Append null terminator */
            password[passwordLen + recvResult / sizeof(wchar_t)] = L'\0';
            /* Eliminate CRLF */
            replace = wcschr(password, L'\r');
            if (replace)
            {
                *replace = L'\0';
            }
            replace = wcschr(password, L'\n');
            if (replace)
            {
                *replace = L'\0';
            }
        }
        while (0);
        if (connectSocket != INVALID_SOCKET)
        {
            closesocket(connectSocket);
        }
        if (wsaDataInit)
        {
            WSACleanup();
        }
    }
    myStruct.structFirst = password;
    CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_67b_case1V2Sink(myStruct);
}

void CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_67_case1()
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
    CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_67_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_67_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
