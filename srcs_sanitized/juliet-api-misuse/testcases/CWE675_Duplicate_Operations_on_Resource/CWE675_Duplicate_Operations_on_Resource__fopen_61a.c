/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__fopen_61a.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource.label.xml
Template File: sources-sinks-61a.tmpl.c
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * Case0Source: fopen Open and close a file using fopen() and flose()
 * Case1Source: Open a file using fopen()
 * Sinks:
 *    Case1Sink: Do nothing
 *    Case0Sink : Close the file
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

/* case0 function declaration */
FILE * CWE675_Duplicate_Operations_on_Resource__fopen_61b_case0Source(FILE * data);

void CWE675_Duplicate_Operations_on_Resource__fopen_61_case0()
{
    FILE * data;
    data = NULL; /* Initialize data */
    data = CWE675_Duplicate_Operations_on_Resource__fopen_61b_case0Source(data);
    /* NOTE: Close the file in the sink (it may have been closed in the Source) */
    fclose(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
FILE * CWE675_Duplicate_Operations_on_Resource__fopen_61b_case1V1Source(FILE * data);

static void case1V1()
{
    FILE * data;
    data = NULL; /* Initialize data */
    data = CWE675_Duplicate_Operations_on_Resource__fopen_61b_case1V1Source(data);
    /* NOTE: Close the file in the sink (it may have been closed in the Source) */
    fclose(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
FILE * CWE675_Duplicate_Operations_on_Resource__fopen_61b_case1V2Source(FILE * data);

static void case1V2()
{
    FILE * data;
    data = NULL; /* Initialize data */
    data = CWE675_Duplicate_Operations_on_Resource__fopen_61b_case1V2Source(data);
    /* Do nothing */
    /* ALT: Don't close the file in the sink */
    ; /* empty statement needed for some flow variants */
}

void CWE675_Duplicate_Operations_on_Resource__fopen_61_case1()
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
    CWE675_Duplicate_Operations_on_Resource__fopen_61_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE675_Duplicate_Operations_on_Resource__fopen_61_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
