/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__w32_wfopen_45.c
Label Definition File: CWE690_NULL_Deref_From_Return.fclose.label.xml
Template File: source-sinks-45.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: w32_wfopen Open data with wfopen()
 * Sinks: 0
 *    Case1Sink: Check data for NULL
 *    Case0Sink : Do not check data for NULL
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

static FILE * CWE690_NULL_Deref_From_Return__w32_wfopen_45_case0Data;
static FILE * CWE690_NULL_Deref_From_Return__w32_wfopen_45_case1V2Data;

#ifndef OMITCASE0

static void case0Sink()
{
    FILE * data = CWE690_NULL_Deref_From_Return__w32_wfopen_45_case0Data;
    /* NOTE: if the fopen failed, data will be NULL here */
    fclose(data);
}

void CWE690_NULL_Deref_From_Return__w32_wfopen_45_case0()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    /* NOTE: Open a file without checking the return value for NULL */
    data = _wfopen(L"file.txt", L"w+");
    CWE690_NULL_Deref_From_Return__w32_wfopen_45_case0Data = data;
    case0Sink();
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2() uses the Case0Source with the Case1Sink */
static void case1V2Sink()
{
    FILE * data = CWE690_NULL_Deref_From_Return__w32_wfopen_45_case1V2Data;
    /* ALT: check the return value */
    if (data != NULL)
    {
        fclose(data);
    }
}

static void case1V2()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    /* NOTE: Open a file without checking the return value for NULL */
    data = _wfopen(L"file.txt", L"w+");
    CWE690_NULL_Deref_From_Return__w32_wfopen_45_case1V2Data = data;
    case1V2Sink();
}

void CWE690_NULL_Deref_From_Return__w32_wfopen_45_case1()
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
    CWE690_NULL_Deref_From_Return__w32_wfopen_45_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE690_NULL_Deref_From_Return__w32_wfopen_45_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
