/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_delete_array_char_84_case0.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_delete_array.label.xml
Template File: sources-sinks-84_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source:  Allocate data using new
 * Case1Source: Allocate data using new []
 * Sinks:
 *    Case1Sink: Deallocate data using delete
 *    Case0Sink : Deallocate data using delete []
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE762_Mismatched_Memory_Management_Routines__new_delete_array_char_84.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_delete_array_char_84
{
CWE762_Mismatched_Memory_Management_Routines__new_delete_array_char_84_case0::CWE762_Mismatched_Memory_Management_Routines__new_delete_array_char_84_case0(char * dataCopy)
{
    data = dataCopy;
    /* NOTE: Allocate memory with a function that requires delete to free the memory */
    data = new char;
}

CWE762_Mismatched_Memory_Management_Routines__new_delete_array_char_84_case0::~CWE762_Mismatched_Memory_Management_Routines__new_delete_array_char_84_case0()
{
    /* NOTE: Deallocate memory using delete [] - the source memory allocation function may
     * require a call to delete to deallocate the memory */
    delete [] data;
}
}
#endif /* OMITCASE0 */
