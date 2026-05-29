/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_struct_realloc_83_case1V2.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete.label.xml
Template File: sources-sinks-83_case1V2.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source: realloc Allocate data using realloc()
 * Case1Source: Allocate data using new
 * Sinks:
 *    Case1Sink: Deallocate data using free()
 *    Case0Sink : Deallocate data using delete
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE762_Mismatched_Memory_Management_Routines__delete_struct_realloc_83.h"

namespace CWE762_Mismatched_Memory_Management_Routines__delete_struct_realloc_83
{
CWE762_Mismatched_Memory_Management_Routines__delete_struct_realloc_83_case1V2::CWE762_Mismatched_Memory_Management_Routines__delete_struct_realloc_83_case1V2(twoIntsStruct * dataCopy)
{
    data = dataCopy;
    data = NULL;
    /* NOTE: Allocate memory with a function that requires free() to free the memory */
    data = (twoIntsStruct *)realloc(data, 100*sizeof(twoIntsStruct));
    if (data == NULL) {exit(-1);}
}

CWE762_Mismatched_Memory_Management_Routines__delete_struct_realloc_83_case1V2::~CWE762_Mismatched_Memory_Management_Routines__delete_struct_realloc_83_case1V2()
{
    /* ALT: Deallocate the memory using free() */
    free(data);
}
}
#endif /* OMITCASE1 */
