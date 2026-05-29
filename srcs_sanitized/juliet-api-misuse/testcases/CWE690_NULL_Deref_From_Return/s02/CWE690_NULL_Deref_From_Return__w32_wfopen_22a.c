/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__w32_wfopen_22a.c
Label Definition File: CWE690_NULL_Deref_From_Return.fclose.label.xml
Template File: source-sinks-22a.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: w32_wfopen Open data with wfopen()
 * Sinks: 0
 *    Case1Sink: Check data for NULL
 *    Case0Sink : Do not check data for NULL
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the sink function */
int CWE690_NULL_Deref_From_Return__w32_wfopen_22_case0Global = 0;

void CWE690_NULL_Deref_From_Return__w32_wfopen_22_case0Sink(FILE * data);

void CWE690_NULL_Deref_From_Return__w32_wfopen_22_case0()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    /* NOTE: Open a file without checking the return value for NULL */
    data = _wfopen(L"file.txt", L"w+");
    CWE690_NULL_Deref_From_Return__w32_wfopen_22_case0Global = 1; /* true */
    CWE690_NULL_Deref_From_Return__w32_wfopen_22_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the sink functions. */
int CWE690_NULL_Deref_From_Return__w32_wfopen_22_case1V21Global = 0;
int CWE690_NULL_Deref_From_Return__w32_wfopen_22_case1V22Global = 0;

/* case1V21() - use case0source and case1sink by setting the static variable to false instead of true */
void CWE690_NULL_Deref_From_Return__w32_wfopen_22_case1V21Sink(FILE * data);

static void case1V21()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    /* NOTE: Open a file without checking the return value for NULL */
    data = _wfopen(L"file.txt", L"w+");
    CWE690_NULL_Deref_From_Return__w32_wfopen_22_case1V21Global = 0; /* false */
    CWE690_NULL_Deref_From_Return__w32_wfopen_22_case1V21Sink(data);
}

/* case1V22() - use case0source and case1sink by reversing the blocks in the if in the sink function */
void CWE690_NULL_Deref_From_Return__w32_wfopen_22_case1V22Sink(FILE * data);

static void case1V22()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    /* NOTE: Open a file without checking the return value for NULL */
    data = _wfopen(L"file.txt", L"w+");
    CWE690_NULL_Deref_From_Return__w32_wfopen_22_case1V22Global = 1; /* true */
    CWE690_NULL_Deref_From_Return__w32_wfopen_22_case1V22Sink(data);
}

void CWE690_NULL_Deref_From_Return__w32_wfopen_22_case1()
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
    CWE690_NULL_Deref_From_Return__w32_wfopen_22_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE690_NULL_Deref_From_Return__w32_wfopen_22_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
