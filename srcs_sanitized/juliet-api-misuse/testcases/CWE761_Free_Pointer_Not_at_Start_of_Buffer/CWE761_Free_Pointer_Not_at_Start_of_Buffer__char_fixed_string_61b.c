/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_61b.c
Label Definition File: CWE761_Free_Pointer_Not_at_Start_of_Buffer.label.xml
Template File: source-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 761 Free Pointer not at Start of Buffer
 * Case0Source: fixed_string Initialize data to be a fixed string
 * Sinks:
 *    Case1Sink: free() memory correctly at the start of the buffer
 *    Case0Sink : free() memory not at the start of the buffer
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define CASE0_SOURCE_FIXED_STRING "Fixed String" /* MAINTENANCE NOTE: This string must contain the SEARCH_CHAR */

#define SEARCH_CHAR 'S'

#ifndef OMITCASE0

char * CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_61b_case0Source(char * data)
{
    /* NOTE: Initialize data to be a fixed string that contains the search character in the sinks */
    strcpy(data, CASE0_SOURCE_FIXED_STRING);
    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2() uses the Case0Source with the Case1Sink */
char * CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_61b_case1V2Source(char * data)
{
    /* NOTE: Initialize data to be a fixed string that contains the search character in the sinks */
    strcpy(data, CASE0_SOURCE_FIXED_STRING);
    return data;
}

#endif /* OMITCASE1 */
