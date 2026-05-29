/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__wchar_t_ncat_83_case0.cpp
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-83_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * Case0Source:  Do not initialize data properly
 * Case1Source: Initialize data
 * Sinks: ncat
 *    Case0Sink : Copy string to data using wcsncat
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE665_Improper_Initialization__wchar_t_ncat_83.h"

namespace CWE665_Improper_Initialization__wchar_t_ncat_83
{
CWE665_Improper_Initialization__wchar_t_ncat_83_case0::CWE665_Improper_Initialization__wchar_t_ncat_83_case0(wchar_t * dataCopy)
{
    data = dataCopy;
    /* NOTE: Do not initialize data */
    ; /* empty statement needed for some flow variants */
}

CWE665_Improper_Initialization__wchar_t_ncat_83_case0::~CWE665_Improper_Initialization__wchar_t_ncat_83_case0()
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
