/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_int64_t_53c.c
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-53c.tmpl.c
*/
/*
 * @description
 * CWE: 415 Double Free
 * Case0Source:  Allocate data using malloc() and Deallocate data using free()
 * Case1Source: Allocate data using malloc()
 * Sinks:
 *    Case1Sink: do nothing
 *    Case0Sink : Deallocate data using free()
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

/* case0 function declaration */
void CWE415_Double_Free__malloc_free_int64_t_53d_case0Sink(int64_t * data);

void CWE415_Double_Free__malloc_free_int64_t_53c_case0Sink(int64_t * data)
{
    CWE415_Double_Free__malloc_free_int64_t_53d_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE415_Double_Free__malloc_free_int64_t_53d_case1V1Sink(int64_t * data);

void CWE415_Double_Free__malloc_free_int64_t_53c_case1V1Sink(int64_t * data)
{
    CWE415_Double_Free__malloc_free_int64_t_53d_case1V1Sink(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE415_Double_Free__malloc_free_int64_t_53d_case1V2Sink(int64_t * data);

void CWE415_Double_Free__malloc_free_int64_t_53c_case1V2Sink(int64_t * data)
{
    CWE415_Double_Free__malloc_free_int64_t_53d_case1V2Sink(data);
}

#endif /* OMITCASE1 */
