/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_array_wchar_t_malloc_54d.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete_array.label.xml
Template File: sources-sinks-54d.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source: malloc Allocate data using malloc()
 * Case1Source: Allocate data using new []
 * Sinks:
 *    Case1Sink: Deallocate data using free()
 *    Case0Sink : Deallocate data using delete []
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__delete_array_wchar_t_malloc_54
{

#ifndef OMITCASE0

/* case0 function declaration */
void case0Sink_e(wchar_t * data);

void case0Sink_d(wchar_t * data)
{
    case0Sink_e(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink_e(wchar_t * data);

void case1V1Sink_d(wchar_t * data)
{
    case1V1Sink_e(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Sink_e(wchar_t * data);

void case1V2Sink_d(wchar_t * data)
{
    case1V2Sink_e(data);
}

#endif /* OMITCASE1 */

} /* close namespace */
