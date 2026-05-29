/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__char_cat_54b.c
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-54b.tmpl.c
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * Case0Source:  Do not initialize data properly
 * Case1Source: Initialize data
 * Sink: cat
 *    Case0Sink : Copy string to data using strcat
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

/* case0 function declaration */
void CWE665_Improper_Initialization__char_cat_54c_case0Sink(char * data);

void CWE665_Improper_Initialization__char_cat_54b_case0Sink(char * data)
{
    CWE665_Improper_Initialization__char_cat_54c_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declaration */
void CWE665_Improper_Initialization__char_cat_54c_case1V1Sink(char * data);

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE665_Improper_Initialization__char_cat_54b_case1V1Sink(char * data)
{
    CWE665_Improper_Initialization__char_cat_54c_case1V1Sink(data);
}

#endif /* OMITCASE1 */
