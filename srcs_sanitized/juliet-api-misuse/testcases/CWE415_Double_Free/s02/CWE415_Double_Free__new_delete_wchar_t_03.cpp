/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_wchar_t_03.cpp
Label Definition File: CWE415_Double_Free__new_delete.label.xml
Template File: sources-sinks-03.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * Case0Source:  Allocate data using new and Deallocae data using delete
 * Case1Source: Allocate data using new
 * Sinks:
 *    Case1Sink: do nothing
 *    Case0Sink : Deallocate data using delete
 * Flow Variant: 03 Control flow: if(5==5) and if(5!=5)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__new_delete_wchar_t_03
{

#ifndef OMITCASE0

void case0()
{
    wchar_t * data;
    /* Initialize data */
    data = NULL;
    if(5==5)
    {
        data = new wchar_t;
        /* NOTE: delete data in the source - the case0 sink deletes data as well */
        delete data;
    }
    if(5==5)
    {
        /* NOTE: Possibly deleting memory twice */
        delete data;
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V21() - use case0source and case1sink by changing the second 5==5 to 5!=5 */
static void case1V21()
{
    wchar_t * data;
    /* Initialize data */
    data = NULL;
    if(5==5)
    {
        data = new wchar_t;
        /* NOTE: delete data in the source - the case0 sink deletes data as well */
        delete data;
    }
    if(5!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* do nothing */
        /* ALT: Don't attempt to delete the memory */
        ; /* empty statement needed for some flow variants */
    }
}

/* case1V22() - use case0source and case1sink by reversing the blocks in the second if */
static void case1V22()
{
    wchar_t * data;
    /* Initialize data */
    data = NULL;
    if(5==5)
    {
        data = new wchar_t;
        /* NOTE: delete data in the source - the case0 sink deletes data as well */
        delete data;
    }
    if(5==5)
    {
        /* do nothing */
        /* ALT: Don't attempt to delete the memory */
        ; /* empty statement needed for some flow variants */
    }
}

/* case1V11() - use case1source and case0sink by changing the first 5==5 to 5!=5 */
static void case1V11()
{
    wchar_t * data;
    /* Initialize data */
    data = NULL;
    if(5!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        data = new wchar_t;
        /* ALT: Do NOT delete data in the source - the case0 sink deletes data */
    }
    if(5==5)
    {
        /* NOTE: Possibly deleting memory twice */
        delete data;
    }
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the first if */
static void case1V12()
{
    wchar_t * data;
    /* Initialize data */
    data = NULL;
    if(5==5)
    {
        data = new wchar_t;
        /* ALT: Do NOT delete data in the source - the case0 sink deletes data */
    }
    if(5==5)
    {
        /* NOTE: Possibly deleting memory twice */
        delete data;
    }
}

void case1()
{
    case1V21();
    case1V22();
    case1V11();
    case1V12();
}

#endif /* OMITCASE1 */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE415_Double_Free__new_delete_wchar_t_03; /* so that we can use case1 and case0 easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITCASE1
    printLine("Calling case1()...");
    case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
