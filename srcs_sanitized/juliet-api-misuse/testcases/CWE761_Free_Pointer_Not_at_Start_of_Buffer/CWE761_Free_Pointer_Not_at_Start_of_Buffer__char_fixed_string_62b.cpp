/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_62b.cpp
Label Definition File: CWE761_Free_Pointer_Not_at_Start_of_Buffer.label.xml
Template File: source-sinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 761 Free Pointer not at Start of Buffer
 * Case0Source: fixed_string Initialize data to be a fixed string
 * Sinks:
 *    Case1Sink: free() memory correctly at the start of the buffer
 *    Case0Sink : free() memory not at the start of the buffer
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define CASE0_SOURCE_FIXED_STRING "Fixed String" /* MAINTENANCE NOTE: This string must contain the SEARCH_CHAR */

namespace CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_62
{

#ifndef OMITCASE0

void case0Source(char * &data)
{
    /* NOTE: Initialize data to be a fixed string that contains the search character in the sinks */
    strcpy(data, CASE0_SOURCE_FIXED_STRING);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2() uses the Case0Source with the Case1Sink */
void case1V2Source(char * &data)
{
    /* NOTE: Initialize data to be a fixed string that contains the search character in the sinks */
    strcpy(data, CASE0_SOURCE_FIXED_STRING);
}

#endif /* OMITCASE1 */

} /* close namespace */
