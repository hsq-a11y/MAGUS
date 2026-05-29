/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__wchar_t_ncat_82_case0.cpp
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-82_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * Case0Source:  Do not initialize data properly
 * Case1Source: Initialize data
 * Sinks: ncat
 *    Case0Sink : Copy string to data using wcsncat
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE665_Improper_Initialization__wchar_t_ncat_82.h"

namespace CWE665_Improper_Initialization__wchar_t_ncat_82
{

void CWE665_Improper_Initialization__wchar_t_ncat_82_case0::action(wchar_t * data)
{
    {
        size_t sourceLen;
        wchar_t source[100];
        wmemset(source, L'C', 100-1); /* fill with L'C's */
        source[100-1] = L'\0'; /* null terminate */
        sourceLen = wcslen(source);
        /* NOTE: If data is not initialized properly, wcsncat() may not function correctly */
        wcsncat(data, source, sourceLen);
        printWLine(data);
    }
}

}
#endif /* OMITCASE0 */
