/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__freopen_16.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource.label.xml
Template File: sources-sinks-16.tmpl.c
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * Case0Source: freopen Open and close a file using freopen() and flose()
 * Case1Source: Open a file using fopen()
 * Sinks:
 *    Case1Sink: Do nothing
 *    Case0Sink : Close the file
 * Flow Variant: 16 Control flow: while(1)
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

void CWE675_Duplicate_Operations_on_Resource__freopen_16_case0()
{
    FILE * data;
    data = NULL; /* Initialize data */
    while(1)
    {
        data = freopen("Case0Source_freopen.txt","w+",stdin);
        /* NOTE: Close the file in the source */
        fclose(data);
        break;
    }
    while(1)
    {
        /* NOTE: Close the file in the sink (it may have been closed in the Source) */
        fclose(data);
        break;
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2() - use case0source and case1sink by changing the sinks in the second while statement */
static void case1V2()
{
    FILE * data;
    data = NULL; /* Initialize data */
    while(1)
    {
        data = freopen("Case0Source_freopen.txt","w+",stdin);
        /* NOTE: Close the file in the source */
        fclose(data);
        break;
    }
    while(1)
    {
        /* Do nothing */
        /* ALT: Don't close the file in the sink */
        ; /* empty statement needed for some flow variants */
        break;
    }
}

/* case1V1() - use case1source and case0sink by changing the sources in the first while statement */
static void case1V1()
{
    FILE * data;
    data = NULL; /* Initialize data */
    while(1)
    {
        /* ALT: Open, but do not close the file in the source */
        data = fopen("Case1Source_fopen.txt", "w+");
        break;
    }
    while(1)
    {
        /* NOTE: Close the file in the sink (it may have been closed in the Source) */
        fclose(data);
        break;
    }
}

void CWE675_Duplicate_Operations_on_Resource__freopen_16_case1()
{
    case1V2();
    case1V1();
}

#endif /* OMITCASE1 */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITCASE1
    printLine("Calling case1()...");
    CWE675_Duplicate_Operations_on_Resource__freopen_16_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE675_Duplicate_Operations_on_Resource__freopen_16_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
