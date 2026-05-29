/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__twoIntsStruct_realloc_61a.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-61a.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source: realloc Allocate data using realloc()
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call free() on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

/* case0 function declaration */
twoIntsStruct * CWE401_Memory_Leak__twoIntsStruct_realloc_61b_case0Source(twoIntsStruct * data);

void CWE401_Memory_Leak__twoIntsStruct_realloc_61_case0()
{
    twoIntsStruct * data;
    data = NULL;
    data = CWE401_Memory_Leak__twoIntsStruct_realloc_61b_case0Source(data);
    /* NOTE: No deallocation */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
twoIntsStruct * CWE401_Memory_Leak__twoIntsStruct_realloc_61b_case1V1Source(twoIntsStruct * data);

static void case1V1()
{
    twoIntsStruct * data;
    data = NULL;
    data = CWE401_Memory_Leak__twoIntsStruct_realloc_61b_case1V1Source(data);
    /* NOTE: No deallocation */
    ; /* empty statement needed for some flow variants */
}

/* case1V2 uses the Case0Source with the Case1Sink */
twoIntsStruct * CWE401_Memory_Leak__twoIntsStruct_realloc_61b_case1V2Source(twoIntsStruct * data);

static void case1V2()
{
    twoIntsStruct * data;
    data = NULL;
    data = CWE401_Memory_Leak__twoIntsStruct_realloc_61b_case1V2Source(data);
    /* ALT: Deallocate memory */
    free(data);
}

void CWE401_Memory_Leak__twoIntsStruct_realloc_61_case1()
{
    case1V1();
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
    CWE401_Memory_Leak__twoIntsStruct_realloc_61_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE401_Memory_Leak__twoIntsStruct_realloc_61_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
