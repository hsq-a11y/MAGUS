/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_delete_array_int64_t_81_case1V2.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_delete_array.label.xml
Template File: sources-sinks-81_case1V2.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source:  Allocate data using new
 * Case1Source: Allocate data using new []
 * Sinks:
 *    Case1Sink: Deallocate data using delete
 *    Case0Sink : Deallocate data using delete []
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE762_Mismatched_Memory_Management_Routines__new_delete_array_int64_t_81.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_delete_array_int64_t_81
{

void CWE762_Mismatched_Memory_Management_Routines__new_delete_array_int64_t_81_case1V2::action(int64_t * data) const
{
    /* ALT: Deallocate the memory using delete */
    delete data;
}

}
#endif /* OMITCASE1 */
