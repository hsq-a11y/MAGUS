/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_82.h
Label Definition File: CWE319_Cleartext_Tx_Sensitive_Info__w32.label.xml
Template File: sources-sinks-82.tmpl.h
*/
/*
 * @description
 * CWE: 319 Cleartext Transmission of Sensitive Information
 * Case0Source: listen_socket Read the password using a listen socket (server side)
 * Case1Source: Use a hardcoded password (one that was not sent over the network)
 * Sinks:
 *    Case1Sink: Decrypt the password before using it in an authentication API call to show that it was transferred as ciphertext
 *    Case0Sink : Use the password directly from the source in an authentication API call to show that it was transferred as plaintext
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"

namespace CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_82
{

class CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_82_base
{
public:
    /* pure virtual function */
    virtual void action(wchar_t * password) = 0;
};

#ifndef OMITCASE0

class CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_82_case0 : public CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_82_base
{
public:
    void action(wchar_t * password);
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_82_case1V1 : public CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_82_base
{
public:
    void action(wchar_t * password);
};

class CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_82_case1V2 : public CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_listen_socket_82_base
{
public:
    void action(wchar_t * password);
};

#endif /* OMITCASE1 */

}
