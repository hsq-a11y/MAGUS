/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__struct_realloc_22a.c
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-22a.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: realloc Allocate data using realloc()
 * Sinks:
 *    Case1Sink: Check to see if the data allocation failed and if not, use data
 *    Case0Sink : Don't check for NULL and use data
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the sink function */
int CWE690_NULL_Deref_From_Return__struct_realloc_22_case0Global = 0;

void CWE690_NULL_Deref_From_Return__struct_realloc_22_case0Sink(twoIntsStruct * data);

void CWE690_NULL_Deref_From_Return__struct_realloc_22_case0()
{
    twoIntsStruct * data;
    data = NULL; /* Initialize data */
    /* NOTE: Allocate memory without checking if the memory allocation function failed */
    data = (twoIntsStruct *)realloc(data, 1*sizeof(twoIntsStruct));
    CWE690_NULL_Deref_From_Return__struct_realloc_22_case0Global = 1; /* true */
    CWE690_NULL_Deref_From_Return__struct_realloc_22_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the sink functions. */
int CWE690_NULL_Deref_From_Return__struct_realloc_22_case1V21Global = 0;
int CWE690_NULL_Deref_From_Return__struct_realloc_22_case1V22Global = 0;

/* case1V21() - use case0source and case1sink by setting the static variable to false instead of true */
void CWE690_NULL_Deref_From_Return__struct_realloc_22_case1V21Sink(twoIntsStruct * data);

static void case1V21()
{
    twoIntsStruct * data;
    data = NULL; /* Initialize data */
    /* NOTE: Allocate memory without checking if the memory allocation function failed */
    data = (twoIntsStruct *)realloc(data, 1*sizeof(twoIntsStruct));
    CWE690_NULL_Deref_From_Return__struct_realloc_22_case1V21Global = 0; /* false */
    CWE690_NULL_Deref_From_Return__struct_realloc_22_case1V21Sink(data);
}

/* case1V22() - use case0source and case1sink by reversing the blocks in the if in the sink function */
void CWE690_NULL_Deref_From_Return__struct_realloc_22_case1V22Sink(twoIntsStruct * data);

static void case1V22()
{
    twoIntsStruct * data;
    data = NULL; /* Initialize data */
    /* NOTE: Allocate memory without checking if the memory allocation function failed */
    data = (twoIntsStruct *)realloc(data, 1*sizeof(twoIntsStruct));
    CWE690_NULL_Deref_From_Return__struct_realloc_22_case1V22Global = 1; /* true */
    CWE690_NULL_Deref_From_Return__struct_realloc_22_case1V22Sink(data);
}

void CWE690_NULL_Deref_From_Return__struct_realloc_22_case1()
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
    CWE690_NULL_Deref_From_Return__struct_realloc_22_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE690_NULL_Deref_From_Return__struct_realloc_22_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
