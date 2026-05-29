/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__char_cat_42.c
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-42.tmpl.c
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * Case0Source:  Do not initialize data properly
 * Case1Source: Initialize data
 * Sink: cat
 *    Case0Sink : Copy string to data using strcat
 * Flow Variant: 42 Data flow: data returned from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

static char * case0Source(char * data)
{
    /* NOTE: Do not initialize data */
    ; /* empty statement needed for some flow variants */
    return data;
}

void CWE665_Improper_Initialization__char_cat_42_case0()
{
    char * data;
    char dataBuffer[100];
    data = dataBuffer;
    data = case0Source(data);
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

static char * case1V1Source(char * data)
{
    /* ALT: Properly initialize data */
    data[0] = '\0'; /* null terminate */
    return data;
}

/* case1V1 uses the Case1Source with the Case0Sink */
static void case1V1()
{
    char * data;
    char dataBuffer[100];
    data = dataBuffer;
    data = case1V1Source(data);
    {
        char source[100];
        memset(source, 'C', 100-1); /* fill with 'C's */
        source[100-1] = '\0'; /* null terminate */
        /* NOTE: If data is not initialized properly, strcat() may not function correctly */
        strcat(data, source);
        printLine(data);
    }
}

void CWE665_Improper_Initialization__char_cat_42_case1()
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
    CWE665_Improper_Initialization__char_cat_42_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE665_Improper_Initialization__char_cat_42_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
