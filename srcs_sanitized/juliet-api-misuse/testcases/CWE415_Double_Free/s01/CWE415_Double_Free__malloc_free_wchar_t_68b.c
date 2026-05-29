/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_wchar_t_68b.c
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 415 Double Free
 * Case0Source:  Allocate data using malloc() and Deallocate data using free()
 * Case1Source: Allocate data using malloc()
 * Sinks:
 *    Case1Sink: do nothing
 *    Case0Sink : Deallocate data using free()
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

extern wchar_t * CWE415_Double_Free__malloc_free_wchar_t_68_case0Data;
extern wchar_t * CWE415_Double_Free__malloc_free_wchar_t_68_case1V1Data;
extern wchar_t * CWE415_Double_Free__malloc_free_wchar_t_68_case1V2Data;

#ifndef OMITCASE0

void CWE415_Double_Free__malloc_free_wchar_t_68b_case0Sink()
{
    wchar_t * data = CWE415_Double_Free__malloc_free_wchar_t_68_case0Data;
    /* NOTE: Possibly freeing memory twice */
    free(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE415_Double_Free__malloc_free_wchar_t_68b_case1V1Sink()
{
    wchar_t * data = CWE415_Double_Free__malloc_free_wchar_t_68_case1V1Data;
    /* NOTE: Possibly freeing memory twice */
    free(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE415_Double_Free__malloc_free_wchar_t_68b_case1V2Sink()
{
    wchar_t * data = CWE415_Double_Free__malloc_free_wchar_t_68_case1V2Data;
    /* do nothing */
    /* ALT: Don't attempt to free the memory */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITCASE1 */
