/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_array_struct_calloc_61b.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete_array.label.xml
Template File: sources-sinks-61b.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source: calloc Allocate data using calloc()
 * Case1Source: Allocate data using new []
 * Sinks:
 *    Case1Sink: Deallocate data using free()
 *    Case0Sink : Deallocate data using delete []
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__delete_array_struct_calloc_61
{

#ifndef OMITCASE0

twoIntsStruct * case0Source(twoIntsStruct * data)
{
    /* NOTE: Allocate memory with a function that requires free() to free the memory */
    data = (twoIntsStruct *)calloc(100, sizeof(twoIntsStruct));
    if (data == NULL) {exit(-1);}
    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
twoIntsStruct * case1V1Source(twoIntsStruct * data)
{
    /* ALT: Allocate memory using new [] */
    data = new twoIntsStruct[100];
    return data;
}

/* case1V2() uses the Case0Source with the Case1Sink */
twoIntsStruct * case1V2Source(twoIntsStruct * data)
{
    /* NOTE: Allocate memory with a function that requires free() to free the memory */
    data = (twoIntsStruct *)calloc(100, sizeof(twoIntsStruct));
    if (data == NULL) {exit(-1);}
    return data;
}

#endif /* OMITCASE1 */

} /* close namespace */
