/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE426_Untrusted_Search_Path__char_system_73b.cpp
Label Definition File: CWE426_Untrusted_Search_Path.label.xml
Template File: sources-sink-73b.tmpl.cpp
*/
/*
 * @description
 * CWE: 426 Untrusted Search Path
 * Case0Source:  Don't specify the full path in the OS command
 * Case1Source: Specify the full path in the OS command
 * Sinks: system
 *    Case0Sink : Execute the system function
 * Flow Variant: 73 Data flow: data passed in a list from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <list>

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

using namespace std;

namespace CWE426_Untrusted_Search_Path__char_system_73
{

#ifndef OMITCASE0

void case0Sink(list<char *> dataList)
{
    /* copy data out of dataList */
    char * data = dataList.back();
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

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink(list<char *> dataList)
{
    char * data = dataList.back();
    /* NOTE: Executing the system() function without specifying the full path to the executable
     * can allow an attacker to run their own program */
    if (SYSTEM(data) <= 0)
    {
        printLine("command execution failed!");
        exit(1);
    }
}

#endif /* OMITCASE1 */

} /* close namespace */
