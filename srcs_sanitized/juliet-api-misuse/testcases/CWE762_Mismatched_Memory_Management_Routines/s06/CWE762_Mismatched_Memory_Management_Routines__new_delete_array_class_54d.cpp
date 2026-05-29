/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_delete_array_class_54d.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_delete_array.label.xml
Template File: sources-sinks-54d.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source:  Allocate data using new
 * Case1Source: Allocate data using new []
 * Sinks:
 *    Case1Sink: Deallocate data using delete
 *    Case0Sink : Deallocate data using delete []
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_delete_array_class_54
{

#ifndef OMITCASE0

/* case0 function declaration */
void case0Sink_e(TwoIntsClass * data);

void case0Sink_d(TwoIntsClass * data)
{
    case0Sink_e(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink_e(TwoIntsClass * data);

void case1V1Sink_d(TwoIntsClass * data)
{
    case1V1Sink_e(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Sink_e(TwoIntsClass * data);

void case1V2Sink_d(TwoIntsClass * data)
{
    case1V2Sink_e(data);
}

#endif /* OMITCASE1 */

} /* close namespace */
