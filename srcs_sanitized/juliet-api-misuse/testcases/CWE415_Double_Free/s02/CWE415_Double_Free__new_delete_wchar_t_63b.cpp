/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_wchar_t_63b.cpp
Label Definition File: CWE415_Double_Free__new_delete.label.xml
Template File: sources-sinks-63b.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * Case0Source:  Allocate data using new and Deallocae data using delete
 * Case1Source: Allocate data using new
 * Sinks:
 *    Case1Sink: do nothing
 *    Case0Sink : Deallocate data using delete
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__new_delete_wchar_t_63
{

#ifndef OMITCASE0

void case0Sink(wchar_t * * dataPtr)
{
    wchar_t * data = *dataPtr;
    /* NOTE: Possibly deleting memory twice */
    delete data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink(wchar_t * * dataPtr)
{
    wchar_t * data = *dataPtr;
    /* NOTE: Possibly deleting memory twice */
    delete data;
}

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Sink(wchar_t * * dataPtr)
{
    wchar_t * data = *dataPtr;
    /* do nothing */
    /* ALT: Don't attempt to delete the memory */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITCASE1 */

} /* close namespace */
