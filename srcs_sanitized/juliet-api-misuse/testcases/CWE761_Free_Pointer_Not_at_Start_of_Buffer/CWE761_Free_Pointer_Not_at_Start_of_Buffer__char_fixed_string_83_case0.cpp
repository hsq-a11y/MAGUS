/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_83_case0.cpp
Label Definition File: CWE761_Free_Pointer_Not_at_Start_of_Buffer.label.xml
Template File: source-sinks-83_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 761 Free Pointer not at Start of Buffer
 * Case0Source: fixed_string Initialize data to be a fixed string
 * Sinks:
 *    Case1Sink: free() memory correctly at the start of the buffer
 *    Case0Sink : free() memory not at the start of the buffer
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_83.h"

#define CASE0_SOURCE_FIXED_STRING "Fixed String" /* MAINTENANCE NOTE: This string must contain the SEARCH_CHAR */

#define SEARCH_CHAR 'S'

namespace CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_83
{
CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_83_case0::CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_83_case0(char * dataCopy)
{
    data = dataCopy;
    /* NOTE: Initialize data to be a fixed string that contains the search character in the sinks */
    strcpy(data, CASE0_SOURCE_FIXED_STRING);
}

CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_83_case0::~CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_83_case0()
{
    /* NOTE: We are incrementing the pointer in the loop - this will cause us to free the
     * memory block not at the start of the buffer */
    for (; *data != '\0'; data++)
    {
        if (*data == SEARCH_CHAR)
        {
            printLine("We have a match!");
            break;
        }
    }
    free(data);
}
}
#endif /* OMITCASE0 */
