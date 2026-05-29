/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__wchar_t_cat_53b.c
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-53b.tmpl.c
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * Case0Source:  Do not initialize data properly
 * Case1Source: Initialize data
 * Sink: cat
 *    Case0Sink : Copy string to data using wcscat
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

/* case0 function declaration */
void CWE665_Improper_Initialization__wchar_t_cat_53c_case0Sink(wchar_t * data);

void CWE665_Improper_Initialization__wchar_t_cat_53b_case0Sink(wchar_t * data)
{
    CWE665_Improper_Initialization__wchar_t_cat_53c_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declaration */
void CWE665_Improper_Initialization__wchar_t_cat_53c_case1V1Sink(wchar_t * data);

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE665_Improper_Initialization__wchar_t_cat_53b_case1V1Sink(wchar_t * data)
{
    CWE665_Improper_Initialization__wchar_t_cat_53c_case1V1Sink(data);
}

#endif /* OMITCASE1 */
