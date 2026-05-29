/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__wchar_t_cat_44.c
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-44.tmpl.c
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * Case0Source:  Do not initialize data properly
 * Case1Source: Initialize data
 * Sinks: cat
 *    Case0Sink : Copy string to data using wcscat
 * Flow Variant: 44 Data/control flow: data passed as an argument from one function to a function in the same source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

static void case0Sink(wchar_t * data)
{
    {
        wchar_t source[100];
        wmemset(source, L'C', 100-1); /* fill with L'C's */
        source[100-1] = L'\0'; /* null terminate */
        /* NOTE: If data is not initialized properly, wcscat() may not function correctly */
        wcscat(data, source);
        printWLine(data);
    }
}

void CWE665_Improper_Initialization__wchar_t_cat_44_case0()
{
    wchar_t * data;
    /* define a function pointer */
    void (*funcPtr) (wchar_t *) = case0Sink;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    /* NOTE: Do not initialize data */
    ; /* empty statement needed for some flow variants */
    /* use the function pointer */
    funcPtr(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
static void case1V1Sink(wchar_t * data)
{
    {
        wchar_t source[100];
        wmemset(source, L'C', 100-1); /* fill with L'C's */
        source[100-1] = L'\0'; /* null terminate */
        /* NOTE: If data is not initialized properly, wcscat() may not function correctly */
        wcscat(data, source);
        printWLine(data);
    }
}

static void case1V1()
{
    wchar_t * data;
    void (*funcPtr) (wchar_t *) = case1V1Sink;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    /* ALT: Properly initialize data */
    data[0] = L'\0'; /* null terminate */
    funcPtr(data);
}

void CWE665_Improper_Initialization__wchar_t_cat_44_case1()
{
    case1V1();
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
    CWE665_Improper_Initialization__wchar_t_cat_44_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE665_Improper_Initialization__wchar_t_cat_44_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
