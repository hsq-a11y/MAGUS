/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__free_struct_alloca_72b.cpp
Label Definition File: CWE590_Free_Memory_Not_on_Heap__free.label.xml
Template File: sources-sink-72b.tmpl.cpp
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * Case0Source: alloca Data buffer is allocated on the stack with alloca()
 * Case1Source: Allocate memory on the heap
 * Sinks:
 *    Case0Sink : Print then free data
 * Flow Variant: 72 Data flow: data passed in a vector from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <vector>

#include <wchar.h>

using namespace std;

namespace CWE590_Free_Memory_Not_on_Heap__free_struct_alloca_72
{

#ifndef OMITCASE0

void case0Sink(vector<twoIntsStruct *> dataVector)
{
    /* copy data out of dataVector */
    twoIntsStruct * data = dataVector[2];
    printStructLine(&data[0]);
    /* NOTE: Possibly deallocating memory allocated on the stack */
    free(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink(vector<twoIntsStruct *> dataVector)
{
    twoIntsStruct * data = dataVector[2];
    printStructLine(&data[0]);
    /* NOTE: Possibly deallocating memory allocated on the stack */
    free(data);
}

#endif /* OMITCASE1 */

} /* close namespace */
