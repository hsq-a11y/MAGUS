/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__wchar_t_malloc_22a.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-22a.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source: malloc Allocate data using malloc()
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call free() on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the sink function */
int CWE401_Memory_Leak__wchar_t_malloc_22_case0Global = 0;

void CWE401_Memory_Leak__wchar_t_malloc_22_case0Sink(wchar_t * data);

void CWE401_Memory_Leak__wchar_t_malloc_22_case0()
{
    wchar_t * data;
    data = NULL;
    /* NOTE: Allocate memory on the heap */
    data = (wchar_t *)malloc(100*sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
    /* Initialize and make use of data */
    wcscpy(data, L"A String");
    printWLine(data);
    CWE401_Memory_Leak__wchar_t_malloc_22_case0Global = 1; /* true */
    CWE401_Memory_Leak__wchar_t_malloc_22_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the sink functions. */
int CWE401_Memory_Leak__wchar_t_malloc_22_case1V21Global = 0;
int CWE401_Memory_Leak__wchar_t_malloc_22_case1V22Global = 0;
int CWE401_Memory_Leak__wchar_t_malloc_22_case1V1Global = 0;

/* case1V21() - use case0source and case1sink by setting the static variable to false instead of true */
void CWE401_Memory_Leak__wchar_t_malloc_22_case1V21Sink(wchar_t * data);

static void case1V21()
{
    wchar_t * data;
    data = NULL;
    /* NOTE: Allocate memory on the heap */
    data = (wchar_t *)malloc(100*sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
    /* Initialize and make use of data */
    wcscpy(data, L"A String");
    printWLine(data);
    CWE401_Memory_Leak__wchar_t_malloc_22_case1V21Global = 0; /* false */
    CWE401_Memory_Leak__wchar_t_malloc_22_case1V21Sink(data);
}

/* case1V22() - use case0source and case1sink by reversing the blocks in the if in the sink function */
void CWE401_Memory_Leak__wchar_t_malloc_22_case1V22Sink(wchar_t * data);

static void case1V22()
{
    wchar_t * data;
    data = NULL;
    /* NOTE: Allocate memory on the heap */
    data = (wchar_t *)malloc(100*sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
    /* Initialize and make use of data */
    wcscpy(data, L"A String");
    printWLine(data);
    CWE401_Memory_Leak__wchar_t_malloc_22_case1V22Global = 1; /* true */
    CWE401_Memory_Leak__wchar_t_malloc_22_case1V22Sink(data);
}

/* case1V1() - use case1source and case0sink */
void CWE401_Memory_Leak__wchar_t_malloc_22_case1V1Sink(wchar_t * data);

static void case1V1()
{
    wchar_t * data;
    data = NULL;
    /* ALT: Use memory allocated on the stack with ALLOCA */
    data = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
    /* Initialize and make use of data */
    wcscpy(data, L"A String");
    printWLine(data);
    CWE401_Memory_Leak__wchar_t_malloc_22_case1V1Global = 1; /* true */
    CWE401_Memory_Leak__wchar_t_malloc_22_case1V1Sink(data);
}

void CWE401_Memory_Leak__wchar_t_malloc_22_case1()
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
    CWE401_Memory_Leak__wchar_t_malloc_22_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE401_Memory_Leak__wchar_t_malloc_22_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
