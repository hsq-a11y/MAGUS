/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__struct_twoIntsStruct_realloc_72b.cpp
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-72b.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source: realloc Allocate data using realloc()
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call free() on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 72 Data flow: data passed in a vector from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <vector>

#include <wchar.h>

using namespace std;

namespace CWE401_Memory_Leak__struct_twoIntsStruct_realloc_72
{

#ifndef OMITCASE0

void case0Sink(vector<struct _twoIntsStruct *> dataVector)
{
    /* copy data out of dataVector */
    struct _twoIntsStruct * data = dataVector[2];
    /* NOTE: No deallocation */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink(vector<struct _twoIntsStruct *> dataVector)
{
    struct _twoIntsStruct * data = dataVector[2];
    /* NOTE: No deallocation */
    ; /* empty statement needed for some flow variants */
}

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Sink(vector<struct _twoIntsStruct *> dataVector)
{
    struct _twoIntsStruct * data = dataVector[2];
    /* ALT: Deallocate memory */
    free(data);
}

#endif /* OMITCASE1 */

} /* close namespace */
