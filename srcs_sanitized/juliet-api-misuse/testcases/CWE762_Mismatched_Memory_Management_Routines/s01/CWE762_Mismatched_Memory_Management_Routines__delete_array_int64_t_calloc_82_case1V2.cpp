/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_array_int64_t_calloc_82_case1V2.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete_array.label.xml
Template File: sources-sinks-82_case1V2.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source: calloc Allocate data using calloc()
 * Case1Source: Allocate data using new []
 * Sinks:
 *    Case1Sink: Deallocate data using free()
 *    Case0Sink : Deallocate data using delete []
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE762_Mismatched_Memory_Management_Routines__delete_array_int64_t_calloc_82.h"

namespace CWE762_Mismatched_Memory_Management_Routines__delete_array_int64_t_calloc_82
{

void CWE762_Mismatched_Memory_Management_Routines__delete_array_int64_t_calloc_82_case1V2::action(int64_t * data)
{
    /* ALT: Free memory using free() */
    free(data);
}

}
#endif /* OMITCASE1 */
