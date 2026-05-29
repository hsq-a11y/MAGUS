/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_wchar_t_67b.c
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 415 Double Free
 * Case0Source:  Allocate data using malloc() and Deallocate data using free()
 * Case1Source: Allocate data using malloc()
 * Sinks:
 *    Case1Sink: do nothing
 *    Case0Sink : Deallocate data using free()
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE415_Double_Free__malloc_free_wchar_t_67_structType
{
    wchar_t * structFirst;
} CWE415_Double_Free__malloc_free_wchar_t_67_structType;

#ifndef OMITCASE0

void CWE415_Double_Free__malloc_free_wchar_t_67b_case0Sink(CWE415_Double_Free__malloc_free_wchar_t_67_structType myStruct)
{
    wchar_t * data = myStruct.structFirst;
    /* NOTE: Possibly freeing memory twice */
    free(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE415_Double_Free__malloc_free_wchar_t_67b_case1V1Sink(CWE415_Double_Free__malloc_free_wchar_t_67_structType myStruct)
{
    wchar_t * data = myStruct.structFirst;
    /* NOTE: Possibly freeing memory twice */
    free(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE415_Double_Free__malloc_free_wchar_t_67b_case1V2Sink(CWE415_Double_Free__malloc_free_wchar_t_67_structType myStruct)
{
    wchar_t * data = myStruct.structFirst;
    /* do nothing */
    /* ALT: Don't attempt to free the memory */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITCASE1 */
