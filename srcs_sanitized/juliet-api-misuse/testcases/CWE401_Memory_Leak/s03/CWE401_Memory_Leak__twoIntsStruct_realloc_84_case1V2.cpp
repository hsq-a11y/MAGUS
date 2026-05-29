/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__twoIntsStruct_realloc_84_case1V2.cpp
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-84_case1V2.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source: realloc Allocate data using realloc()
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call free() on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE401_Memory_Leak__twoIntsStruct_realloc_84.h"

namespace CWE401_Memory_Leak__twoIntsStruct_realloc_84
{
CWE401_Memory_Leak__twoIntsStruct_realloc_84_case1V2::CWE401_Memory_Leak__twoIntsStruct_realloc_84_case1V2(twoIntsStruct * dataCopy)
{
    data = dataCopy;
    /* NOTE: Allocate memory on the heap */
    data = (twoIntsStruct *)realloc(data, 100*sizeof(twoIntsStruct));
    if (data == NULL) {exit(-1);}
    /* Initialize and make use of data */
    data[0].intOne = 0;
    data[0].intTwo = 0;
    printStructLine(&data[0]);
}

CWE401_Memory_Leak__twoIntsStruct_realloc_84_case1V2::~CWE401_Memory_Leak__twoIntsStruct_realloc_84_case1V2()
{
    /* ALT: Deallocate memory */
    free(data);
}
}
#endif /* OMITCASE1 */
