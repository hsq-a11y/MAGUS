/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_fixed_string_83_case1V2.cpp
Label Definition File: CWE761_Free_Pointer_Not_at_Start_of_Buffer.label.xml
Template File: source-sinks-83_case1V2.tmpl.cpp
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
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_fixed_string_83.h"

#define CASE0_SOURCE_FIXED_STRING L"Fixed String" /* MAINTENANCE NOTE: This string must contain the SEARCH_CHAR */

#define SEARCH_CHAR L'S'

namespace CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_fixed_string_83
{
CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_fixed_string_83_case1V2::CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_fixed_string_83_case1V2(wchar_t * dataCopy)
{
    data = dataCopy;
    /* NOTE: Initialize data to be a fixed string that contains the search character in the sinks */
    wcscpy(data, CASE0_SOURCE_FIXED_STRING);
}

CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_fixed_string_83_case1V2::~CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_fixed_string_83_case1V2()
{
    {
        size_t i;
        /* ALT: Use a loop variable to traverse through the string pointed to by data */
        for (i=0; i < wcslen(data); i++)
        {
            if (data[i] == SEARCH_CHAR)
            {
                printLine("We have a match!");
                break;
            }
        }
        free(data);
    }
}
}
#endif /* OMITCASE1 */
