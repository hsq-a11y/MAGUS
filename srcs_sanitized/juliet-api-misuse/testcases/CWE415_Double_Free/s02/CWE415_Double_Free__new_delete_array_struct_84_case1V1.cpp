/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_array_struct_84_case1V1.cpp
Label Definition File: CWE415_Double_Free__new_delete_array.label.xml
Template File: sources-sinks-84_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * Case0Source:  Allocate data using new and Deallocae data using delete
 * Case1Source: Allocate data using new
 * Sinks:
 *    Case1Sink: do nothing
 *    Case0Sink : Deallocate data using delete
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE415_Double_Free__new_delete_array_struct_84.h"

namespace CWE415_Double_Free__new_delete_array_struct_84
{
CWE415_Double_Free__new_delete_array_struct_84_case1V1::CWE415_Double_Free__new_delete_array_struct_84_case1V1(twoIntsStruct * dataCopy)
{
    data = dataCopy;
    data = new twoIntsStruct[100];
    /* ALT: Do NOT delete the array data in the source - the case0 sink deletes the array data */
}

CWE415_Double_Free__new_delete_array_struct_84_case1V1::~CWE415_Double_Free__new_delete_array_struct_84_case1V1()
{
    /* NOTE: Possibly deleting memory twice */
    delete [] data;
}
}
#endif /* OMITCASE1 */
