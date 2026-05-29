/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__delete_long_static_63b.cpp
Label Definition File: CWE590_Free_Memory_Not_on_Heap__delete.nonpointer.label.xml
Template File: sources-sink-63b.tmpl.cpp
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * Case0Source: static Data buffer is declared static on the stack
 * Case1Source: Allocate memory on the heap
 * Sinks:
 *    Case0Sink : Print then free data
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE590_Free_Memory_Not_on_Heap__delete_long_static_63
{

#ifndef OMITCASE0

void case0Sink(long * * dataPtr)
{
    long * data = *dataPtr;
    printLongLine(*data);
    /* NOTE: Possibly deallocating memory allocated on the stack */
    delete data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink(long * * dataPtr)
{
    long * data = *dataPtr;
    printLongLine(*data);
    /* NOTE: Possibly deallocating memory allocated on the stack */
    delete data;
}

#endif /* OMITCASE1 */

} /* close namespace */
