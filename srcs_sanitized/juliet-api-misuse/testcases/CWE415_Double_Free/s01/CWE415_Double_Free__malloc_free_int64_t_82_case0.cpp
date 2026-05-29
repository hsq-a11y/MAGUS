/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_int64_t_82_case0.cpp
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-82_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * Case0Source:  Allocate data using malloc() and Deallocate data using free()
 * Case1Source: Allocate data using malloc()
 * Sinks:
 *    Case1Sink: do nothing
 *    Case0Sink : Deallocate data using free()
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE415_Double_Free__malloc_free_int64_t_82.h"

namespace CWE415_Double_Free__malloc_free_int64_t_82
{

void CWE415_Double_Free__malloc_free_int64_t_82_case0::action(int64_t * data)
{
    /* NOTE: Possibly freeing memory twice */
    free(data);
}

}
#endif /* OMITCASE0 */
