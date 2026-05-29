/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE426_Untrusted_Search_Path__wchar_t_system_34.c
Label Definition File: CWE426_Untrusted_Search_Path.label.xml
Template File: sources-sink-34.tmpl.c
*/
/*
 * @description
 * CWE: 426 Untrusted Search Path
 * Case0Source:  Don't specify the full path in the OS command
 * Case1Source: Specify the full path in the OS command
 * Sinks: system
 *    Case0Sink : Execute the _wsystem function
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#ifdef _WIN32
#define CASE0_OS_COMMAND L"cmd.exe /c dir"

/* REVIEWERS NOTE:
 * This hard-coded path is probably incorrect for Windows systems, as it will
 * function improperly on 9x/NT/2K, possibly on XP+ systems upgraded from 2K,
 * and could introduce code execution vulnerabilities on Windows systems that
 * have a system drive on an alternate drive letter (e.g., d:\windows)
 */
#define CASE1_OS_COMMAND L"c:\\windows\\system32\\cmd.exe /c dir"
#else /* NOT _WIN32 */
#define CASE0_OS_COMMAND L"ls -la"
#define CASE1_OS_COMMAND L"/usr/bin/ls -la"
#endif /* end NOT _WIN32 */

#ifdef _WIN32
#define SYSTEM _wsystem
#else /* NOT _WIN32 */
#define SYSTEM system
#endif

typedef union
{
    wchar_t * unionFirst;
    wchar_t * unionSecond;
} CWE426_Untrusted_Search_Path__wchar_t_system_34_unionType;

#ifndef OMITCASE0

void CWE426_Untrusted_Search_Path__wchar_t_system_34_case0()
{
    wchar_t * data;
    CWE426_Untrusted_Search_Path__wchar_t_system_34_unionType myUnion;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    /* NOTE: the full path is not specified */
    wcscpy(data, CASE0_OS_COMMAND);
    myUnion.unionFirst = data;
    {
        wchar_t * data = myUnion.unionSecond;
        /* NOTE: Executing the _wsystem() function without specifying the full path to the executable
         * can allow an attacker to run their own program */
        if (SYSTEM(data) <= 0)
        {
            printLine("command execution failed!");
            exit(1);
        }
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
static void case1V1()
{
    wchar_t * data;
    CWE426_Untrusted_Search_Path__wchar_t_system_34_unionType myUnion;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    /* ALT: full path is specified */
    wcscpy(data, CASE1_OS_COMMAND);
    myUnion.unionFirst = data;
    {
        wchar_t * data = myUnion.unionSecond;
        /* NOTE: Executing the _wsystem() function without specifying the full path to the executable
         * can allow an attacker to run their own program */
        if (SYSTEM(data) <= 0)
        {
            printLine("command execution failed!");
            exit(1);
        }
    }
}

void CWE426_Untrusted_Search_Path__wchar_t_system_34_case1()
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
    CWE426_Untrusted_Search_Path__wchar_t_system_34_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE426_Untrusted_Search_Path__wchar_t_system_34_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
