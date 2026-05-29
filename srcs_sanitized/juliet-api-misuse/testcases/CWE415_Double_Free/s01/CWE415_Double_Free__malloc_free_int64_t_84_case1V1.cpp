/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_int64_t_84_case1V1.cpp
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-84_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * Case0Source:  Allocate data using malloc() and Deallocate data using free()
 * Case1Source: Allocate data using malloc()
 * Sinks:
 *    Case1Sink: do nothing
 *    Case0Sink : Deallocate data using free()
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE415_Double_Free__malloc_free_int64_t_84.h"

namespace CWE415_Double_Free__malloc_free_int64_t_84
{
CWE415_Double_Free__malloc_free_int64_t_84_case1V1::CWE415_Double_Free__malloc_free_int64_t_84_case1V1(int64_t * dataCopy)
{
    data = dataCopy;
    data = (int64_t *)malloc(100*sizeof(int64_t));
    if (data == NULL) {exit(-1);}
    /* ALT: Do NOT free data in the source - the case0 sink frees data */
}

CWE415_Double_Free__malloc_free_int64_t_84_case1V1::~CWE415_Double_Free__malloc_free_int64_t_84_case1V1()
{
    /* NOTE: Possibly freeing memory twice */
    free(data);
}
}
#endif /* OMITCASE1 */
