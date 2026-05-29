/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_long_83_case0.cpp
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-83_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * Case0Source:  Allocate data using malloc() and Deallocate data using free()
 * Case1Source: Allocate data using malloc()
 * Sinks:
 *    Case1Sink: do nothing
 *    Case0Sink : Deallocate data using free()
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE415_Double_Free__malloc_free_long_83.h"

namespace CWE415_Double_Free__malloc_free_long_83
{
CWE415_Double_Free__malloc_free_long_83_case0::CWE415_Double_Free__malloc_free_long_83_case0(long * dataCopy)
{
    data = dataCopy;
    data = (long *)malloc(100*sizeof(long));
    if (data == NULL) {exit(-1);}
    /* NOTE: Free data in the source - the case0 sink frees data as well */
    free(data);
}

CWE415_Double_Free__malloc_free_long_83_case0::~CWE415_Double_Free__malloc_free_long_83_case0()
{
    /* NOTE: Possibly freeing memory twice */
    free(data);
}
}
#endif /* OMITCASE0 */
