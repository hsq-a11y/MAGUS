/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__strdup_wchar_t_44.c
Label Definition File: CWE401_Memory_Leak__strdup.label.xml
Template File: sources-sinks-44.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source:  Allocate data using wcsdup()
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call free() on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 44 Data/control flow: data passed as an argument from one function to a function in the same source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

static void case0Sink(wchar_t * data)
{
    /* NOTE: No deallocation of memory */
    /* no deallocation */
    ; /* empty statement needed for some flow variants */
}

void CWE401_Memory_Leak__strdup_wchar_t_44_case0()
{
    wchar_t * data;
    /* define a function pointer */
    void (*funcPtr) (wchar_t *) = case0Sink;
    data = NULL;
    {
        wchar_t myString[] = L"myString";
        /* NOTE: Allocate memory from the heap using a function that requires free() for deallocation */
        data = wcsdup(myString);
        /* Use data */
        printWLine(data);
    }
    /* use the function pointer */
    funcPtr(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
static void case1V1Sink(wchar_t * data)
{
    /* NOTE: No deallocation of memory */
    /* no deallocation */
    ; /* empty statement needed for some flow variants */
}

static void case1V1()
{
    wchar_t * data;
    void (*funcPtr) (wchar_t *) = case1V1Sink;
    data = NULL;
    /* ALT: Use memory allocated on the stack with ALLOCA */
    data = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
    /* Initialize then use data */
    wcscpy(data, L"a string");
    printWLine(data);
    funcPtr(data);
}

/* case1V2() uses the Case0Source with the Case1Sink */
static void case1V2Sink(wchar_t * data)
{
    /* ALT: Deallocate memory initialized in the source */
    free(data);
}

static void case1V2()
{
    wchar_t * data;
    void (*funcPtr) (wchar_t *) = case1V2Sink;
    data = NULL;
    {
        wchar_t myString[] = L"myString";
        /* NOTE: Allocate memory from the heap using a function that requires free() for deallocation */
        data = wcsdup(myString);
        /* Use data */
        printWLine(data);
    }
    funcPtr(data);
}

void CWE401_Memory_Leak__strdup_wchar_t_44_case1()
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
    CWE401_Memory_Leak__strdup_wchar_t_44_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE401_Memory_Leak__strdup_wchar_t_44_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
