/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_int_67a.c
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 415 Double Free
 * Case0Source:  Allocate data using malloc() and Deallocate data using free()
 * Case1Source: Allocate data using malloc()
 * Sinks:
 *    Case1Sink: do nothing
 *    Case0Sink : Deallocate data using free()
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE415_Double_Free__malloc_free_int_67_structType
{
    int * structFirst;
} CWE415_Double_Free__malloc_free_int_67_structType;

#ifndef OMITCASE0

/* case0 function declaration */
void CWE415_Double_Free__malloc_free_int_67b_case0Sink(CWE415_Double_Free__malloc_free_int_67_structType myStruct);

void CWE415_Double_Free__malloc_free_int_67_case0()
{
    int * data;
    CWE415_Double_Free__malloc_free_int_67_structType myStruct;
    /* Initialize data */
    data = NULL;
    data = (int *)malloc(100*sizeof(int));
    if (data == NULL) {exit(-1);}
    /* NOTE: Free data in the source - the case0 sink frees data as well */
    free(data);
    myStruct.structFirst = data;
    CWE415_Double_Free__malloc_free_int_67b_case0Sink(myStruct);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE415_Double_Free__malloc_free_int_67b_case1V1Sink(CWE415_Double_Free__malloc_free_int_67_structType myStruct);

static void case1V1()
{
    int * data;
    CWE415_Double_Free__malloc_free_int_67_structType myStruct;
    /* Initialize data */
    data = NULL;
    data = (int *)malloc(100*sizeof(int));
    if (data == NULL) {exit(-1);}
    /* ALT: Do NOT free data in the source - the case0 sink frees data */
    myStruct.structFirst = data;
    CWE415_Double_Free__malloc_free_int_67b_case1V1Sink(myStruct);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE415_Double_Free__malloc_free_int_67b_case1V2Sink(CWE415_Double_Free__malloc_free_int_67_structType myStruct);

static void case1V2()
{
    int * data;
    CWE415_Double_Free__malloc_free_int_67_structType myStruct;
    /* Initialize data */
    data = NULL;
    data = (int *)malloc(100*sizeof(int));
    if (data == NULL) {exit(-1);}
    /* NOTE: Free data in the source - the case0 sink frees data as well */
    free(data);
    myStruct.structFirst = data;
    CWE415_Double_Free__malloc_free_int_67b_case1V2Sink(myStruct);
}

void CWE415_Double_Free__malloc_free_int_67_case1()
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
    CWE415_Double_Free__malloc_free_int_67_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE415_Double_Free__malloc_free_int_67_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
