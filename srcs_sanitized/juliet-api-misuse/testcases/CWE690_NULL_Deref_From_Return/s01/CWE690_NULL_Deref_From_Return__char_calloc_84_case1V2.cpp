/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__char_calloc_84_case1V2.cpp
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-84_case1V2.tmpl.cpp
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: calloc Allocate data using calloc()
 * Sinks:
 *    Case1Sink: Check to see if the data allocation failed and if not, use data
 *    Case0Sink : Don't check for NULL and use data
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE690_NULL_Deref_From_Return__char_calloc_84.h"

namespace CWE690_NULL_Deref_From_Return__char_calloc_84
{
CWE690_NULL_Deref_From_Return__char_calloc_84_case1V2::CWE690_NULL_Deref_From_Return__char_calloc_84_case1V2(char * dataCopy)
{
    data = dataCopy;
    /* NOTE: Allocate memory without checking if the memory allocation function failed */
    data = (char *)calloc(20, sizeof(char));
}

CWE690_NULL_Deref_From_Return__char_calloc_84_case1V2::~CWE690_NULL_Deref_From_Return__char_calloc_84_case1V2()
{
    /* ALT: Check to see if the memory allocation function was successful before initializing the memory buffer */
    if (data != NULL)
    {
        strcpy(data, "Initialize");
        printLine(data);
        free(data);
    }
}
}
#endif /* OMITCASE1 */
