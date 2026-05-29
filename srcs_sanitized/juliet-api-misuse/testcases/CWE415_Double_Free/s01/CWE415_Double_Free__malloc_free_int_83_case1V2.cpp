/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_int_83_case1V2.cpp
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-83_case1V2.tmpl.cpp
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
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE415_Double_Free__malloc_free_int_83.h"

namespace CWE415_Double_Free__malloc_free_int_83
{
CWE415_Double_Free__malloc_free_int_83_case1V2::CWE415_Double_Free__malloc_free_int_83_case1V2(int * dataCopy)
{
    data = dataCopy;
    data = (int *)malloc(100*sizeof(int));
    if (data == NULL) {exit(-1);}
    /* NOTE: Free data in the source - the case0 sink frees data as well */
    free(data);
}

CWE415_Double_Free__malloc_free_int_83_case1V2::~CWE415_Double_Free__malloc_free_int_83_case1V2()
{
    /* do nothing */
    /* ALT: Don't attempt to free the memory */
    ; /* empty statement needed for some flow variants */
}
}
#endif /* OMITCASE1 */
