/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_wchar_t_68b.cpp
Label Definition File: CWE415_Double_Free__new_delete.label.xml
Template File: sources-sinks-68b.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * Case0Source:  Allocate data using new and Deallocae data using delete
 * Case1Source: Allocate data using new
 * Sinks:
 *    Case1Sink: do nothing
 *    Case0Sink : Deallocate data using delete
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__new_delete_wchar_t_68
{

extern wchar_t * case0Data;
extern wchar_t * case1V1Data;
extern wchar_t * case1V2Data;

#ifndef OMITCASE0

void case0Sink()
{
    wchar_t * data = case0Data;
    /* NOTE: Possibly deleting memory twice */
    delete data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink()
{
    wchar_t * data = case1V1Data;
    /* NOTE: Possibly deleting memory twice */
    delete data;
}

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Sink()
{
    wchar_t * data = case1V2Data;
    /* do nothing */
    /* ALT: Don't attempt to delete the memory */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITCASE1 */

} /* close namespace */
