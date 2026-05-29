/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__fopen_44.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource.label.xml
Template File: sources-sinks-44.tmpl.c
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * Case0Source: fopen Open and close a file using fopen() and flose()
 * Case1Source: Open a file using fopen()
 * Sinks:
 *    Case1Sink: Do nothing
 *    Case0Sink : Close the file
 * Flow Variant: 44 Data/control flow: data passed as an argument from one function to a function in the same source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

static void case0Sink(FILE * data)
{
    /* NOTE: Close the file in the sink (it may have been closed in the Source) */
    fclose(data);
}

void CWE675_Duplicate_Operations_on_Resource__fopen_44_case0()
{
    FILE * data;
    /* define a function pointer */
    void (*funcPtr) (FILE *) = case0Sink;
    data = NULL; /* Initialize data */
    data = fopen("Case0Source_fopen.txt", "w+");
    /* NOTE: Close the file in the source */
    fclose(data);
    /* use the function pointer */
    funcPtr(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
static void case1V1Sink(FILE * data)
{
    /* NOTE: Close the file in the sink (it may have been closed in the Source) */
    fclose(data);
}

static void case1V1()
{
    FILE * data;
    void (*funcPtr) (FILE *) = case1V1Sink;
    data = NULL; /* Initialize data */
    /* ALT: Open, but do not close the file in the source */
    data = fopen("Case1Source_fopen.txt", "w+");
    funcPtr(data);
}

/* case1V2() uses the Case0Source with the Case1Sink */
static void case1V2Sink(FILE * data)
{
    /* Do nothing */
    /* ALT: Don't close the file in the sink */
    ; /* empty statement needed for some flow variants */
}

static void case1V2()
{
    FILE * data;
    void (*funcPtr) (FILE *) = case1V2Sink;
    data = NULL; /* Initialize data */
    data = fopen("Case0Source_fopen.txt", "w+");
    /* NOTE: Close the file in the source */
    fclose(data);
    funcPtr(data);
}

void CWE675_Duplicate_Operations_on_Resource__fopen_44_case1()
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
    CWE675_Duplicate_Operations_on_Resource__fopen_44_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE675_Duplicate_Operations_on_Resource__fopen_44_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
