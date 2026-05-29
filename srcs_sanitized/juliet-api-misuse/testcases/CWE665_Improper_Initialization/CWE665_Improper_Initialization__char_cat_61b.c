/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__char_cat_61b.c
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-61b.tmpl.c
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * Case0Source:  Do not initialize data properly
 * Case1Source: Initialize data
 * Sinks: cat
 *    Case0Sink : Copy string to data using strcat
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

char * CWE665_Improper_Initialization__char_cat_61b_case0Source(char * data)
{
    /* NOTE: Do not initialize data */
    ; /* empty statement needed for some flow variants */
    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
char * CWE665_Improper_Initialization__char_cat_61b_case1V1Source(char * data)
{
    /* ALT: Properly initialize data */
    data[0] = '\0'; /* null terminate */
    return data;
}

#endif /* OMITCASE1 */
