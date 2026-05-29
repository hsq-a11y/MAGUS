/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_array_free_int_66b.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_array_free.label.xml
Template File: sources-sinks-66b.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source:  Allocate data using new []
 * Case1Source: Allocate data using malloc()
 * Sinks:
 *    Case1Sink: Deallocate data using delete []
 *    Case0Sink : Deallocate data using free()
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_array_free_int_66
{

#ifndef OMITCASE0

void case0Sink(int * dataArray[])
{
    /* copy data out of dataArray */
    int * data = dataArray[2];
    /* NOTE: Deallocate memory using free() - the source memory allocation function may
     * require a call to delete [] to deallocate the memory */
    free(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink(int * dataArray[])
{
    int * data = dataArray[2];
    /* NOTE: Deallocate memory using free() - the source memory allocation function may
     * require a call to delete [] to deallocate the memory */
    free(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Sink(int * dataArray[])
{
    int * data = dataArray[2];
    /* ALT: Deallocate the memory using delete [] */
    delete [] data;
}

#endif /* OMITCASE1 */

} /* close namespace */
