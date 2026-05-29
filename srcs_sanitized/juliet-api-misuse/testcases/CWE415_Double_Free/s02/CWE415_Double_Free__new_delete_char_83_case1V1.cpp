/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_char_83_case1V1.cpp
Label Definition File: CWE415_Double_Free__new_delete.label.xml
Template File: sources-sinks-83_case1V1.tmpl.cpp
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
#include "CWE415_Double_Free__new_delete_char_83.h"

namespace CWE415_Double_Free__new_delete_char_83
{
CWE415_Double_Free__new_delete_char_83_case1V1::CWE415_Double_Free__new_delete_char_83_case1V1(char * dataCopy)
{
    data = dataCopy;
    data = new char;
    /* ALT: Do NOT delete data in the source - the case0 sink deletes data */
}

CWE415_Double_Free__new_delete_char_83_case1V1::~CWE415_Double_Free__new_delete_char_83_case1V1()
{
    /* NOTE: Possibly deleting memory twice */
    delete data;
}
}
#endif /* OMITCASE1 */
