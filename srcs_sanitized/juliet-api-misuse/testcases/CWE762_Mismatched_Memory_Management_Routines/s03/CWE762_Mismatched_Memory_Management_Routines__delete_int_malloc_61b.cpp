/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_int_malloc_61b.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete.label.xml
Template File: sources-sinks-61b.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source: malloc Allocate data using malloc()
 * Case1Source: Allocate data using new
 * Sinks:
 *    Case1Sink: Deallocate data using free()
 *    Case0Sink : Deallocate data using delete
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__delete_int_malloc_61
{

#ifndef OMITCASE0

int * case0Source(int * data)
{
    /* NOTE: Allocate memory with a function that requires free() to free the memory */
    data = (int *)malloc(100*sizeof(int));
    if (data == NULL) {exit(-1);}
    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
int * case1V1Source(int * data)
{
    /* ALT: Allocate memory from the heap using new */
    data = new int;
    return data;
}

/* case1V2() uses the Case0Source with the Case1Sink */
int * case1V2Source(int * data)
{
    /* NOTE: Allocate memory with a function that requires free() to free the memory */
    data = (int *)malloc(100*sizeof(int));
    if (data == NULL) {exit(-1);}
    return data;
}

#endif /* OMITCASE1 */

} /* close namespace */
