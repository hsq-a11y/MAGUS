/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_wchar_t_realloc_53c.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete.label.xml
Template File: sources-sinks-53c.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source: realloc Allocate data using realloc()
 * Case1Source: Allocate data using new
 * Sinks:
 *    Case1Sink: Deallocate data using free()
 *    Case0Sink : Deallocate data using delete
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__delete_wchar_t_realloc_53
{

#ifndef OMITCASE0

/* case0 function declaration */
void case0Sink_d(wchar_t * data);

void case0Sink_c(wchar_t * data)
{
    case0Sink_d(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink_d(wchar_t * data);

void case1V1Sink_c(wchar_t * data)
{
    case1V1Sink_d(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Sink_d(wchar_t * data);

void case1V2Sink_c(wchar_t * data)
{
    case1V2Sink_d(data);
}

#endif /* OMITCASE1 */

} /* close namespace */
