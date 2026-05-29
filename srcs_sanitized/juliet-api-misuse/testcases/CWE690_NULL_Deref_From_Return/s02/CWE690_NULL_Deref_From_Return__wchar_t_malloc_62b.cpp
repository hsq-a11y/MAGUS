/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__wchar_t_malloc_62b.cpp
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: malloc Allocate data using malloc()
 * Sinks:
 *    Case1Sink: Check to see if the data allocation failed and if not, use data
 *    Case0Sink : Don't check for NULL and use data
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE690_NULL_Deref_From_Return__wchar_t_malloc_62
{

#ifndef OMITCASE0

void case0Source(wchar_t * &data)
{
    /* NOTE: Allocate memory without checking if the memory allocation function failed */
    data = (wchar_t *)malloc(20*sizeof(wchar_t));
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2() uses the Case0Source with the Case1Sink */
void case1V2Source(wchar_t * &data)
{
    /* NOTE: Allocate memory without checking if the memory allocation function failed */
    data = (wchar_t *)malloc(20*sizeof(wchar_t));
}

#endif /* OMITCASE1 */

} /* close namespace */
