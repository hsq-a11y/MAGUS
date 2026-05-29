/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_char_81_case0.cpp
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-81_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * Case0Source:  Allocate data using malloc() and Deallocate data using free()
 * Case1Source: Allocate data using malloc()
 * Sinks:
 *    Case1Sink: do nothing
 *    Case0Sink : Deallocate data using free()
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE415_Double_Free__malloc_free_char_81.h"

namespace CWE415_Double_Free__malloc_free_char_81
{

void CWE415_Double_Free__malloc_free_char_81_case0::action(char * data) const
{
    /* NOTE: Possibly freeing memory twice */
    free(data);
}

}
#endif /* OMITCASE0 */
