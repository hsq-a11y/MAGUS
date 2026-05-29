/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_int64_t_calloc_84_case1V2.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete.label.xml
Template File: sources-sinks-84_case1V2.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source: calloc Allocate data using calloc()
 * Case1Source: Allocate data using new
 * Sinks:
 *    Case1Sink: Deallocate data using free()
 *    Case0Sink : Deallocate data using delete
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE762_Mismatched_Memory_Management_Routines__delete_int64_t_calloc_84.h"

namespace CWE762_Mismatched_Memory_Management_Routines__delete_int64_t_calloc_84
{
CWE762_Mismatched_Memory_Management_Routines__delete_int64_t_calloc_84_case1V2::CWE762_Mismatched_Memory_Management_Routines__delete_int64_t_calloc_84_case1V2(int64_t * dataCopy)
{
    data = dataCopy;
    /* NOTE: Allocate memory with a function that requires free() to free the memory */
    data = (int64_t *)calloc(100, sizeof(int64_t));
    if (data == NULL) {exit(-1);}
}

CWE762_Mismatched_Memory_Management_Routines__delete_int64_t_calloc_84_case1V2::~CWE762_Mismatched_Memory_Management_Routines__delete_int64_t_calloc_84_case1V2()
{
    /* ALT: Deallocate the memory using free() */
    free(data);
}
}
#endif /* OMITCASE1 */
