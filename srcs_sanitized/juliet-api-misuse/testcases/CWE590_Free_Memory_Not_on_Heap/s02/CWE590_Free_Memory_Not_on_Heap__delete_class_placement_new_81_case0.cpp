/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__delete_class_placement_new_81_case0.cpp
Label Definition File: CWE590_Free_Memory_Not_on_Heap__delete.pointer.label.xml
Template File: sources-sink-81_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * Case0Source: placement_new Data buffer is declared on the stack
 * Case1Source: Allocate memory on the heap
 * Sinks:
 *    Case0Sink : Print then free data
 * Flow Variant: 81 Data flow: data passed in a parameter to a virtual method called via a reference
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE590_Free_Memory_Not_on_Heap__delete_class_placement_new_81.h"

namespace CWE590_Free_Memory_Not_on_Heap__delete_class_placement_new_81
{

void CWE590_Free_Memory_Not_on_Heap__delete_class_placement_new_81_case0::action(TwoIntsClass * data) const
{
    printIntLine(data->intOne);
    /* NOTE: Possibly deallocating memory allocated on the stack */
    delete data;
}

}
#endif /* OMITCASE0 */
