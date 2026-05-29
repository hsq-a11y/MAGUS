/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE426_Untrusted_Search_Path__char_system_81.h
Label Definition File: CWE426_Untrusted_Search_Path.label.xml
Template File: sources-sink-81.tmpl.h
*/
/*
 * @description
 * CWE: 426 Untrusted Search Path
 * Case0Source:  Don't specify the full path in the OS command
 * Case1Source: Specify the full path in the OS command
 * Sinks: system
 *    Case0Sink : Execute the system function
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
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

namespace CWE426_Untrusted_Search_Path__char_system_81
{

class CWE426_Untrusted_Search_Path__char_system_81_base
{
public:
    /* pure virtual function */
    virtual void action(char * data) const = 0;
};

#ifndef OMITCASE0

class CWE426_Untrusted_Search_Path__char_system_81_case0 : public CWE426_Untrusted_Search_Path__char_system_81_base
{
public:
    void action(char * data) const;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE426_Untrusted_Search_Path__char_system_81_case1V1 : public CWE426_Untrusted_Search_Path__char_system_81_base
{
public:
    void action(char * data) const;
};

#endif /* OMITCASE1 */

}
