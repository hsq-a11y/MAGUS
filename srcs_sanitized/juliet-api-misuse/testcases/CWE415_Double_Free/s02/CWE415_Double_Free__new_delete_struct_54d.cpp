/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_struct_54d.cpp
Label Definition File: CWE415_Double_Free__new_delete.label.xml
Template File: sources-sinks-54d.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * Case0Source:  Allocate data using new and Deallocae data using delete
 * Case1Source: Allocate data using new
 * Sinks:
 *    Case1Sink: do nothing
 *    Case0Sink : Deallocate data using delete
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__new_delete_struct_54
{

#ifndef OMITCASE0

/* case0 function declaration */
void case0Sink_e(twoIntsStruct * data);

void case0Sink_d(twoIntsStruct * data)
{
    case0Sink_e(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink_e(twoIntsStruct * data);

void case1V1Sink_d(twoIntsStruct * data)
{
    case1V1Sink_e(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Sink_e(twoIntsStruct * data);

void case1V2Sink_d(twoIntsStruct * data)
{
    case1V2Sink_e(data);
}

#endif /* OMITCASE1 */

} /* close namespace */
