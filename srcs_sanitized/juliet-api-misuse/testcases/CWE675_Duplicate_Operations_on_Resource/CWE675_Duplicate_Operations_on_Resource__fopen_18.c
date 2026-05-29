/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__fopen_18.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource.label.xml
Template File: sources-sinks-18.tmpl.c
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * Case0Source: fopen Open and close a file using fopen() and flose()
 * Case1Source: Open a file using fopen()
 * Sinks:
 *    Case1Sink: Do nothing
 *    Case0Sink : Close the file
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

void CWE675_Duplicate_Operations_on_Resource__fopen_18_case0()
{
    FILE * data;
    data = NULL; /* Initialize data */
    goto source;
source:
    data = fopen("Case0Source_fopen.txt", "w+");
    /* NOTE: Close the file in the source */
    fclose(data);
    goto sink;
sink:
    /* NOTE: Close the file in the sink (it may have been closed in the Source) */
    fclose(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2() - use case0source and case1sink by reversing the blocks on the second goto statement */
static void case1V2()
{
    FILE * data;
    data = NULL; /* Initialize data */
    goto source;
source:
    data = fopen("Case0Source_fopen.txt", "w+");
    /* NOTE: Close the file in the source */
    fclose(data);
    goto sink;
sink:
    /* Do nothing */
    /* ALT: Don't close the file in the sink */
    ; /* empty statement needed for some flow variants */
}

/* case1V1() - use case1source and case0sink by reversing the blocks on the first goto statement */
static void case1V1()
{
    FILE * data;
    data = NULL; /* Initialize data */
    goto source;
source:
    /* ALT: Open, but do not close the file in the source */
    data = fopen("Case1Source_fopen.txt", "w+");
    goto sink;
sink:
    /* NOTE: Close the file in the sink (it may have been closed in the Source) */
    fclose(data);
}

void CWE675_Duplicate_Operations_on_Resource__fopen_18_case1()
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
    CWE675_Duplicate_Operations_on_Resource__fopen_18_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE675_Duplicate_Operations_on_Resource__fopen_18_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
