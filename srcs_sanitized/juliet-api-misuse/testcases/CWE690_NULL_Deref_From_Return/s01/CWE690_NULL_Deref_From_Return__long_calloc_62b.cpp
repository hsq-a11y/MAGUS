/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__long_calloc_62b.cpp
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: calloc Allocate data using calloc()
 * Sinks:
 *    Case1Sink: Check to see if the data allocation failed and if not, use data
 *    Case0Sink : Don't check for NULL and use data
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE690_NULL_Deref_From_Return__long_calloc_62
{

#ifndef OMITCASE0

void case0Source(long * &data)
{
    /* NOTE: Allocate memory without checking if the memory allocation function failed */
    data = (long *)calloc(1, sizeof(long));
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2() uses the Case0Source with the Case1Sink */
void case1V2Source(long * &data)
{
    /* NOTE: Allocate memory without checking if the memory allocation function failed */
    data = (long *)calloc(1, sizeof(long));
}

#endif /* OMITCASE1 */

} /* close namespace */
