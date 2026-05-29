/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_wchar_t_calloc_62b.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete.label.xml
Template File: sources-sinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source: calloc Allocate data using calloc()
 * Case1Source: Allocate data using new
 * Sinks:
 *    Case1Sink: Deallocate data using free()
 *    Case0Sink : Deallocate data using delete
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__delete_wchar_t_calloc_62
{

#ifndef OMITCASE0

void case0Source(wchar_t * &data)
{
    /* NOTE: Allocate memory with a function that requires free() to free the memory */
    data = (wchar_t *)calloc(100, sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
void case1V1Source(wchar_t * &data)
{
    /* ALT: Allocate memory from the heap using new */
    data = new wchar_t;
}

/* case1V2() uses the Case0Source with the Case1Sink */
void case1V2Source(wchar_t * &data)
{
    /* NOTE: Allocate memory with a function that requires free() to free the memory */
    data = (wchar_t *)calloc(100, sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
}

#endif /* OMITCASE1 */

} /* close namespace */
