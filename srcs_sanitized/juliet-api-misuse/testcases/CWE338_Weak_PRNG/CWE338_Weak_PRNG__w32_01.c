/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE338_Weak_PRNG__w32_01.c
Label Definition File: CWE338_Weak_PRNG__w32.label.xml
Template File: point-note-01.tmpl.c
*/
/*
 * @description
 * CWE: 338 Use of Cryptographically Weak PRNG
 * Sinks:
 *    Case1Sink: Use CryptGenRandom() to generate a random number
 *    Case0Sink : Use rand() to generate a random number
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#include <wincrypt.h>
#pragma comment(lib, "advapi32.lib")

#ifndef OMITCASE0

void CWE338_Weak_PRNG__w32_01_case0()
{
    {
        /* NOTE: Use of rand() as a PRNG */
        int data = rand();
        printIntLine(data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

static void case11()
{
    {
        HCRYPTPROV hCryptProv;
        int data;
        if (!CryptAcquireContextW(&hCryptProv, 0, 0, PROV_RSA_FULL, 0))
        {
            exit(1);
        }
        /* ALT: Use of CryptGenRandom() as a more secure PRNG */
        if (!CryptGenRandom(hCryptProv, sizeof(data), (BYTE *) &data))
        {
            CryptReleaseContext(hCryptProv, 0);
            exit(1);
        }
        if (hCryptProv)
        {
            CryptReleaseContext(hCryptProv, 0);
        }
        printIntLine(data);
    }
}

void CWE338_Weak_PRNG__w32_01_case1()
{
    case11();
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
    CWE338_Weak_PRNG__w32_01_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE338_Weak_PRNG__w32_01_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
