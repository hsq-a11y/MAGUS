/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_int64_t_61b.c
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-61b.tmpl.c
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

int64_t * CWE415_Double_Free__malloc_free_int64_t_61b_case0Source(int64_t * data)
{
    data = (int64_t *)malloc(100*sizeof(int64_t));
    if (data == NULL) {exit(-1);}
    /* NOTE: Free data in the source - the case0 sink frees data as well */
    free(data);
    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
int64_t * CWE415_Double_Free__malloc_free_int64_t_61b_case1V1Source(int64_t * data)
{
    data = (int64_t *)malloc(100*sizeof(int64_t));
    if (data == NULL) {exit(-1);}
    /* ALT: Do NOT free data in the source - the case0 sink frees data */
    return data;
}

/* case1V2() uses the Case0Source with the Case1Sink */
int64_t * CWE415_Double_Free__malloc_free_int64_t_61b_case1V2Source(int64_t * data)
{
    data = (int64_t *)malloc(100*sizeof(int64_t));
    if (data == NULL) {exit(-1);}
    /* NOTE: Free data in the source - the case0 sink frees data as well */
    free(data);
    return data;
}

#endif /* OMITCASE1 */
