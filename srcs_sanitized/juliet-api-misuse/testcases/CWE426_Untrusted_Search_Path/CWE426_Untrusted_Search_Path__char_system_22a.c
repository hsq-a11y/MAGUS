/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE426_Untrusted_Search_Path__char_system_22a.c
Label Definition File: CWE426_Untrusted_Search_Path.label.xml
Template File: sources-sink-22a.tmpl.c
*/
/*
 * @description
 * CWE: 426 Untrusted Search Path
 * Case0Source:  Don't specify the full path in the OS command
 * Case1Source: Specify the full path in the OS command
 * Sink: system
 *    Case0Sink : Execute the system function
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
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

/* The global variable below is used to drive control flow in the source function */
int CWE426_Untrusted_Search_Path__char_system_22_case0Global = 0;

char * CWE426_Untrusted_Search_Path__char_system_22_case0Source(char * data);

void CWE426_Untrusted_Search_Path__char_system_22_case0()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    CWE426_Untrusted_Search_Path__char_system_22_case0Global = 1; /* true */
    data = CWE426_Untrusted_Search_Path__char_system_22_case0Source(data);
    /* NOTE: Executing the system() function without specifying the full path to the executable
     * can allow an attacker to run their own program */
    if (SYSTEM(data) <= 0)
    {
        printLine("command execution failed!");
        exit(1);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the source functions. */
int CWE426_Untrusted_Search_Path__char_system_22_case1V11Global = 0;
int CWE426_Untrusted_Search_Path__char_system_22_case1V12Global = 0;

/* case1V11() - use case1source and case0sink by setting the static variable to false instead of true */
char * CWE426_Untrusted_Search_Path__char_system_22_case1V11Source(char * data);

static void case1V11()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    CWE426_Untrusted_Search_Path__char_system_22_case1V11Global = 0; /* false */
    data = CWE426_Untrusted_Search_Path__char_system_22_case1V11Source(data);
    /* NOTE: Executing the system() function without specifying the full path to the executable
     * can allow an attacker to run their own program */
    if (SYSTEM(data) <= 0)
    {
        printLine("command execution failed!");
        exit(1);
    }
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the if in the source function */
char * CWE426_Untrusted_Search_Path__char_system_22_case1V12Source(char * data);

static void case1V12()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    CWE426_Untrusted_Search_Path__char_system_22_case1V12Global = 1; /* true */
    data = CWE426_Untrusted_Search_Path__char_system_22_case1V12Source(data);
    /* NOTE: Executing the system() function without specifying the full path to the executable
     * can allow an attacker to run their own program */
    if (SYSTEM(data) <= 0)
    {
        printLine("command execution failed!");
        exit(1);
    }
}

void CWE426_Untrusted_Search_Path__char_system_22_case1()
{
    case1V11();
    case1V12();
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
    CWE426_Untrusted_Search_Path__char_system_22_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE426_Untrusted_Search_Path__char_system_22_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
