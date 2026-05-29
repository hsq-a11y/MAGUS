/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__freopen_21.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource.label.xml
Template File: sources-sinks-21.tmpl.c
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * Case0Source: freopen Open and close a file using freopen() and flose()
 * Case1Source: Open a file using fopen()
 * Sinks:
 *    Case1Sink: Do nothing
 *    Case0Sink : Close the file
 * Flow Variant: 21 Control flow: Flow controlled by value of a static global variable. All functions contained in one file.
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

/* The static variable below is used to drive control flow in the sink function */
static int case0Static = 0;

static void case0Sink(FILE * data)
{
    if(case0Static)
    {
        /* NOTE: Close the file in the sink (it may have been closed in the Source) */
        fclose(data);
    }
}

void CWE675_Duplicate_Operations_on_Resource__freopen_21_case0()
{
    FILE * data;
    data = NULL; /* Initialize data */
    data = freopen("Case0Source_freopen.txt","w+",stdin);
    /* NOTE: Close the file in the source */
    fclose(data);
    case0Static = 1; /* true */
    case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The static variables below are used to drive control flow in the sink functions. */
static int case1V21Static = 0;
static int case1V22Static = 0;
static int case1V1Static = 0;

/* case1V21() - use case0source and case1sink by setting the static variable to false instead of true */
static void case1V21Sink(FILE * data)
{
    if(case1V21Static)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* Do nothing */
        /* ALT: Don't close the file in the sink */
        ; /* empty statement needed for some flow variants */
    }
}

static void case1V21()
{
    FILE * data;
    data = NULL; /* Initialize data */
    data = freopen("Case0Source_freopen.txt","w+",stdin);
    /* NOTE: Close the file in the source */
    fclose(data);
    case1V21Static = 0; /* false */
    case1V21Sink(data);
}

/* case1V22() - use case0source and case1sink by reversing the blocks in the if in the sink function */
static void case1V22Sink(FILE * data)
{
    if(case1V22Static)
    {
        /* Do nothing */
        /* ALT: Don't close the file in the sink */
        ; /* empty statement needed for some flow variants */
    }
}

static void case1V22()
{
    FILE * data;
    data = NULL; /* Initialize data */
    data = freopen("Case0Source_freopen.txt","w+",stdin);
    /* NOTE: Close the file in the source */
    fclose(data);
    case1V22Static = 1; /* true */
    case1V22Sink(data);
}

/* case1V1() - use case1source and case0sink */
static void case1V1Sink(FILE * data)
{
    if(case1V1Static)
    {
        /* NOTE: Close the file in the sink (it may have been closed in the Source) */
        fclose(data);
    }
}

static void case1V1()
{
    FILE * data;
    data = NULL; /* Initialize data */
    /* ALT: Open, but do not close the file in the source */
    data = fopen("Case1Source_fopen.txt", "w+");
    case1V1Static = 1; /* true */
    case1V1Sink(data);
}

void CWE675_Duplicate_Operations_on_Resource__freopen_21_case1()
{
    case1V21();
    case1V22();
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
    CWE675_Duplicate_Operations_on_Resource__freopen_21_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE675_Duplicate_Operations_on_Resource__freopen_21_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
