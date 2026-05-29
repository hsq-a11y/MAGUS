/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_52b.c
Label Definition File: CWE319_Cleartext_Tx_Sensitive_Info__w32.label.xml
Template File: sources-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 319 Cleartext Transmission of Sensitive Information
 * Case0Source: listen_socket Read the password using a listen socket (server side)
 * Case1Source: Use a hardcoded password (one that was not sent over the network)
 * Sinks:
 *    Case1Sink: Decrypt the password before using it in an authentication API call to show that it was transferred as ciphertext
 *    Case0Sink : Use the password directly from the source in an authentication API call to show that it was transferred as plaintext
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <winsock2.h>
#include <windows.h>
#include <direct.h>
#pragma comment(lib, "ws2_32") /* include ws2_32.lib when linking */

#define TCP_PORT 27015
#define LISTEN_BACKLOG 5

#pragma comment(lib, "advapi32.lib")

#define HASH_INPUT "ABCDEFG123456" /* INCIDENTAL: Hardcoded crypto */

#ifndef OMITCASE0

/* case0 function declaration */
void CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_52c_case0Sink(char * password);

void CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_52b_case0Sink(char * password)
{
    CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_52c_case0Sink(password);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_52c_case1V1Sink(char * password);

void CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_52b_case1V1Sink(char * password)
{
    CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_52c_case1V1Sink(password);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_52c_case1V2Sink(char * password);

void CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_52b_case1V2Sink(char * password)
{
    CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_52c_case1V2Sink(password);
}

#endif /* OMITCASE1 */
