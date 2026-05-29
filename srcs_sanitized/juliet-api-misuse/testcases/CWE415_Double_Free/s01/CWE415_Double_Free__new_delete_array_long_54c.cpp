/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_array_long_54c.cpp
Label Definition File: CWE415_Double_Free__new_delete_array.label.xml
Template File: sources-sinks-54c.tmpl.cpp
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

namespace CWE415_Double_Free__new_delete_array_long_54
{

#ifndef OMITCASE0

/* case0 function declaration */
void case0Sink_d(long * data);

void case0Sink_c(long * data)
{
    case0Sink_d(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink_d(long * data);

void case1V1Sink_c(long * data)
{
    case1V1Sink_d(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Sink_d(long * data);

void case1V2Sink_c(long * data)
{
    case1V2Sink_d(data);
}

#endif /* OMITCASE1 */

} /* close namespace */
