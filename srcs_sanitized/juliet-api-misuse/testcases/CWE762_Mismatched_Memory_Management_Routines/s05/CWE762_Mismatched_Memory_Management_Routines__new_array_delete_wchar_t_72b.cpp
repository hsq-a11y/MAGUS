/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_array_delete_wchar_t_72b.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_array_delete.label.xml
Template File: sources-sinks-72b.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source:  Allocate data using new []
 * Case1Source: Allocate data using new
 * Sinks:
 *    Case1Sink: Deallocate data using delete []
 *    Case0Sink : Deallocate data using delete
 * Flow Variant: 72 Data flow: data passed in a vector from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <vector>

using namespace std;

namespace CWE762_Mismatched_Memory_Management_Routines__new_array_delete_wchar_t_72
{

#ifndef OMITCASE0

void case0Sink(vector<wchar_t *> dataVector)
{
    /* copy data out of dataVector */
    wchar_t * data = dataVector[2];
    /* NOTE: Deallocate memory using delete - the source memory allocation function may
     * require a call to delete [] to deallocate the memory */
    delete data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink(vector<wchar_t *> dataVector)
{
    wchar_t * data = dataVector[2];
    /* NOTE: Deallocate memory using delete - the source memory allocation function may
     * require a call to delete [] to deallocate the memory */
    delete data;
}

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Sink(vector<wchar_t *> dataVector)
{
    wchar_t * data = dataVector[2];
    /* ALT: Deallocate the memory using delete [] */
    delete [] data;
}

#endif /* OMITCASE1 */

} /* close namespace */
