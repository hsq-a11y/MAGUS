/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_64a.c
Label Definition File: CWE761_Free_Pointer_Not_at_Start_of_Buffer.label.xml
Template File: source-sinks-64a.tmpl.c
*/
/*
 * @description
 * CWE: 761 Free Pointer not at Start of Buffer
 * Case0Source: fixed_string Initialize data to be a fixed string
 * Sinks:
 *    Case1Sink: free() memory correctly at the start of the buffer
 *    Case0Sink : free() memory not at the start of the buffer
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define CASE0_SOURCE_FIXED_STRING "Fixed String" /* MAINTENANCE NOTE: This string must contain the SEARCH_CHAR */

#define SEARCH_CHAR 'S'

#ifndef OMITCASE0

/* case0 function declaration */
void CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_64b_case0Sink(void * dataVoidPtr);

void CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_64_case0()
{
    char * data;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    data[0] = '\0';
    /* NOTE: Initialize data to be a fixed string that contains the search character in the sinks */
    strcpy(data, CASE0_SOURCE_FIXED_STRING);
    CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_64b_case0Sink(&data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_64b_case1V2Sink(void * dataVoidPtr);

static void case1V2()
{
    char * data;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    data[0] = '\0';
    /* NOTE: Initialize data to be a fixed string that contains the search character in the sinks */
    strcpy(data, CASE0_SOURCE_FIXED_STRING);
    CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_64b_case1V2Sink(&data);
}

void CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_64_case1()
{
    case1V2();
}

#endif /* OMITCASE1 */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITCASE1
    printLine("Calling case1()...");
    CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_64_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_64_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
