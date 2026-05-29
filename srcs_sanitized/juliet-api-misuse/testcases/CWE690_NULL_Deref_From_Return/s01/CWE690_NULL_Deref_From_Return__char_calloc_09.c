/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__char_calloc_09.c
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-09.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: calloc Allocate data using calloc()
 * Sinks:
 *    Case1Sink: Check to see if the data allocation failed and if not, use data
 *    Case0Sink : Don't check for NULL and use data
 * Flow Variant: 09 Control flow: if(GLOBAL_CONST_TRUE) and if(GLOBAL_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

void CWE690_NULL_Deref_From_Return__char_calloc_09_case0()
{
    char * data;
    data = NULL; /* Initialize data */
    /* NOTE: Allocate memory without checking if the memory allocation function failed */
    data = (char *)calloc(20, sizeof(char));
    if(GLOBAL_CONST_TRUE)
    {
        /* NOTE: Initialize memory buffer without checking to see if the memory allocation function failed */
        strcpy(data, "Initialize");
        printLine(data);
        free(data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V21() - use case0source and case1sink by changing GLOBAL_CONST_TRUE to GLOBAL_CONST_FALSE */
static void case1V21()
{
    char * data;
    data = NULL; /* Initialize data */
    /* NOTE: Allocate memory without checking if the memory allocation function failed */
    data = (char *)calloc(20, sizeof(char));
    if(GLOBAL_CONST_FALSE)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
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

/* case1V22() - use case0source and case1sink by reversing statements in if  */
static void case1V22()
{
    char * data;
    data = NULL; /* Initialize data */
    /* NOTE: Allocate memory without checking if the memory allocation function failed */
    data = (char *)calloc(20, sizeof(char));
    if(GLOBAL_CONST_TRUE)
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

void CWE690_NULL_Deref_From_Return__char_calloc_09_case1()
{
    case1V21();
    case1V22();
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
    CWE690_NULL_Deref_From_Return__char_calloc_09_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE690_NULL_Deref_From_Return__char_calloc_09_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
