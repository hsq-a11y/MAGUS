/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE273_Improper_Check_for_Dropped_Privileges__w32_RpcImpersonateClient_03.c
Label Definition File: CWE273_Improper_Check_for_Dropped_Privileges__w32.label.xml
Template File: point-note-03.tmpl.c
*/
/*
 * @description
 * CWE: 273 Improper Check for Dropped Privileges
 * Sinks: RpcImpersonateClient
 *    Case1Sink: Check the return value of RpcImpersonateClient() and handle it properly
 *    Case0Sink : Do not check if RpcImpersonateClient() fails
 * Flow Variant: 03 Control flow: if(5==5) and if(5!=5)
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#include <rpcdce.h>
# pragma comment(lib, "rpcrt4")

#ifndef OMITCASE0

void CWE273_Improper_Check_for_Dropped_Privileges__w32_RpcImpersonateClient_03_case0()
{
    if(5==5)
    {
        RpcImpersonateClient(0);
        /* NOTE: Do not check if RpcImpersonateClient() fails */
        /* We'll leave out most of the implementation since it has nothing to do with the CWE
         * and since the checkers are looking for certain function calls anyway */
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case11() uses if(5!=5) instead of if(5==5) */
static void case11()
{
    if(5!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: Check the return value of RpcImpersonateClient() for RPC_S_OK */
        if (RpcImpersonateClient(0) != RPC_S_OK)
        {
            exit(1);
        }
        /* We'll leave out most of the implementation since it has nothing to do with the CWE
         * and since the checkers are looking for certain function calls anyway */
    }
}

/* case12() reverses the bodies in the if statement */
static void case12()
{
    if(5==5)
    {
        /* ALT: Check the return value of RpcImpersonateClient() for RPC_S_OK */
        if (RpcImpersonateClient(0) != RPC_S_OK)
        {
            exit(1);
        }
        /* We'll leave out most of the implementation since it has nothing to do with the CWE
         * and since the checkers are looking for certain function calls anyway */
    }
}

void CWE273_Improper_Check_for_Dropped_Privileges__w32_RpcImpersonateClient_03_case1()
{
    case11();
    case12();
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
    CWE273_Improper_Check_for_Dropped_Privileges__w32_RpcImpersonateClient_03_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE273_Improper_Check_for_Dropped_Privileges__w32_RpcImpersonateClient_03_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
