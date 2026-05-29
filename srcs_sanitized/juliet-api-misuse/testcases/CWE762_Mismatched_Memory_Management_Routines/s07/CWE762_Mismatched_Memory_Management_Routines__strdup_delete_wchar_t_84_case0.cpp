/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__strdup_delete_wchar_t_84_case0.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__strdup_delete.label.xml
Template File: sources-sinks-84_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source:  Allocate data using wcsdup()
 * Case1Source: Allocate data using new
 * Sinks:
 *    Case1Sink: Deallocate data using free()
 *    Case0Sink : Deallocate data using delete
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE762_Mismatched_Memory_Management_Routines__strdup_delete_wchar_t_84.h"

namespace CWE762_Mismatched_Memory_Management_Routines__strdup_delete_wchar_t_84
{
CWE762_Mismatched_Memory_Management_Routines__strdup_delete_wchar_t_84_case0::CWE762_Mismatched_Memory_Management_Routines__strdup_delete_wchar_t_84_case0(wchar_t * dataCopy)
{
    data = dataCopy;
    {
        wchar_t myString[] = L"myString";
        /* NOTE: Allocate memory from the heap using a function that requires free() for deallocation */
        data = wcsdup(myString);
    }
}

CWE762_Mismatched_Memory_Management_Routines__strdup_delete_wchar_t_84_case0::~CWE762_Mismatched_Memory_Management_Routines__strdup_delete_wchar_t_84_case0()
{
    /* NOTE: Deallocate memory using delete - the source memory allocation function may
     * require a call to free() to deallocate the memory */
    delete data;
}
}
#endif /* OMITCASE0 */
