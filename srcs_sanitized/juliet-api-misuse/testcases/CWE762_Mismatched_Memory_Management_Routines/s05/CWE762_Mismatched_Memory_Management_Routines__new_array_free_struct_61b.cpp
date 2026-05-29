/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_array_free_struct_61b.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_array_free.label.xml
Template File: sources-sinks-61b.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source:  Allocate data using new []
 * Case1Source: Allocate data using malloc()
 * Sinks:
 *    Case1Sink: Deallocate data using delete []
 *    Case0Sink : Deallocate data using free()
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_array_free_struct_61
{

#ifndef OMITCASE0

twoIntsStruct * case0Source(twoIntsStruct * data)
{
    /* NOTE: Allocate memory with a function that requires delete [] to free the memory */
    data = new twoIntsStruct[100];
    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
twoIntsStruct * case1V1Source(twoIntsStruct * data)
{
    /* ALT: Allocate memory from the heap using malloc() */
    data = (twoIntsStruct *)malloc(100*sizeof(twoIntsStruct));
    if (data == NULL) {exit(-1);}
    return data;
}

/* case1V2() uses the Case0Source with the Case1Sink */
twoIntsStruct * case1V2Source(twoIntsStruct * data)
{
    /* NOTE: Allocate memory with a function that requires delete [] to free the memory */
    data = new twoIntsStruct[100];
    return data;
}

#endif /* OMITCASE1 */

} /* close namespace */
