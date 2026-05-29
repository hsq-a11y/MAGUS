/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_array_free_class_83_case1V1.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_array_free.label.xml
Template File: sources-sinks-83_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source:  Allocate data using new []
 * Case1Source: Allocate data using malloc()
 * Sinks:
 *    Case1Sink: Deallocate data using delete []
 *    Case0Sink : Deallocate data using free()
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE762_Mismatched_Memory_Management_Routines__new_array_free_class_83.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_array_free_class_83
{
CWE762_Mismatched_Memory_Management_Routines__new_array_free_class_83_case1V1::CWE762_Mismatched_Memory_Management_Routines__new_array_free_class_83_case1V1(TwoIntsClass * dataCopy)
{
    data = dataCopy;
    /* ALT: Allocate memory from the heap using malloc() */
    data = (TwoIntsClass *)malloc(100*sizeof(TwoIntsClass));
    if (data == NULL) {exit(-1);}
}

CWE762_Mismatched_Memory_Management_Routines__new_array_free_class_83_case1V1::~CWE762_Mismatched_Memory_Management_Routines__new_array_free_class_83_case1V1()
{
    /* NOTE: Deallocate memory using free() - the source memory allocation function may
     * require a call to delete [] to deallocate the memory */
    free(data);
}
}
#endif /* OMITCASE1 */
