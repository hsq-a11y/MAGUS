/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__delete_array_class_static_66b.cpp
Label Definition File: CWE590_Free_Memory_Not_on_Heap__delete_array.label.xml
Template File: sources-sink-66b.tmpl.cpp
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * Case0Source: static Data buffer is declared static on the stack
 * Case1Source: Allocate memory on the heap
 * Sinks:
 *    Case0Sink : Print then free data
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE590_Free_Memory_Not_on_Heap__delete_array_class_static_66
{

#ifndef OMITCASE0

void case0Sink(TwoIntsClass * dataArray[])
{
    /* copy data out of dataArray */
    TwoIntsClass * data = dataArray[2];
    printIntLine(data[0].intOne);
    /* NOTE: Possibly deallocating memory allocated on the stack */
    delete [] data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink(TwoIntsClass * dataArray[])
{
    TwoIntsClass * data = dataArray[2];
    printIntLine(data[0].intOne);
    /* NOTE: Possibly deallocating memory allocated on the stack */
    delete [] data;
}

#endif /* OMITCASE1 */

} /* close namespace */
