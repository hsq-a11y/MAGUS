/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_array_long_72b.cpp
Label Definition File: CWE415_Double_Free__new_delete_array.label.xml
Template File: sources-sinks-72b.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * Case0Source:  Allocate data using new and Deallocae data using delete
 * Case1Source: Allocate data using new
 * Sinks:
 *    Case1Sink: do nothing
 *    Case0Sink : Deallocate data using delete
 * Flow Variant: 72 Data flow: data passed in a vector from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <vector>

#include <wchar.h>

using namespace std;

namespace CWE415_Double_Free__new_delete_array_long_72
{

#ifndef OMITCASE0

void case0Sink(vector<long *> dataVector)
{
    /* copy data out of dataVector */
    long * data = dataVector[2];
    /* NOTE: Possibly deleting memory twice */
    delete [] data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink(vector<long *> dataVector)
{
    long * data = dataVector[2];
    /* NOTE: Possibly deleting memory twice */
    delete [] data;
}

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Sink(vector<long *> dataVector)
{
    long * data = dataVector[2];
    /* do nothing */
    /* ALT: Don't attempt to delete the memory */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITCASE1 */

} /* close namespace */
