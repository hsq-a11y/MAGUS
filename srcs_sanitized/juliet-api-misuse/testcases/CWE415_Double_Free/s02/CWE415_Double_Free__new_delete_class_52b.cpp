/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_class_52b.cpp
Label Definition File: CWE415_Double_Free__new_delete.label.xml
Template File: sources-sinks-52b.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * Case0Source:  Allocate data using new and Deallocae data using delete
 * Case1Source: Allocate data using new
 * Sinks:
 *    Case1Sink: do nothing
 *    Case0Sink : Deallocate data using delete
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__new_delete_class_52
{

#ifndef OMITCASE0

/* case0 function declaration */
void case0Sink_c(TwoIntsClass * data);

void case0Sink_b(TwoIntsClass * data)
{
    case0Sink_c(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink_c(TwoIntsClass * data);

void case1V1Sink_b(TwoIntsClass * data)
{
    case1V1Sink_c(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Sink_c(TwoIntsClass * data);

void case1V2Sink_b(TwoIntsClass * data)
{
    case1V2Sink_c(data);
}

#endif /* OMITCASE1 */

} /* close namespace */
