/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE426_Untrusted_Search_Path__char_system_44.c
Label Definition File: CWE426_Untrusted_Search_Path.label.xml
Template File: sources-sink-44.tmpl.c
*/
/*
 * @description
 * CWE: 426 Untrusted Search Path
 * Case0Source:  Don't specify the full path in the OS command
 * Case1Source: Specify the full path in the OS command
 * Sinks: system
 *    Case0Sink : Execute the system function
 * Flow Variant: 44 Data/control flow: data passed as an argument from one function to a function in the same source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#ifdef _WIN32
#define CASE0_OS_COMMAND "cmd.exe /c dir"

/* REVIEWERS NOTE:
 * This hard-coded path is probably incorrect for Windows systems, as it will
 * function improperly on 9x/NT/2K, possibly on XP+ systems upgraded from 2K,
 * and could introduce code execution vulnerabilities on Windows systems that
 * have a system drive on an alternate drive letter (e.g., d:\windows)
 */
#define CASE1_OS_COMMAND "c:\\windows\\system32\\cmd.exe /c dir"
#else /* NOT _WIN32 */
#define CASE0_OS_COMMAND "ls -la"
#define CASE1_OS_COMMAND "/usr/bin/ls -la"
#endif /* end NOT _WIN32 */

#ifdef _WIN32
#define SYSTEM system
#else /* NOT _WIN32 */
#define SYSTEM system
#endif

#ifndef OMITCASE0

static void case0Sink(char * data)
{
    /* NOTE: Executing the system() function without specifying the full path to the executable
     * can allow an attacker to run their own program */
    if (SYSTEM(data) <= 0)
    {
        printLine("command execution failed!");
        exit(1);
    }
}

void CWE426_Untrusted_Search_Path__char_system_44_case0()
{
    char * data;
    /* define a function pointer */
    void (*funcPtr) (char *) = case0Sink;
    char dataBuffer[100] = "";
    data = dataBuffer;
    /* NOTE: the full path is not specified */
    strcpy(data, CASE0_OS_COMMAND);
    /* use the function pointer */
    funcPtr(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
static void case1V1Sink(char * data)
{
    /* NOTE: Executing the system() function without specifying the full path to the executable
     * can allow an attacker to run their own program */
    if (SYSTEM(data) <= 0)
    {
        printLine("command execution failed!");
        exit(1);
    }
}

static void case1V1()
{
    char * data;
    void (*funcPtr) (char *) = case1V1Sink;
    char dataBuffer[100] = "";
    data = dataBuffer;
    /* ALT: full path is specified */
    strcpy(data, CASE1_OS_COMMAND);
    funcPtr(data);
}

void CWE426_Untrusted_Search_Path__char_system_44_case1()
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
    CWE426_Untrusted_Search_Path__char_system_44_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE426_Untrusted_Search_Path__char_system_44_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
