/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_free_int_62b.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_free.label.xml
Template File: sources-sinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source:  Allocate data using new
 * Case1Source: Allocate data using malloc()
 * Sinks:
 *    Case1Sink: Deallocate data using delete
 *    Case0Sink : Deallocate data using free()
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_free_int_62
{

#ifndef OMITCASE0

void case0Source(int * &data)
{
    /* NOTE: Allocate memory with a function that requires delete to free the memory */
    data = new int;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
void case1V1Source(int * &data)
{
    /* ALT: Allocate memory from the heap using malloc() */
    data = (int *)malloc(100*sizeof(int));
    if (data == NULL) {exit(-1);}
}

/* case1V2() uses the Case0Source with the Case1Sink */
void case1V2Source(int * &data)
{
    /* NOTE: Allocate memory with a function that requires delete to free the memory */
    data = new int;
}

#endif /* OMITCASE1 */

} /* close namespace */
