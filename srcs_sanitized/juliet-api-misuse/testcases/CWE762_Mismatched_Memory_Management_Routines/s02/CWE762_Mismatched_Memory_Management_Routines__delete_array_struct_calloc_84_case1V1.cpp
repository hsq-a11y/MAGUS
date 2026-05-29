/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_array_struct_calloc_84_case1V1.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete_array.label.xml
Template File: sources-sinks-84_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source: calloc Allocate data using calloc()
 * Case1Source: Allocate data using new []
 * Sinks:
 *    Case1Sink: Deallocate data using free()
 *    Case0Sink : Deallocate data using delete []
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE762_Mismatched_Memory_Management_Routines__delete_array_struct_calloc_84.h"

namespace CWE762_Mismatched_Memory_Management_Routines__delete_array_struct_calloc_84
{
CWE762_Mismatched_Memory_Management_Routines__delete_array_struct_calloc_84_case1V1::CWE762_Mismatched_Memory_Management_Routines__delete_array_struct_calloc_84_case1V1(twoIntsStruct * dataCopy)
{
    data = dataCopy;
    /* ALT: Allocate memory using new [] */
    data = new twoIntsStruct[100];
}

CWE762_Mismatched_Memory_Management_Routines__delete_array_struct_calloc_84_case1V1::~CWE762_Mismatched_Memory_Management_Routines__delete_array_struct_calloc_84_case1V1()
{
    /* NOTE: Deallocate memory using delete [] - the source memory allocation function may
     * require a call to free() to deallocate the memory */
    delete [] data;
}
}
#endif /* OMITCASE1 */
