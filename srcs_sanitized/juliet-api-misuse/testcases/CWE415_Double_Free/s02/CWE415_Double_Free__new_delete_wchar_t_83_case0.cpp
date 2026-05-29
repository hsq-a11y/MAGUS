/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_wchar_t_83_case0.cpp
Label Definition File: CWE415_Double_Free__new_delete.label.xml
Template File: sources-sinks-83_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * Case0Source:  Allocate data using new and Deallocae data using delete
 * Case1Source: Allocate data using new
 * Sinks:
 *    Case1Sink: do nothing
 *    Case0Sink : Deallocate data using delete
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE415_Double_Free__new_delete_wchar_t_83.h"

namespace CWE415_Double_Free__new_delete_wchar_t_83
{
CWE415_Double_Free__new_delete_wchar_t_83_case0::CWE415_Double_Free__new_delete_wchar_t_83_case0(wchar_t * dataCopy)
{
    data = dataCopy;
    data = new wchar_t;
    /* NOTE: delete data in the source - the case0 sink deletes data as well */
    delete data;
}

CWE415_Double_Free__new_delete_wchar_t_83_case0::~CWE415_Double_Free__new_delete_wchar_t_83_case0()
{
    /* NOTE: Possibly deleting memory twice */
    delete data;
}
}
#endif /* OMITCASE0 */
