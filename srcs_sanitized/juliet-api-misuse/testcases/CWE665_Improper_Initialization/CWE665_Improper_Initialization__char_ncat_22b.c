/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__char_ncat_22b.c
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * Case0Source:  Do not initialize data properly
 * Case1Source: Initialize data
 * Sink: ncat
 *    Case0Sink : Copy string to data using strncat
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the source function */
extern int CWE665_Improper_Initialization__char_ncat_22_case0Global;

char * CWE665_Improper_Initialization__char_ncat_22_case0Source(char * data)
{
    if(CWE665_Improper_Initialization__char_ncat_22_case0Global)
    {
        /* NOTE: Do not initialize data */
        ; /* empty statement needed for some flow variants */
    }
    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the source functions. */
extern int CWE665_Improper_Initialization__char_ncat_22_case1V11Global;
extern int CWE665_Improper_Initialization__char_ncat_22_case1V12Global;

/* case1V11() - use case1source and case0sink by setting the static variable to false instead of true */
char * CWE665_Improper_Initialization__char_ncat_22_case1V11Source(char * data)
{
    if(CWE665_Improper_Initialization__char_ncat_22_case1V11Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: Properly initialize data */
        data[0] = '\0'; /* null terminate */
    }
    return data;
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the if in the source function */
char * CWE665_Improper_Initialization__char_ncat_22_case1V12Source(char * data)
{
    if(CWE665_Improper_Initialization__char_ncat_22_case1V12Global)
    {
        /* ALT: Properly initialize data */
        data[0] = '\0'; /* null terminate */
    }
    return data;
}

#endif /* OMITCASE1 */
