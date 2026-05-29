/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__free_struct_alloca_81_case1V1.cpp
Label Definition File: CWE590_Free_Memory_Not_on_Heap__free.label.xml
Template File: sources-sink-81_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * Case0Source: alloca Data buffer is allocated on the stack with alloca()
 * Case1Source: Allocate memory on the heap
 * Sinks:
 *    Case0Sink : Print then free data
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE590_Free_Memory_Not_on_Heap__free_struct_alloca_81.h"

namespace CWE590_Free_Memory_Not_on_Heap__free_struct_alloca_81
{

void CWE590_Free_Memory_Not_on_Heap__free_struct_alloca_81_case1V1::action(twoIntsStruct * data) const
{
    printStructLine(&data[0]);
    /* NOTE: Possibly deallocating memory allocated on the stack */
    free(data);
}

}
#endif /* OMITCASE1 */
