/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_delete_array_wchar_t_83_case0.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_delete_array.label.xml
Template File: sources-sinks-83_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source:  Allocate data using new
 * Case1Source: Allocate data using new []
 * Sinks:
 *    Case1Sink: Deallocate data using delete
 *    Case0Sink : Deallocate data using delete []
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE762_Mismatched_Memory_Management_Routines__new_delete_array_wchar_t_83.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_delete_array_wchar_t_83
{
CWE762_Mismatched_Memory_Management_Routines__new_delete_array_wchar_t_83_case0::CWE762_Mismatched_Memory_Management_Routines__new_delete_array_wchar_t_83_case0(wchar_t * dataCopy)
{
    data = dataCopy;
    /* NOTE: Allocate memory with a function that requires delete to free the memory */
    data = new wchar_t;
}

CWE762_Mismatched_Memory_Management_Routines__new_delete_array_wchar_t_83_case0::~CWE762_Mismatched_Memory_Management_Routines__new_delete_array_wchar_t_83_case0()
{
    /* NOTE: Deallocate memory using delete [] - the source memory allocation function may
     * require a call to delete to deallocate the memory */
    delete [] data;
}
}
#endif /* OMITCASE0 */
