/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_array_int64_t_calloc_83_case1V1.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete_array.label.xml
Template File: sources-sinks-83_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source: calloc Allocate data using calloc()
 * Case1Source: Allocate data using new []
 * Sinks:
 *    Case1Sink: Deallocate data using free()
 *    Case0Sink : Deallocate data using delete []
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE762_Mismatched_Memory_Management_Routines__delete_array_int64_t_calloc_83.h"

namespace CWE762_Mismatched_Memory_Management_Routines__delete_array_int64_t_calloc_83
{
CWE762_Mismatched_Memory_Management_Routines__delete_array_int64_t_calloc_83_case1V1::CWE762_Mismatched_Memory_Management_Routines__delete_array_int64_t_calloc_83_case1V1(int64_t * dataCopy)
{
    data = dataCopy;
    /* ALT: Allocate memory using new [] */
    data = new int64_t[100];
}

CWE762_Mismatched_Memory_Management_Routines__delete_array_int64_t_calloc_83_case1V1::~CWE762_Mismatched_Memory_Management_Routines__delete_array_int64_t_calloc_83_case1V1()
{
    /* NOTE: Deallocate memory using delete [] - the source memory allocation function may
     * require a call to free() to deallocate the memory */
    delete [] data;
}
}
#endif /* OMITCASE1 */
