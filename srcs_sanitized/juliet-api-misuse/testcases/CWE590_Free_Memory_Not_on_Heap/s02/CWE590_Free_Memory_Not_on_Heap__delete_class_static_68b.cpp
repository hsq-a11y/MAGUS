/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__delete_class_static_68b.cpp
Label Definition File: CWE590_Free_Memory_Not_on_Heap__delete.nonpointer.label.xml
Template File: sources-sink-68b.tmpl.cpp
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * Case0Source: static Data buffer is declared static on the stack
 * Case1Source: Allocate memory on the heap
 * Sink:
 *    Case0Sink : Print then free data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

extern TwoIntsClass * CWE590_Free_Memory_Not_on_Heap__delete_class_static_68_case0Data;
extern TwoIntsClass * CWE590_Free_Memory_Not_on_Heap__delete_class_static_68_case1V1Data;

namespace CWE590_Free_Memory_Not_on_Heap__delete_class_static_68
{

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

void case0Sink()
{
    TwoIntsClass * data = CWE590_Free_Memory_Not_on_Heap__delete_class_static_68_case0Data;
    printIntLine(data->intOne);
    /* NOTE: Possibly deallocating memory allocated on the stack */
    delete data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink()
{
    TwoIntsClass * data = CWE590_Free_Memory_Not_on_Heap__delete_class_static_68_case1V1Data;
    printIntLine(data->intOne);
    /* NOTE: Possibly deallocating memory allocated on the stack */
    delete data;
}

#endif /* OMITCASE1 */

} /* close namespace */
