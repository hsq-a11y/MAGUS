/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_array_free_char_84_case1V2.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_array_free.label.xml
Template File: sources-sinks-84_case1V2.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source:  Allocate data using new []
 * Case1Source: Allocate data using malloc()
 * Sinks:
 *    Case1Sink: Deallocate data using delete []
 *    Case0Sink : Deallocate data using free()
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE762_Mismatched_Memory_Management_Routines__new_array_free_char_84.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_array_free_char_84
{
CWE762_Mismatched_Memory_Management_Routines__new_array_free_char_84_case1V2::CWE762_Mismatched_Memory_Management_Routines__new_array_free_char_84_case1V2(char * dataCopy)
{
    data = dataCopy;
    /* NOTE: Allocate memory with a function that requires delete [] to free the memory */
    data = new char[100];
}

CWE762_Mismatched_Memory_Management_Routines__new_array_free_char_84_case1V2::~CWE762_Mismatched_Memory_Management_Routines__new_array_free_char_84_case1V2()
{
    /* ALT: Deallocate the memory using delete [] */
    delete [] data;
}
}
#endif /* OMITCASE1 */
