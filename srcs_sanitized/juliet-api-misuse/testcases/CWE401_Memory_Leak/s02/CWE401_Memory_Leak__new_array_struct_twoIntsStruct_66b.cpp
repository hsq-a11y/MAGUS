/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_array_struct_twoIntsStruct_66b.cpp
Label Definition File: CWE401_Memory_Leak__new_array.label.xml
Template File: sources-sinks-66b.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source:  Allocate data using new[]
 * Case1Source: Point data to a stack buffer
 * Sinks:
 *    Case1Sink: call delete[] on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE401_Memory_Leak__new_array_struct_twoIntsStruct_66
{

#ifndef OMITCASE0

void case0Sink(struct _twoIntsStruct * dataArray[])
{
    /* copy data out of dataArray */
    struct _twoIntsStruct * data = dataArray[2];
    /* NOTE: No deallocation */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink(struct _twoIntsStruct * dataArray[])
{
    struct _twoIntsStruct * data = dataArray[2];
    /* NOTE: No deallocation */
    ; /* empty statement needed for some flow variants */
}

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Sink(struct _twoIntsStruct * dataArray[])
{
    struct _twoIntsStruct * data = dataArray[2];
    /* ALT: Deallocate memory */
    delete[] data;
}

#endif /* OMITCASE1 */

} /* close namespace */
