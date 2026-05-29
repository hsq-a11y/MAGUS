/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__int_malloc_72b.cpp
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-72b.tmpl.cpp
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: malloc Allocate data using malloc()
 * Sinks:
 *    Case1Sink: Check to see if the data allocation failed and if not, use data
 *    Case0Sink : Don't check for NULL and use data
 * Flow Variant: 72 Data flow: data passed in a vector from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <vector>

#include <wchar.h>

using namespace std;

namespace CWE690_NULL_Deref_From_Return__int_malloc_72
{

#ifndef OMITCASE0

void case0Sink(vector<int *> dataVector)
{
    /* copy data out of dataVector */
    int * data = dataVector[2];
    /* NOTE: Initialize memory buffer without checking to see if the memory allocation function failed */
    data[0] = 5;
    printIntLine(data[0]);
    free(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Sink(vector<int *> dataVector)
{
    int * data = dataVector[2];
    /* ALT: Check to see if the memory allocation function was successful before initializing the memory buffer */
    if (data != NULL)
    {
        data[0] = 5;
        printIntLine(data[0]);
        free(data);
    }
}

#endif /* OMITCASE1 */

} /* close namespace */
