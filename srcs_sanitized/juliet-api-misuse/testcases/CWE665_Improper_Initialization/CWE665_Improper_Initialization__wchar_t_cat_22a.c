/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__wchar_t_cat_22a.c
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-22a.tmpl.c
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * Case0Source:  Do not initialize data properly
 * Case1Source: Initialize data
 * Sink: cat
 *    Case0Sink : Copy string to data using wcscat
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the source function */
int CWE665_Improper_Initialization__wchar_t_cat_22_case0Global = 0;

wchar_t * CWE665_Improper_Initialization__wchar_t_cat_22_case0Source(wchar_t * data);

void CWE665_Improper_Initialization__wchar_t_cat_22_case0()
{
    wchar_t * data;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    CWE665_Improper_Initialization__wchar_t_cat_22_case0Global = 1; /* true */
    data = CWE665_Improper_Initialization__wchar_t_cat_22_case0Source(data);
    {
        wchar_t source[100];
        wmemset(source, L'C', 100-1); /* fill with L'C's */
        source[100-1] = L'\0'; /* null terminate */
        /* NOTE: If data is not initialized properly, wcscat() may not function correctly */
        wcscat(data, source);
        printWLine(data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the source functions. */
int CWE665_Improper_Initialization__wchar_t_cat_22_case1V11Global = 0;
int CWE665_Improper_Initialization__wchar_t_cat_22_case1V12Global = 0;

/* case1V11() - use case1source and case0sink by setting the static variable to false instead of true */
wchar_t * CWE665_Improper_Initialization__wchar_t_cat_22_case1V11Source(wchar_t * data);

static void case1V11()
{
    wchar_t * data;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    CWE665_Improper_Initialization__wchar_t_cat_22_case1V11Global = 0; /* false */
    data = CWE665_Improper_Initialization__wchar_t_cat_22_case1V11Source(data);
    {
        wchar_t source[100];
        wmemset(source, L'C', 100-1); /* fill with L'C's */
        source[100-1] = L'\0'; /* null terminate */
        /* NOTE: If data is not initialized properly, wcscat() may not function correctly */
        wcscat(data, source);
        printWLine(data);
    }
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the if in the source function */
wchar_t * CWE665_Improper_Initialization__wchar_t_cat_22_case1V12Source(wchar_t * data);

static void case1V12()
{
    wchar_t * data;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    CWE665_Improper_Initialization__wchar_t_cat_22_case1V12Global = 1; /* true */
    data = CWE665_Improper_Initialization__wchar_t_cat_22_case1V12Source(data);
    {
        wchar_t source[100];
        wmemset(source, L'C', 100-1); /* fill with L'C's */
        source[100-1] = L'\0'; /* null terminate */
        /* NOTE: If data is not initialized properly, wcscat() may not function correctly */
        wcscat(data, source);
        printWLine(data);
    }
}

void CWE665_Improper_Initialization__wchar_t_cat_22_case1()
{
    case1V11();
    case1V12();
}

#endif /* OMITCASE1 */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITCASE1
    printLine("Calling case1()...");
    CWE665_Improper_Initialization__wchar_t_cat_22_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE665_Improper_Initialization__wchar_t_cat_22_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
