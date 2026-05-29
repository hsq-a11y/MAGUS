/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__delete_int64_t_placement_new_82_case1V1.cpp
Label Definition File: CWE590_Free_Memory_Not_on_Heap__delete.pointer.label.xml
Template File: sources-sink-82_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * Case0Source: placement_new Data buffer is declared on the stack
 * Case1Source: Allocate memory on the heap
 * Sinks:
 *    Case0Sink : Print then free data
 * Flow Variant: 82 Data flow: data passed in a parameter to a virtual method called via a pointer
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE590_Free_Memory_Not_on_Heap__delete_int64_t_placement_new_82.h"

namespace CWE590_Free_Memory_Not_on_Heap__delete_int64_t_placement_new_82
{

void CWE590_Free_Memory_Not_on_Heap__delete_int64_t_placement_new_82_case1V1::action(int64_t * data)
{
    printLongLongLine(*data);
    /* NOTE: Possibly deallocating memory allocated on the stack */
    delete data;
}

}
#endif /* OMITCASE1 */
