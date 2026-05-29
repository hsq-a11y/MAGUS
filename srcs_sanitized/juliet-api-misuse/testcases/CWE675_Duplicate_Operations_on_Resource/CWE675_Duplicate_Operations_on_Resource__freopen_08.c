/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__freopen_08.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource.label.xml
Template File: sources-sinks-08.tmpl.c
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * Case0Source: freopen Open and close a file using freopen() and flose()
 * Case1Source: Open a file using fopen()
 * Sinks:
 *    Case1Sink: Do nothing
 *    Case0Sink : Close the file
 * Flow Variant: 08 Control flow: if(staticReturnsTrue()) and if(staticReturnsFalse())
 *
 * */

#include "std_testcase.h"

/* The two function below always return the same value, so a tool
   should be able to identify that calls to the functions will always
   return a fixed value. */
static int staticReturnsTrue()
{
    return 1;
}

static int staticReturnsFalse()
{
    return 0;
}

#ifndef OMITCASE0

void CWE675_Duplicate_Operations_on_Resource__freopen_08_case0()
{
    FILE * data;
    data = NULL; /* Initialize data */
    if(staticReturnsTrue())
    {
        data = freopen("Case0Source_freopen.txt","w+",stdin);
        /* NOTE: Close the file in the source */
        fclose(data);
    }
    if(staticReturnsTrue())
    {
        /* NOTE: Close the file in the sink (it may have been closed in the Source) */
        fclose(data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V21() - use case0source and case1sink by changing the second staticReturnsTrue() to staticReturnsFalse() */
static void case1V21()
{
    FILE * data;
    data = NULL; /* Initialize data */
    if(staticReturnsTrue())
    {
        data = freopen("Case0Source_freopen.txt","w+",stdin);
        /* NOTE: Close the file in the source */
        fclose(data);
    }
    if(staticReturnsFalse())
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

/* case1V22() - use case0source and case1sink by reversing the blocks in the second if */
static void case1V22()
{
    FILE * data;
    data = NULL; /* Initialize data */
    if(staticReturnsTrue())
    {
        data = freopen("Case0Source_freopen.txt","w+",stdin);
        /* NOTE: Close the file in the source */
        fclose(data);
    }
    if(staticReturnsTrue())
    {
        /* Do nothing */
        /* ALT: Don't close the file in the sink */
        ; /* empty statement needed for some flow variants */
    }
}

/* case1V11() - use case1source and case0sink by changing the first staticReturnsTrue() to staticReturnsFalse() */
static void case1V11()
{
    FILE * data;
    data = NULL; /* Initialize data */
    if(staticReturnsFalse())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: Open, but do not close the file in the source */
        data = fopen("Case1Source_fopen.txt", "w+");
    }
    if(staticReturnsTrue())
    {
        /* NOTE: Close the file in the sink (it may have been closed in the Source) */
        fclose(data);
    }
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the first if */
static void case1V12()
{
    FILE * data;
    data = NULL; /* Initialize data */
    if(staticReturnsTrue())
    {
        /* ALT: Open, but do not close the file in the source */
        data = fopen("Case1Source_fopen.txt", "w+");
    }
    if(staticReturnsTrue())
    {
        /* NOTE: Close the file in the sink (it may have been closed in the Source) */
        fclose(data);
    }
}

void CWE675_Duplicate_Operations_on_Resource__freopen_08_case1()
{
    case1V21();
    case1V22();
    case1V11();
    case1V12();
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
    CWE675_Duplicate_Operations_on_Resource__freopen_08_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE675_Duplicate_Operations_on_Resource__freopen_08_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
