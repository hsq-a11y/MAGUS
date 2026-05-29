/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_array_delete_char_61b.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_array_delete.label.xml
Template File: sources-sinks-61b.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source:  Allocate data using new []
 * Case1Source: Allocate data using new
 * Sinks:
 *    Case1Sink: Deallocate data using delete []
 *    Case0Sink : Deallocate data using delete
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_array_delete_char_61
{

#ifndef OMITCASE0

char * case0Source(char * data)
{
    /* NOTE: Allocate memory with a function that requires delete [] to free the memory */
    data = new char[100];
    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
char * case1V1Source(char * data)
{
    /* ALT: Allocate memory from the heap using new */
    data = new char;
    return data;
}

/* case1V2() uses the Case0Source with the Case1Sink */
char * case1V2Source(char * data)
{
    /* NOTE: Allocate memory with a function that requires delete [] to free the memory */
    data = new char[100];
    return data;
}

#endif /* OMITCASE1 */

} /* close namespace */
