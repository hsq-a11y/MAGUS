/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__char_cat_68b.c
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * Case0Source:  Do not initialize data properly
 * Case1Source: Initialize data
 * Sink: cat
 *    Case0Sink : Copy string to data using strcat
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

extern char * CWE665_Improper_Initialization__char_cat_68_case0Data;
extern char * CWE665_Improper_Initialization__char_cat_68_case1V1Data;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

void CWE665_Improper_Initialization__char_cat_68b_case0Sink()
{
    char * data = CWE665_Improper_Initialization__char_cat_68_case0Data;
    {
        char source[100];
        memset(source, 'C', 100-1); /* fill with 'C's */
        source[100-1] = '\0'; /* null terminate */
        /* NOTE: If data is not initialized properly, strcat() may not function correctly */
        strcat(data, source);
        printLine(data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE665_Improper_Initialization__char_cat_68b_case1V1Sink()
{
    char * data = CWE665_Improper_Initialization__char_cat_68_case1V1Data;
    {
        char source[100];
        memset(source, 'C', 100-1); /* fill with 'C's */
        source[100-1] = '\0'; /* null terminate */
        /* NOTE: If data is not initialized properly, strcat() may not function correctly */
        strcat(data, source);
        printLine(data);
    }
}

#endif /* OMITCASE1 */
