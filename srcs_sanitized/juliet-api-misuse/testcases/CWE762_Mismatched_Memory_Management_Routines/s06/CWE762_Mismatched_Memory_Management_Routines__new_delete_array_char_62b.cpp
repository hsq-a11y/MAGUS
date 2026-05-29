/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_delete_array_char_62b.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_delete_array.label.xml
Template File: sources-sinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source:  Allocate data using new
 * Case1Source: Allocate data using new []
 * Sinks:
 *    Case1Sink: Deallocate data using delete
 *    Case0Sink : Deallocate data using delete []
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_delete_array_char_62
{

#ifndef OMITCASE0

void case0Source(char * &data)
{
    /* NOTE: Allocate memory with a function that requires delete to free the memory */
    data = new char;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
void case1V1Source(char * &data)
{
    /* ALT: Allocate memory from the heap using new [] */
    data = new char[100];
}

/* case1V2() uses the Case0Source with the Case1Sink */
void case1V2Source(char * &data)
{
    /* NOTE: Allocate memory with a function that requires delete to free the memory */
    data = new char;
}

#endif /* OMITCASE1 */

} /* close namespace */
