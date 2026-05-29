/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_array_long_calloc_72b.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete_array.label.xml
Template File: sources-sinks-72b.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source: calloc Allocate data using calloc()
 * Case1Source: Allocate data using new []
 * Sinks:
 *    Case1Sink: Deallocate data using free()
 *    Case0Sink : Deallocate data using delete []
 * Flow Variant: 72 Data flow: data passed in a vector from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <vector>

using namespace std;

namespace CWE762_Mismatched_Memory_Management_Routines__delete_array_long_calloc_72
{

#ifndef OMITCASE0

void case0Sink(vector<long *> dataVector)
{
    /* copy data out of dataVector */
    long * data = dataVector[2];
    /* NOTE: Deallocate memory using delete [] - the source memory allocation function may
     * require a call to free() to deallocate the memory */
    delete [] data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink(vector<long *> dataVector)
{
    long * data = dataVector[2];
    /* NOTE: Deallocate memory using delete [] - the source memory allocation function may
     * require a call to free() to deallocate the memory */
    delete [] data;
}

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Sink(vector<long *> dataVector)
{
    long * data = dataVector[2];
    /* ALT: Free memory using free() */
    free(data);
}

#endif /* OMITCASE1 */

} /* close namespace */
