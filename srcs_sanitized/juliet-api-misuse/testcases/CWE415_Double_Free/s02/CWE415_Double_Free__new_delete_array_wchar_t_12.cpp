/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_array_wchar_t_12.cpp
Label Definition File: CWE415_Double_Free__new_delete_array.label.xml
Template File: sources-sinks-12.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * Case0Source:  Allocate data using new and Deallocae data using delete
 * Case1Source: Allocate data using new
 * Sinks:
 *    Case1Sink: do nothing
 *    Case0Sink : Deallocate data using delete
 * Flow Variant: 12 Control flow: if(globalReturnsTrueOrFalse())
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__new_delete_array_wchar_t_12
{

#ifndef OMITCASE0

void case0()
{
    wchar_t * data;
    /* Initialize data */
    data = NULL;
    if(globalReturnsTrueOrFalse())
    {
        data = new wchar_t[100];
        /* NOTE: delete the array data in the source - the case0 sink deletes the array data as well */
        delete [] data;
    }
    else
    {
        data = new wchar_t[100];
        /* ALT: Do NOT delete the array data in the source - the case0 sink deletes the array data */
    }
    if(globalReturnsTrueOrFalse())
    {
        /* NOTE: Possibly deleting memory twice */
        delete [] data;
    }
    else
    {
        /* do nothing */
        /* ALT: Don't attempt to delete the memory */
        ; /* empty statement needed for some flow variants */
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2() - use case0source and case1sink by changing the first "if" so that
   both branches use the Case0Source and the second "if" so that both branches
   use the Case1Sink */
static void case1V2()
{
    wchar_t * data;
    /* Initialize data */
    data = NULL;
    if(globalReturnsTrueOrFalse())
    {
        data = new wchar_t[100];
        /* NOTE: delete the array data in the source - the case0 sink deletes the array data as well */
        delete [] data;
    }
    else
    {
        data = new wchar_t[100];
        /* NOTE: delete the array data in the source - the case0 sink deletes the array data as well */
        delete [] data;
    }
    if(globalReturnsTrueOrFalse())
    {
        /* do nothing */
        /* ALT: Don't attempt to delete the memory */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* do nothing */
        /* ALT: Don't attempt to delete the memory */
        ; /* empty statement needed for some flow variants */
    }
}

/* case1V1() - use case1source and case0sink by changing the first "if" so that
   both branches use the Case1Source and the second "if" so that both branches
   use the Case0Sink */
static void case1V1()
{
    wchar_t * data;
    /* Initialize data */
    data = NULL;
    if(globalReturnsTrueOrFalse())
    {
        data = new wchar_t[100];
        /* ALT: Do NOT delete the array data in the source - the case0 sink deletes the array data */
    }
    else
    {
        data = new wchar_t[100];
        /* ALT: Do NOT delete the array data in the source - the case0 sink deletes the array data */
    }
    if(globalReturnsTrueOrFalse())
    {
        /* NOTE: Possibly deleting memory twice */
        delete [] data;
    }
    else
    {
        /* NOTE: Possibly deleting memory twice */
        delete [] data;
    }
}

void case1()
{
    case1V2();
    case1V1();
}

#endif /* OMITCASE1 */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE415_Double_Free__new_delete_array_wchar_t_12; /* so that we can use case1 and case0 easily */

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
