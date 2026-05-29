/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE780_Use_of_RSA_Algorithm_Without_OAEP__w32_13.c
Label Definition File: CWE780_Use_of_RSA_Algorithm_Without_OAEP__w32.label.xml
Template File: point-note-13.tmpl.c
*/
/*
 * @description
 * CWE: 780 Use of RSA Algorithm Without OAEP
 * Sinks:
 *    Case1Sink: Use RSA with OAEP
 *    Case0Sink : Use RSA without OAEP
 * Flow Variant: 13 Control flow: if(GLOBAL_CONST_FIVE==5) and if(GLOBAL_CONST_FIVE!=5)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#include <wincrypt.h>

/* Link with the Advapi32.lib file for Crypt* functions */
#pragma comment (lib, "Advapi32")
#define HASH_INPUT "ABCDEFG123456" /* INCIDENTAL: Hardcoded crypto */
#define PAYLOAD "String to be encrypted"

#ifndef OMITCASE0

void CWE780_Use_of_RSA_Algorithm_Without_OAEP__w32_13_case0()
{
    if(GLOBAL_CONST_FIVE==5)
    {
        {
            BYTE payload[200];
            DWORD payloadLen = strlen(PAYLOAD);
            HCRYPTPROV hCryptProv = (HCRYPTPROV)NULL;
            HCRYPTHASH hHash = (HCRYPTHASH)NULL;
            HCRYPTKEY hKey = (HCRYPTKEY)NULL;
            do
            {
                /* Copy plaintext into payload buffer */
                memcpy(payload, PAYLOAD, payloadLen);
                /* Try to get a context with and without a new key set */
                if(!CryptAcquireContext(&hCryptProv, NULL, MS_ENHANCED_PROV, PROV_RSA_FULL, 0))
                {
                    if(!CryptAcquireContext(&hCryptProv, NULL, MS_ENHANCED_PROV, PROV_RSA_FULL, CRYPT_NEWKEYSET))
                    {
                        printLine("Error in acquiring cryptographic context");
                        exit(1);
                    }
                }
                /* Create Hash handle */
                if(!CryptCreateHash(hCryptProv, CALG_SHA_256, 0, 0, &hHash))
                {
                    printLine("Error in creating hash");
                    exit(1);
                }
                /* Hash the data */
                if(!CryptHashData(hHash, (BYTE *) HASH_INPUT, strlen(HASH_INPUT)*sizeof(char), 0))
                {
                    printLine("Error in hashing HASH_INPUT");
                    exit(1);
                }
                /* Derive an RSA key from the hash */
                if(!CryptDeriveKey(hCryptProv, CALG_RSA_SIGN, hHash, 0, &hKey))
                {
                    printLine("Error in CryptDeriveKey");
                    exit(1);
                }
                /* NOTE: Do not use OAEP padding */
                /* Use the derived key to encrypt something */
                if(!CryptEncrypt(hKey, (HCRYPTHASH)NULL, 1, 0, (BYTE *)payload, &payloadLen, sizeof(payload)))
                {
                    printLine("Error in CryptEncryptData");
                    exit(1);
                }
            }
            while (0);
            if (hKey)
            {
                CryptDestroyKey(hKey);
            }
            if (hHash)
            {
                CryptDestroyHash(hHash);
            }
            if (hCryptProv)
            {
                CryptReleaseContext(hCryptProv, 0);
            }
            /* use encrypted block */
            printBytesLine((BYTE *) payload, payloadLen);
        }
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case11() uses if(GLOBAL_CONST_FIVE!=5) instead of if(GLOBAL_CONST_FIVE==5) */
static void case11()
{
    if(GLOBAL_CONST_FIVE!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            BYTE payload[200];
            DWORD payloadLen = strlen(PAYLOAD);
            HCRYPTPROV hCryptProv = (HCRYPTPROV)NULL;
            HCRYPTHASH hHash = (HCRYPTHASH)NULL;
            HCRYPTKEY hKey = (HCRYPTKEY)NULL;
            do
            {
                /* Copy plaintext into payload buffer */
                memcpy(payload, PAYLOAD, payloadLen);
                /* Try to get a context with and without a new key set */
                if(!CryptAcquireContext(&hCryptProv, NULL, MS_ENHANCED_PROV, PROV_RSA_FULL, 0))
                {
                    if(!CryptAcquireContext(&hCryptProv, NULL, MS_ENHANCED_PROV, PROV_RSA_FULL, CRYPT_NEWKEYSET))
                    {
                        printLine("Error in acquiring cryptographic context");
                        exit(1);
                    }
                }
                /* Create Hash handle */
                if(!CryptCreateHash(hCryptProv, CALG_SHA_256, 0, 0, &hHash))
                {
                    printLine("Error in creating hash");
                    exit(1);
                }
                /* Hash the data */
                if(!CryptHashData(hHash, (BYTE *) HASH_INPUT, strlen(HASH_INPUT)*sizeof(char), 0))
                {
                    printLine("Error in hashing HASH_INPUT");
                    exit(1);
                }
                /* Derive an RSA key from the hash */
                if(!CryptDeriveKey(hCryptProv, CALG_RSA_SIGN, hHash, 0, &hKey))
                {
                    printLine("Error in CryptDeriveKey");
                    exit(1);
                }
                /* ALT: Use OAEP padding */
                /* Use the derived key to encrypt something */
                if(!CryptEncrypt(hKey, (HCRYPTHASH)NULL, 1, CRYPT_OAEP, (BYTE *)payload, &payloadLen, sizeof(payload)))
                {
                    printLine("Error in CryptEncryptData");
                    exit(1);
                }
            }
            while (0);
            if (hKey)
            {
                CryptDestroyKey(hKey);
            }
            if (hHash)
            {
                CryptDestroyHash(hHash);
            }
            if (hCryptProv)
            {
                CryptReleaseContext(hCryptProv, 0);
            }
            /* use encrypted block */
            printBytesLine((BYTE *) payload, payloadLen);
        }
    }
}

/* case12() reverses the bodies in the if statement */
static void case12()
{
    if(GLOBAL_CONST_FIVE==5)
    {
        {
            BYTE payload[200];
            DWORD payloadLen = strlen(PAYLOAD);
            HCRYPTPROV hCryptProv = (HCRYPTPROV)NULL;
            HCRYPTHASH hHash = (HCRYPTHASH)NULL;
            HCRYPTKEY hKey = (HCRYPTKEY)NULL;
            do
            {
                /* Copy plaintext into payload buffer */
                memcpy(payload, PAYLOAD, payloadLen);
                /* Try to get a context with and without a new key set */
                if(!CryptAcquireContext(&hCryptProv, NULL, MS_ENHANCED_PROV, PROV_RSA_FULL, 0))
                {
                    if(!CryptAcquireContext(&hCryptProv, NULL, MS_ENHANCED_PROV, PROV_RSA_FULL, CRYPT_NEWKEYSET))
                    {
                        printLine("Error in acquiring cryptographic context");
                        exit(1);
                    }
                }
                /* Create Hash handle */
                if(!CryptCreateHash(hCryptProv, CALG_SHA_256, 0, 0, &hHash))
                {
                    printLine("Error in creating hash");
                    exit(1);
                }
                /* Hash the data */
                if(!CryptHashData(hHash, (BYTE *) HASH_INPUT, strlen(HASH_INPUT)*sizeof(char), 0))
                {
                    printLine("Error in hashing HASH_INPUT");
                    exit(1);
                }
                /* Derive an RSA key from the hash */
                if(!CryptDeriveKey(hCryptProv, CALG_RSA_SIGN, hHash, 0, &hKey))
                {
                    printLine("Error in CryptDeriveKey");
                    exit(1);
                }
                /* ALT: Use OAEP padding */
                /* Use the derived key to encrypt something */
                if(!CryptEncrypt(hKey, (HCRYPTHASH)NULL, 1, CRYPT_OAEP, (BYTE *)payload, &payloadLen, sizeof(payload)))
                {
                    printLine("Error in CryptEncryptData");
                    exit(1);
                }
            }
            while (0);
            if (hKey)
            {
                CryptDestroyKey(hKey);
            }
            if (hHash)
            {
                CryptDestroyHash(hHash);
            }
            if (hCryptProv)
            {
                CryptReleaseContext(hCryptProv, 0);
            }
            /* use encrypted block */
            printBytesLine((BYTE *) payload, payloadLen);
        }
    }
}

void CWE780_Use_of_RSA_Algorithm_Without_OAEP__w32_13_case1()
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
    CWE780_Use_of_RSA_Algorithm_Without_OAEP__w32_13_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE780_Use_of_RSA_Algorithm_Without_OAEP__w32_13_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
