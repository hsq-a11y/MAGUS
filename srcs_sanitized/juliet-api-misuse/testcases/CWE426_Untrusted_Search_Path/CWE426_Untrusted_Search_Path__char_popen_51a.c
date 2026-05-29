/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE426_Untrusted_Search_Path__char_popen_51a.c
Label Definition File: CWE426_Untrusted_Search_Path.label.xml
Template File: sources-sink-51a.tmpl.c
*/
/*
 * @description
 * CWE: 426 Untrusted Search Path
 * Case0Source:  Don't specify the full path in the OS command
 * Case1Source: Specify the full path in the OS command
 * Sink: popen
 *    Case0Sink : Execute the popen function
 * Flow Variant: 51 Data flow: data passed as an argument from one function to another in different source files
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
#define POPEN _popen
#define PCLOSE _pclose
#else /* NOT _WIN32 */
#define POPEN popen
#define PCLOSE pclose
#endif

#ifndef OMITCASE0

/* case0 function declaration */
void CWE426_Untrusted_Search_Path__char_popen_51b_case0Sink(char * data);

void CWE426_Untrusted_Search_Path__char_popen_51_case0()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    /* NOTE: the full path is not specified */
    strcpy(data, CASE0_OS_COMMAND);
    CWE426_Untrusted_Search_Path__char_popen_51b_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declarations */
void CWE426_Untrusted_Search_Path__char_popen_51b_case1V1Sink(char * data);

/* case1V1 uses the Case1Source with the Case0Sink */
static void case1V1()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    /* ALT: full path is specified */
    strcpy(data, CASE1_OS_COMMAND);
    CWE426_Untrusted_Search_Path__char_popen_51b_case1V1Sink(data);
}

void CWE426_Untrusted_Search_Path__char_popen_51_case1()
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
    CWE426_Untrusted_Search_Path__char_popen_51_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE426_Untrusted_Search_Path__char_popen_51_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
