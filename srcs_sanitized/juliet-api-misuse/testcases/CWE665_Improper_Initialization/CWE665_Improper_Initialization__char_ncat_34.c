/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__char_ncat_34.c
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-34.tmpl.c
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * Case0Source:  Do not initialize data properly
 * Case1Source: Initialize data
 * Sinks: ncat
 *    Case0Sink : Copy string to data using strncat
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef union
{
    char * unionFirst;
    char * unionSecond;
} CWE665_Improper_Initialization__char_ncat_34_unionType;

#ifndef OMITCASE0

void CWE665_Improper_Initialization__char_ncat_34_case0()
{
    char * data;
    CWE665_Improper_Initialization__char_ncat_34_unionType myUnion;
    char dataBuffer[100];
    data = dataBuffer;
    /* NOTE: Do not initialize data */
    ; /* empty statement needed for some flow variants */
    myUnion.unionFirst = data;
    {
        char * data = myUnion.unionSecond;
        {
            size_t sourceLen;
            char source[100];
            memset(source, 'C', 100-1); /* fill with 'C's */
            source[100-1] = '\0'; /* null terminate */
            sourceLen = strlen(source);
            /* NOTE: If data is not initialized properly, strncat() may not function correctly */
            strncat(data, source, sourceLen);
            printLine(data);
        }
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
static void case1V1()
{
    char * data;
    CWE665_Improper_Initialization__char_ncat_34_unionType myUnion;
    char dataBuffer[100];
    data = dataBuffer;
    /* ALT: Properly initialize data */
    data[0] = '\0'; /* null terminate */
    myUnion.unionFirst = data;
    {
        char * data = myUnion.unionSecond;
        {
            size_t sourceLen;
            char source[100];
            memset(source, 'C', 100-1); /* fill with 'C's */
            source[100-1] = '\0'; /* null terminate */
            sourceLen = strlen(source);
            /* NOTE: If data is not initialized properly, strncat() may not function correctly */
            strncat(data, source, sourceLen);
            printLine(data);
        }
    }
}

void CWE665_Improper_Initialization__char_ncat_34_case1()
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
    CWE665_Improper_Initialization__char_ncat_34_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE665_Improper_Initialization__char_ncat_34_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
