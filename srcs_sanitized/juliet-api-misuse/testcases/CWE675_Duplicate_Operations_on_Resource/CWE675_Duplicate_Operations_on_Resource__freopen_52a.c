/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__freopen_52a.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource.label.xml
Template File: sources-sinks-52a.tmpl.c
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * Case0Source: freopen Open and close a file using freopen() and flose()
 * Case1Source: Open a file using fopen()
 * Sinks:
 *    Case1Sink: Do nothing
 *    Case0Sink : Close the file
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

/* case0 function declaration */
void CWE675_Duplicate_Operations_on_Resource__freopen_52b_case0Sink(FILE * data);

void CWE675_Duplicate_Operations_on_Resource__freopen_52_case0()
{
    FILE * data;
    data = NULL; /* Initialize data */
    data = freopen("Case0Source_freopen.txt","w+",stdin);
    /* NOTE: Close the file in the source */
    fclose(data);
    CWE675_Duplicate_Operations_on_Resource__freopen_52b_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE675_Duplicate_Operations_on_Resource__freopen_52b_case1V1Sink(FILE * data);

static void case1V1()
{
    FILE * data;
    data = NULL; /* Initialize data */
    /* ALT: Open, but do not close the file in the source */
    data = fopen("Case1Source_fopen.txt", "w+");
    CWE675_Duplicate_Operations_on_Resource__freopen_52b_case1V1Sink(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE675_Duplicate_Operations_on_Resource__freopen_52b_case1V2Sink(FILE * data);

static void case1V2()
{
    FILE * data;
    data = NULL; /* Initialize data */
    data = freopen("Case0Source_freopen.txt","w+",stdin);
    /* NOTE: Close the file in the source */
    fclose(data);
    CWE675_Duplicate_Operations_on_Resource__freopen_52b_case1V2Sink(data);
}

void CWE675_Duplicate_Operations_on_Resource__freopen_52_case1()
{
    case1V1();
    case1V2();
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
    CWE675_Duplicate_Operations_on_Resource__freopen_52_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE675_Duplicate_Operations_on_Resource__freopen_52_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
