/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_int64_t_22a.c
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-22a.tmpl.c
*/
/*
 * @description
 * CWE: 415 Double Free
 * Case0Source:  Allocate data using malloc() and Deallocate data using free()
 * Case1Source: Allocate data using malloc()
 * Sinks:
 *    Case1Sink: do nothing
 *    Case0Sink : Deallocate data using free()
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the sink function */
int CWE415_Double_Free__malloc_free_int64_t_22_case0Global = 0;

void CWE415_Double_Free__malloc_free_int64_t_22_case0Sink(int64_t * data);

void CWE415_Double_Free__malloc_free_int64_t_22_case0()
{
    int64_t * data;
    /* Initialize data */
    data = NULL;
    data = (int64_t *)malloc(100*sizeof(int64_t));
    if (data == NULL) {exit(-1);}
    /* NOTE: Free data in the source - the case0 sink frees data as well */
    free(data);
    CWE415_Double_Free__malloc_free_int64_t_22_case0Global = 1; /* true */
    CWE415_Double_Free__malloc_free_int64_t_22_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the sink functions. */
int CWE415_Double_Free__malloc_free_int64_t_22_case1V21Global = 0;
int CWE415_Double_Free__malloc_free_int64_t_22_case1V22Global = 0;
int CWE415_Double_Free__malloc_free_int64_t_22_case1V1Global = 0;

/* case1V21() - use case0source and case1sink by setting the static variable to false instead of true */
void CWE415_Double_Free__malloc_free_int64_t_22_case1V21Sink(int64_t * data);

static void case1V21()
{
    int64_t * data;
    /* Initialize data */
    data = NULL;
    data = (int64_t *)malloc(100*sizeof(int64_t));
    if (data == NULL) {exit(-1);}
    /* NOTE: Free data in the source - the case0 sink frees data as well */
    free(data);
    CWE415_Double_Free__malloc_free_int64_t_22_case1V21Global = 0; /* false */
    CWE415_Double_Free__malloc_free_int64_t_22_case1V21Sink(data);
}

/* case1V22() - use case0source and case1sink by reversing the blocks in the if in the sink function */
void CWE415_Double_Free__malloc_free_int64_t_22_case1V22Sink(int64_t * data);

static void case1V22()
{
    int64_t * data;
    /* Initialize data */
    data = NULL;
    data = (int64_t *)malloc(100*sizeof(int64_t));
    if (data == NULL) {exit(-1);}
    /* NOTE: Free data in the source - the case0 sink frees data as well */
    free(data);
    CWE415_Double_Free__malloc_free_int64_t_22_case1V22Global = 1; /* true */
    CWE415_Double_Free__malloc_free_int64_t_22_case1V22Sink(data);
}

/* case1V1() - use case1source and case0sink */
void CWE415_Double_Free__malloc_free_int64_t_22_case1V1Sink(int64_t * data);

static void case1V1()
{
    int64_t * data;
    /* Initialize data */
    data = NULL;
    data = (int64_t *)malloc(100*sizeof(int64_t));
    if (data == NULL) {exit(-1);}
    /* ALT: Do NOT free data in the source - the case0 sink frees data */
    CWE415_Double_Free__malloc_free_int64_t_22_case1V1Global = 1; /* true */
    CWE415_Double_Free__malloc_free_int64_t_22_case1V1Sink(data);
}

void CWE415_Double_Free__malloc_free_int64_t_22_case1()
{
    case1V21();
    case1V22();
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
    CWE415_Double_Free__malloc_free_int64_t_22_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE415_Double_Free__malloc_free_int64_t_22_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
