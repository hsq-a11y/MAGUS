/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__fopen_21.c
Label Definition File: CWE690_NULL_Deref_From_Return.fclose.label.xml
Template File: source-sinks-21.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: fopen Open data with fopen()
 * Sinks: 0
 *    Case1Sink: Check data for NULL
 *    Case0Sink : Do not check data for NULL
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
        /* NOTE: if the fopen failed, data will be NULL here */
        fclose(data);
    }
}

void CWE690_NULL_Deref_From_Return__fopen_21_case0()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    /* NOTE: Open a file without checking the return value for NULL */
    data = fopen("file.txt", "w+");
    case0Static = 1; /* true */
    case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The static variables below are used to drive control flow in the sink functions. */
static int case1V21Static = 0;
static int case1V22Static = 0;

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
        /* ALT: check the return value */
        if (data != NULL)
        {
            fclose(data);
        }
    }
}

static void case1V21()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    /* NOTE: Open a file without checking the return value for NULL */
    data = fopen("file.txt", "w+");
    case1V21Static = 0; /* false */
    case1V21Sink(data);
}

/* case1V22() - use case0source and case1sink by reversing the blocks in the if in the sink function */
static void case1V22Sink(FILE * data)
{
    if(case1V22Static)
    {
        /* ALT: check the return value */
        if (data != NULL)
        {
            fclose(data);
        }
    }
}

static void case1V22()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    /* NOTE: Open a file without checking the return value for NULL */
    data = fopen("file.txt", "w+");
    case1V22Static = 1; /* true */
    case1V22Sink(data);
}

void CWE690_NULL_Deref_From_Return__fopen_21_case1()
{
    case1V21();
    case1V22();
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
    CWE690_NULL_Deref_From_Return__fopen_21_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE690_NULL_Deref_From_Return__fopen_21_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
