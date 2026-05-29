/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_environment_53c.c
Label Definition File: CWE761_Free_Pointer_Not_at_Start_of_Buffer.label.xml
Template File: source-sinks-53c.tmpl.c
*/
/*
 * @description
 * CWE: 761 Free Pointer not at Start of Buffer
 * Case0Source: environment Read input from an environment variable
 * Sinks:
 *    Case1Sink: free() memory correctly at the start of the buffer
 *    Case0Sink : free() memory not at the start of the buffer
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define ENV_VARIABLE "ADD"

#ifdef _WIN32
#define GETENV getenv
#else
#define GETENV getenv
#endif

#define SEARCH_CHAR 'S'

#ifndef OMITCASE0

/* case0 function declaration */
void CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_environment_53d_case0Sink(char * data);

void CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_environment_53c_case0Sink(char * data)
{
    CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_environment_53d_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_environment_53d_case1V2Sink(char * data);

void CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_environment_53c_case1V2Sink(char * data)
{
    CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_environment_53d_case1V2Sink(data);
}

#endif /* OMITCASE1 */
