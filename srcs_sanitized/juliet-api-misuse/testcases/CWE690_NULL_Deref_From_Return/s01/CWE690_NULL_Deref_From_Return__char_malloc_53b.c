/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__char_malloc_53b.c
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-53b.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: malloc Allocate data using malloc()
 * Sinks:
 *    Case1Sink: Check to see if the data allocation failed and if not, use data
 *    Case0Sink : Don't check for NULL and use data
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

/* case0 function declaration */
void CWE690_NULL_Deref_From_Return__char_malloc_53c_case0Sink(char * data);

void CWE690_NULL_Deref_From_Return__char_malloc_53b_case0Sink(char * data)
{
    CWE690_NULL_Deref_From_Return__char_malloc_53c_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE690_NULL_Deref_From_Return__char_malloc_53c_case1V2Sink(char * data);

void CWE690_NULL_Deref_From_Return__char_malloc_53b_case1V2Sink(char * data)
{
    CWE690_NULL_Deref_From_Return__char_malloc_53c_case1V2Sink(data);
}

#endif /* OMITCASE1 */
