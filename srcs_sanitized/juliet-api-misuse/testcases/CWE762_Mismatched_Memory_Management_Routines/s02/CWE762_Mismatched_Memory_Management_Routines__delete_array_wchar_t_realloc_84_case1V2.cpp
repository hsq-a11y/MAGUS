/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_array_wchar_t_realloc_84_case1V2.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete_array.label.xml
Template File: sources-sinks-84_case1V2.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source: realloc Allocate data using realloc()
 * Case1Source: Allocate data using new []
 * Sinks:
 *    Case1Sink: Deallocate data using free()
 *    Case0Sink : Deallocate data using delete []
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE762_Mismatched_Memory_Management_Routines__delete_array_wchar_t_realloc_84.h"

namespace CWE762_Mismatched_Memory_Management_Routines__delete_array_wchar_t_realloc_84
{
CWE762_Mismatched_Memory_Management_Routines__delete_array_wchar_t_realloc_84_case1V2::CWE762_Mismatched_Memory_Management_Routines__delete_array_wchar_t_realloc_84_case1V2(wchar_t * dataCopy)
{
    data = dataCopy;
    data = NULL;
    /* NOTE: Allocate memory with a function that requires free() to free the memory */
    data = (wchar_t *)realloc(data, 100*sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
}

CWE762_Mismatched_Memory_Management_Routines__delete_array_wchar_t_realloc_84_case1V2::~CWE762_Mismatched_Memory_Management_Routines__delete_array_wchar_t_realloc_84_case1V2()
{
    /* ALT: Free memory using free() */
    free(data);
}
}
#endif /* OMITCASE1 */
