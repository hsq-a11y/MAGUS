/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__free_long_static_82_case1V1.cpp
Label Definition File: CWE590_Free_Memory_Not_on_Heap__free.label.xml
Template File: sources-sink-82_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * Case0Source: static Data buffer is declared static on the stack
 * Case1Source: Allocate memory on the heap
 * Sinks:
 *    Case0Sink : Print then free data
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE590_Free_Memory_Not_on_Heap__free_long_static_82.h"

namespace CWE590_Free_Memory_Not_on_Heap__free_long_static_82
{

void CWE590_Free_Memory_Not_on_Heap__free_long_static_82_case1V1::action(long * data)
{
    printLongLine(data[0]);
    /* NOTE: Possibly deallocating memory allocated on the stack */
    free(data);
}

}
#endif /* OMITCASE1 */
