/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_54d.c
Label Definition File: CWE319_Cleartext_Tx_Sensitive_Info__w32.label.xml
Template File: sources-sinks-54d.tmpl.c
*/
/*
 * @description
 * CWE: 319 Cleartext Transmission of Sensitive Information
 * Case0Source: connect_socket Read the password using a connect socket (client side)
 * Case1Source: Use a hardcoded password (one that was not sent over the network)
 * Sinks:
 *    Case1Sink: Decrypt the password before using it in an authentication API call to show that it was transferred as ciphertext
 *    Case0Sink : Use the password directly from the source in an authentication API call to show that it was transferred as plaintext
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
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

#ifndef OMITCASE0

/* case0 function declaration */
void CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_54e_case0Sink(wchar_t * password);

void CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_54d_case0Sink(wchar_t * password)
{
    CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_54e_case0Sink(password);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_54e_case1V1Sink(wchar_t * password);

void CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_54d_case1V1Sink(wchar_t * password)
{
    CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_54e_case1V1Sink(password);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_54e_case1V2Sink(wchar_t * password);

void CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_54d_case1V2Sink(wchar_t * password)
{
    CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_54e_case1V2Sink(password);
}

#endif /* OMITCASE1 */
