/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE426_Untrusted_Search_Path__wchar_t_popen_22b.c
Label Definition File: CWE426_Untrusted_Search_Path.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 426 Untrusted Search Path
 * Case0Source:  Don't specify the full path in the OS command
 * Case1Source: Specify the full path in the OS command
 * Sink: popen
 *    Case0Sink : Execute the wpopen function
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
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

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the source function */
extern int CWE426_Untrusted_Search_Path__wchar_t_popen_22_case0Global;

wchar_t * CWE426_Untrusted_Search_Path__wchar_t_popen_22_case0Source(wchar_t * data)
{
    if(CWE426_Untrusted_Search_Path__wchar_t_popen_22_case0Global)
    {
        /* NOTE: the full path is not specified */
        wcscpy(data, CASE0_OS_COMMAND);
    }
    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the source functions. */
extern int CWE426_Untrusted_Search_Path__wchar_t_popen_22_case1V11Global;
extern int CWE426_Untrusted_Search_Path__wchar_t_popen_22_case1V12Global;

/* case1V11() - use case1source and case0sink by setting the static variable to false instead of true */
wchar_t * CWE426_Untrusted_Search_Path__wchar_t_popen_22_case1V11Source(wchar_t * data)
{
    if(CWE426_Untrusted_Search_Path__wchar_t_popen_22_case1V11Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: full path is specified */
        wcscpy(data, CASE1_OS_COMMAND);
    }
    return data;
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the if in the source function */
wchar_t * CWE426_Untrusted_Search_Path__wchar_t_popen_22_case1V12Source(wchar_t * data)
{
    if(CWE426_Untrusted_Search_Path__wchar_t_popen_22_case1V12Global)
    {
        /* ALT: full path is specified */
        wcscpy(data, CASE1_OS_COMMAND);
    }
    return data;
}

#endif /* OMITCASE1 */
