/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__delete_array_struct_static_73b.cpp
Label Definition File: CWE590_Free_Memory_Not_on_Heap__delete_array.label.xml
Template File: sources-sink-73b.tmpl.cpp
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * Case0Source: static Data buffer is declared static on the stack
 * Case1Source: Allocate memory on the heap
 * Sinks:
 *    Case0Sink : Print then free data
 * Flow Variant: 73 Data flow: data passed in a list from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <list>

#include <wchar.h>

using namespace std;

namespace CWE590_Free_Memory_Not_on_Heap__delete_array_struct_static_73
{

#ifndef OMITCASE0

void case0Sink(list<twoIntsStruct *> dataList)
{
    /* copy data out of dataList */
    twoIntsStruct * data = dataList.back();
    printStructLine(&data[0]);
    /* NOTE: Possibly deallocating memory allocated on the stack */
    delete [] data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink(list<twoIntsStruct *> dataList)
{
    twoIntsStruct * data = dataList.back();
    printStructLine(&data[0]);
    /* NOTE: Possibly deallocating memory allocated on the stack */
    delete [] data;
}

#endif /* OMITCASE1 */

} /* close namespace */
