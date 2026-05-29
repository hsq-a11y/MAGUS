/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_array_long_83_case1V2.cpp
Label Definition File: CWE415_Double_Free__new_delete_array.label.xml
Template File: sources-sinks-83_case1V2.tmpl.cpp
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
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE415_Double_Free__new_delete_array_long_83.h"

namespace CWE415_Double_Free__new_delete_array_long_83
{
CWE415_Double_Free__new_delete_array_long_83_case1V2::CWE415_Double_Free__new_delete_array_long_83_case1V2(long * dataCopy)
{
    data = dataCopy;
    data = new long[100];
    /* NOTE: delete the array data in the source - the case0 sink deletes the array data as well */
    delete [] data;
}

CWE415_Double_Free__new_delete_array_long_83_case1V2::~CWE415_Double_Free__new_delete_array_long_83_case1V2()
{
    /* do nothing */
    /* ALT: Don't attempt to delete the memory */
    ; /* empty statement needed for some flow variants */
}
}
#endif /* OMITCASE1 */
