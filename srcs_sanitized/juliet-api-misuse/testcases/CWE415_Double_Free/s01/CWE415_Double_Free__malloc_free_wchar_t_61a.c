/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_wchar_t_61a.c
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-61a.tmpl.c
*/
/*
 * @description
 * CWE: 415 Double Free
 * Case0Source:  Allocate data using malloc() and Deallocate data using free()
 * Case1Source: Allocate data using malloc()
 * Sinks:
 *    Case1Sink: do nothing
 *    Case0Sink : Deallocate data using free()
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

/* case0 function declaration */
wchar_t * CWE415_Double_Free__malloc_free_wchar_t_61b_case0Source(wchar_t * data);

void CWE415_Double_Free__malloc_free_wchar_t_61_case0()
{
    wchar_t * data;
    /* Initialize data */
    data = NULL;
    data = CWE415_Double_Free__malloc_free_wchar_t_61b_case0Source(data);
    /* NOTE: Possibly freeing memory twice */
    free(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
wchar_t * CWE415_Double_Free__malloc_free_wchar_t_61b_case1V1Source(wchar_t * data);

static void case1V1()
{
    wchar_t * data;
    /* Initialize data */
    data = NULL;
    data = CWE415_Double_Free__malloc_free_wchar_t_61b_case1V1Source(data);
    /* NOTE: Possibly freeing memory twice */
    free(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
wchar_t * CWE415_Double_Free__malloc_free_wchar_t_61b_case1V2Source(wchar_t * data);

static void case1V2()
{
    wchar_t * data;
    /* Initialize data */
    data = NULL;
    data = CWE415_Double_Free__malloc_free_wchar_t_61b_case1V2Source(data);
    /* do nothing */
    /* ALT: Don't attempt to free the memory */
    ; /* empty statement needed for some flow variants */
}

void CWE415_Double_Free__malloc_free_wchar_t_61_case1()
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
    CWE415_Double_Free__malloc_free_wchar_t_61_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE415_Double_Free__malloc_free_wchar_t_61_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
