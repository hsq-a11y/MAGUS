/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__int_calloc_67a.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source: calloc Allocate data using calloc()
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call free() on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE401_Memory_Leak__int_calloc_67_structType
{
    int * structFirst;
} CWE401_Memory_Leak__int_calloc_67_structType;

#ifndef OMITCASE0

/* case0 function declaration */
void CWE401_Memory_Leak__int_calloc_67b_case0Sink(CWE401_Memory_Leak__int_calloc_67_structType myStruct);

void CWE401_Memory_Leak__int_calloc_67_case0()
{
    int * data;
    CWE401_Memory_Leak__int_calloc_67_structType myStruct;
    data = NULL;
    /* NOTE: Allocate memory on the heap */
    data = (int *)calloc(100, sizeof(int));
    if (data == NULL) {exit(-1);}
    /* Initialize and make use of data */
    data[0] = 5;
    printIntLine(data[0]);
    myStruct.structFirst = data;
    CWE401_Memory_Leak__int_calloc_67b_case0Sink(myStruct);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE401_Memory_Leak__int_calloc_67b_case1V1Sink(CWE401_Memory_Leak__int_calloc_67_structType myStruct);

static void case1V1()
{
    int * data;
    CWE401_Memory_Leak__int_calloc_67_structType myStruct;
    data = NULL;
    /* ALT: Use memory allocated on the stack with ALLOCA */
    data = (int *)ALLOCA(100*sizeof(int));
    /* Initialize and make use of data */
    data[0] = 5;
    printIntLine(data[0]);
    myStruct.structFirst = data;
    CWE401_Memory_Leak__int_calloc_67b_case1V1Sink(myStruct);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE401_Memory_Leak__int_calloc_67b_case1V2Sink(CWE401_Memory_Leak__int_calloc_67_structType myStruct);

static void case1V2()
{
    int * data;
    CWE401_Memory_Leak__int_calloc_67_structType myStruct;
    data = NULL;
    /* NOTE: Allocate memory on the heap */
    data = (int *)calloc(100, sizeof(int));
    if (data == NULL) {exit(-1);}
    /* Initialize and make use of data */
    data[0] = 5;
    printIntLine(data[0]);
    myStruct.structFirst = data;
    CWE401_Memory_Leak__int_calloc_67b_case1V2Sink(myStruct);
}

void CWE401_Memory_Leak__int_calloc_67_case1()
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
    CWE401_Memory_Leak__int_calloc_67_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE401_Memory_Leak__int_calloc_67_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
