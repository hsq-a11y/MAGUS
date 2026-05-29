/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__int64_t_malloc_68a.c
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-68a.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: malloc Allocate data using malloc()
 * Sinks:
 *    Case1Sink: Check to see if the data allocation failed and if not, use data
 *    Case0Sink : Don't check for NULL and use data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

int64_t * CWE690_NULL_Deref_From_Return__int64_t_malloc_68_case0DataForCase0Sink;

int64_t * CWE690_NULL_Deref_From_Return__int64_t_malloc_68_case0DataForCase1Sink;

#ifndef OMITCASE0

/* case0 function declaration */
void CWE690_NULL_Deref_From_Return__int64_t_malloc_68b_case0Sink();

void CWE690_NULL_Deref_From_Return__int64_t_malloc_68_case0()
{
    int64_t * data;
    data = NULL; /* Initialize data */
    /* NOTE: Allocate memory without checking if the memory allocation function failed */
    data = (int64_t *)malloc(1*sizeof(int64_t));
    CWE690_NULL_Deref_From_Return__int64_t_malloc_68_case0DataForCase0Sink = data;
    CWE690_NULL_Deref_From_Return__int64_t_malloc_68b_case0Sink();
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declarations */
void CWE690_NULL_Deref_From_Return__int64_t_malloc_68b_case1V2Sink();

/* case1V2 uses the Case0Source with the Case1Sink */
static void case1V2()
{
    int64_t * data;
    data = NULL; /* Initialize data */
    /* NOTE: Allocate memory without checking if the memory allocation function failed */
    data = (int64_t *)malloc(1*sizeof(int64_t));
    CWE690_NULL_Deref_From_Return__int64_t_malloc_68_case0DataForCase1Sink = data;
    CWE690_NULL_Deref_From_Return__int64_t_malloc_68b_case1V2Sink();
}

void CWE690_NULL_Deref_From_Return__int64_t_malloc_68_case1()
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
    CWE690_NULL_Deref_From_Return__int64_t_malloc_68_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE690_NULL_Deref_From_Return__int64_t_malloc_68_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
