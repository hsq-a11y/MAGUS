/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_TwoIntsClass_54d.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-54d.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source:  Allocate data using new
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call delete on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE401_Memory_Leak__new_TwoIntsClass_54
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
