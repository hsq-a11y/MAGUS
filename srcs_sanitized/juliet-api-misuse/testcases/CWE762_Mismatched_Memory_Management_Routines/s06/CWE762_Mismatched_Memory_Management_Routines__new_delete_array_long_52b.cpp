/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_delete_array_long_52b.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_delete_array.label.xml
Template File: sources-sinks-52b.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source:  Allocate data using new
 * Case1Source: Allocate data using new []
 * Sinks:
 *    Case1Sink: Deallocate data using delete
 *    Case0Sink : Deallocate data using delete []
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_delete_array_long_52
{

#ifndef OMITCASE0

/* case0 function declaration */
void case0Sink_c(long * data);

void case0Sink_b(long * data)
{
    case0Sink_c(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink_c(long * data);

void case1V1Sink_b(long * data)
{
    case1V1Sink_c(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Sink_c(long * data);

void case1V2Sink_b(long * data)
{
    case1V2Sink_c(data);
}

#endif /* OMITCASE1 */

} /* close namespace */
