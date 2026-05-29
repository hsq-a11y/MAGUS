/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_83a.cpp
Label Definition File: CWE319_Cleartext_Tx_Sensitive_Info__w32.label.xml
Template File: sources-sinks-83a.tmpl.cpp
*/
/*
 * @description
 * CWE: 319 Cleartext Transmission of Sensitive Information
 * Case0Source: connect_socket Read the password using a connect socket (client side)
 * Case1Source: Use a hardcoded password (one that was not sent over the network)
 * Sinks:
 *    Case1Sink: Decrypt the password before using it in an authentication API call to show that it was transferred as ciphertext
 *    Case0Sink : Use the password directly from the source in an authentication API call to show that it was transferred as plaintext
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"
#include "CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_83.h"

namespace CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_83
{

#ifndef OMITCASE0

void case0()
{
    wchar_t * password;
    wchar_t passwordBuffer[100] = L"";
    password = passwordBuffer;
    CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_83_case0 case0Object(password);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
static void case1V1()
{
    wchar_t * password;
    wchar_t passwordBuffer[100] = L"";
    password = passwordBuffer;
    CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_83_case1V1 case1V1Object(password);
}

/* case1V1 uses the Case0Source with the Case1Sink */
static void case1V2()
{
    wchar_t * password;
    wchar_t passwordBuffer[100] = L"";
    password = passwordBuffer;
    CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_83_case1V2 case1V2Object(password);
}

void case1()
{
    case1V1();
    case1V2();
}

#endif /* OMITCASE1 */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_83; /* so that we can use case1 and case0 easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITCASE1
    printLine("Calling case1()...");
    case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
