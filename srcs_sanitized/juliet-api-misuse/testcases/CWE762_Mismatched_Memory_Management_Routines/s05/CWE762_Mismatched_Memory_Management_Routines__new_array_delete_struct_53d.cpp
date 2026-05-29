/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_array_delete_struct_53d.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_array_delete.label.xml
Template File: sources-sinks-53d.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source:  Allocate data using new []
 * Case1Source: Allocate data using new
 * Sinks:
 *    Case1Sink: Deallocate data using delete []
 *    Case0Sink : Deallocate data using delete
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_array_delete_struct_53
{

#ifndef OMITCASE0

void case0Sink_d(twoIntsStruct * data)
{
    /* NOTE: Deallocate memory using delete - the source memory allocation function may
     * require a call to delete [] to deallocate the memory */
    delete data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink_d(twoIntsStruct * data)
{
    /* NOTE: Deallocate memory using delete - the source memory allocation function may
     * require a call to delete [] to deallocate the memory */
    delete data;
}

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Sink_d(twoIntsStruct * data)
{
    /* ALT: Deallocate the memory using delete [] */
    delete [] data;
}

#endif /* OMITCASE1 */

} /* close namespace */
