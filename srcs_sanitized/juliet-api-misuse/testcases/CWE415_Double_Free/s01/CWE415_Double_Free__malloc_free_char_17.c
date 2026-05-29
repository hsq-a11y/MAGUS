/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_char_17.c
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-17.tmpl.c
*/
/*
 * @description
 * CWE: 415 Double Free
 * Case0Source:  Allocate data using malloc() and Deallocate data using free()
 * Case1Source: Allocate data using malloc()
 * Sinks:
 *    Case1Sink: do nothing
 *    Case0Sink : Deallocate data using free()
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

void CWE415_Double_Free__malloc_free_char_17_case0()
{
    int i,j;
    char * data;
    /* Initialize data */
    data = NULL;
    for(i = 0; i < 1; i++)
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        /* NOTE: Free data in the source - the case0 sink frees data as well */
        free(data);
    }
    for(j = 0; j < 1; j++)
    {
        /* NOTE: Possibly freeing memory twice */
        free(data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2() - use case0source and case1sink in the for statements */
static void case1V2()
{
    int i,k;
    char * data;
    /* Initialize data */
    data = NULL;
    for(i = 0; i < 1; i++)
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        /* NOTE: Free data in the source - the case0 sink frees data as well */
        free(data);
    }
    for(k = 0; k < 1; k++)
    {
        /* do nothing */
        /* ALT: Don't attempt to free the memory */
        ; /* empty statement needed for some flow variants */
    }
}

/* case1V1() - use case1source and case0sink in the for statements */
static void case1V1()
{
    int h,j;
    char * data;
    /* Initialize data */
    data = NULL;
    for(h = 0; h < 1; h++)
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        /* ALT: Do NOT free data in the source - the case0 sink frees data */
    }
    for(j = 0; j < 1; j++)
    {
        /* NOTE: Possibly freeing memory twice */
        free(data);
    }
}

void CWE415_Double_Free__malloc_free_char_17_case1()
{
    case1V2();
    case1V1();
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
    CWE415_Double_Free__malloc_free_char_17_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE415_Double_Free__malloc_free_char_17_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
