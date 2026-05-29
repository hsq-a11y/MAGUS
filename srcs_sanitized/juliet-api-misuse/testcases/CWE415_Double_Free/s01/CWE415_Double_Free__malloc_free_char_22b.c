/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_char_22b.c
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 415 Double Free
 * Case0Source:  Allocate data using malloc() and Deallocate data using free()
 * Case1Source: Allocate data using malloc()
 * Sinks:
 *    Case1Sink: do nothing
 *    Case0Sink : Deallocate data using free()
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the sink function */
extern int CWE415_Double_Free__malloc_free_char_22_case0Global;

void CWE415_Double_Free__malloc_free_char_22_case0Sink(char * data)
{
    if(CWE415_Double_Free__malloc_free_char_22_case0Global)
    {
        /* NOTE: Possibly freeing memory twice */
        free(data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the sink functions. */
extern int CWE415_Double_Free__malloc_free_char_22_case1V21Global;
extern int CWE415_Double_Free__malloc_free_char_22_case1V22Global;
extern int CWE415_Double_Free__malloc_free_char_22_case1V1Global;

/* case1V21() - use case0source and case1sink by setting the static variable to false instead of true */
void CWE415_Double_Free__malloc_free_char_22_case1V21Sink(char * data)
{
    if(CWE415_Double_Free__malloc_free_char_22_case1V21Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* do nothing */
        /* ALT: Don't attempt to free the memory */
        ; /* empty statement needed for some flow variants */
    }
}

/* case1V22() - use case0source and case1sink by reversing the blocks in the if in the sink function */
void CWE415_Double_Free__malloc_free_char_22_case1V22Sink(char * data)
{
    if(CWE415_Double_Free__malloc_free_char_22_case1V22Global)
    {
        /* do nothing */
        /* ALT: Don't attempt to free the memory */
        ; /* empty statement needed for some flow variants */
    }
}

/* case1V1() - use case1source and case0sink */
void CWE415_Double_Free__malloc_free_char_22_case1V1Sink(char * data)
{
    if(CWE415_Double_Free__malloc_free_char_22_case1V1Global)
    {
        /* NOTE: Possibly freeing memory twice */
        free(data);
    }
}

#endif /* OMITCASE1 */
