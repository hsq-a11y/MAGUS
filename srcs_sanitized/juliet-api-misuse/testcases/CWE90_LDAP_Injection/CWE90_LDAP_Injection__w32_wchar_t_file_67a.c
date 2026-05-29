/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE90_LDAP_Injection__w32_wchar_t_file_67a.c
Label Definition File: CWE90_LDAP_Injection__w32.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 90 LDAP Injection
 * Case0Source: file Read input from a file
 * Case1Source: Use a fixed string
 * Sinks:
 *    Case0Sink : data concatenated into LDAP search, which could result in LDAP Injection
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define FILENAME "C:\\temp\\file.txt"
#else
#define FILENAME "/tmp/file.txt"
#endif

#include <windows.h>
#include <Winldap.h>

#pragma comment(lib, "wldap32")

typedef struct _CWE90_LDAP_Injection__w32_wchar_t_file_67_structType
{
    wchar_t * structFirst;
} CWE90_LDAP_Injection__w32_wchar_t_file_67_structType;

#ifndef OMITCASE0

/* case0 function declaration */
void CWE90_LDAP_Injection__w32_wchar_t_file_67b_case0Sink(CWE90_LDAP_Injection__w32_wchar_t_file_67_structType myStruct);

void CWE90_LDAP_Injection__w32_wchar_t_file_67_case0()
{
    wchar_t * data;
    CWE90_LDAP_Injection__w32_wchar_t_file_67_structType myStruct;
    wchar_t dataBuffer[256] = L"";
    data = dataBuffer;
    {
        /* Read input from a file */
        size_t dataLen = wcslen(data);
        FILE * pFile;
        /* if there is room in data, attempt to read the input from a file */
        if (256-dataLen > 1)
        {
            pFile = fopen(FILENAME, "r");
            if (pFile != NULL)
            {
                /* NOTE: Read data from a file */
                if (fgetws(data+dataLen, (int)(256-dataLen), pFile) == NULL)
                {
                    printLine("fgetws() failed");
                    /* Restore NUL terminator if fgetws fails */
                    data[dataLen] = L'\0';
                }
                fclose(pFile);
            }
        }
    }
    myStruct.structFirst = data;
    CWE90_LDAP_Injection__w32_wchar_t_file_67b_case0Sink(myStruct);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE90_LDAP_Injection__w32_wchar_t_file_67b_case1V1Sink(CWE90_LDAP_Injection__w32_wchar_t_file_67_structType myStruct);

static void case1V1()
{
    wchar_t * data;
    CWE90_LDAP_Injection__w32_wchar_t_file_67_structType myStruct;
    wchar_t dataBuffer[256] = L"";
    data = dataBuffer;
    /* ALT: Use a fixed file name */
    wcscat(data, L"Doe, XXXXX");
    myStruct.structFirst = data;
    CWE90_LDAP_Injection__w32_wchar_t_file_67b_case1V1Sink(myStruct);
}

void CWE90_LDAP_Injection__w32_wchar_t_file_67_case1()
{
    case1V1();
}

#endif /* OMITCASE1 */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITCASE1
    printLine("Calling case1()...");
    CWE90_LDAP_Injection__w32_wchar_t_file_67_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE90_LDAP_Injection__w32_wchar_t_file_67_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
