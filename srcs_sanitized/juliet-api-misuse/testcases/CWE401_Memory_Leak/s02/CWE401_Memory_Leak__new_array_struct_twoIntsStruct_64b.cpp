/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_array_struct_twoIntsStruct_64b.cpp
Label Definition File: CWE401_Memory_Leak__new_array.label.xml
Template File: sources-sinks-64b.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source:  Allocate data using new[]
 * Case1Source: Point data to a stack buffer
 * Sinks:
 *    Case1Sink: call delete[] on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE401_Memory_Leak__new_array_struct_twoIntsStruct_64
{

#ifndef OMITCASE0

void case0Sink(void * dataVoidPtr)
{
    /* cast void pointer to a pointer of the appropriate type */
    struct _twoIntsStruct * * dataPtr = (struct _twoIntsStruct * *)dataVoidPtr;
    /* dereference dataPtr into data */
    struct _twoIntsStruct * data = (*dataPtr);
    /* NOTE: No deallocation */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink(void * dataVoidPtr)
{
    /* cast void pointer to a pointer of the appropriate type */
    struct _twoIntsStruct * * dataPtr = (struct _twoIntsStruct * *)dataVoidPtr;
    /* dereference dataPtr into data */
    struct _twoIntsStruct * data = (*dataPtr);
    /* NOTE: No deallocation */
    ; /* empty statement needed for some flow variants */
}

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Sink(void * dataVoidPtr)
{
    /* cast void pointer to a pointer of the appropriate type */
    struct _twoIntsStruct * * dataPtr = (struct _twoIntsStruct * *)dataVoidPtr;
    /* dereference dataPtr into data */
    struct _twoIntsStruct * data = (*dataPtr);
    /* ALT: Deallocate memory */
    delete[] data;
}

#endif /* OMITCASE1 */

} /* close namespace */
