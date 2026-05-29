/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__delete_array_int64_t_alloca_81_case0.cpp
Label Definition File: CWE590_Free_Memory_Not_on_Heap__delete_array.label.xml
Template File: sources-sink-81_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * Case0Source: alloca Data buffer is allocated on the stack with alloca()
 * Case1Source: Allocate memory on the heap
 * Sinks:
 *    Case0Sink : Print then free data
 * Flow Variant: 81 Data flow: data passed in a parameter to a virtual method called via a reference
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE590_Free_Memory_Not_on_Heap__delete_array_int64_t_alloca_81.h"

namespace CWE590_Free_Memory_Not_on_Heap__delete_array_int64_t_alloca_81
{

void CWE590_Free_Memory_Not_on_Heap__delete_array_int64_t_alloca_81_case0::action(int64_t * data) const
{
    printLongLongLine(data[0]);
    /* NOTE: Possibly deallocating memory allocated on the stack */
    delete [] data;
}

}
#endif /* OMITCASE0 */
