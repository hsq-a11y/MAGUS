/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__w32_wfopen_34.c
Label Definition File: CWE690_NULL_Deref_From_Return.fclose.label.xml
Template File: source-sinks-34.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: w32_wfopen Open data with wfopen()
 * Sinks: 0
 *    Case1Sink: Check data for NULL
 *    Case0Sink : Do not check data for NULL
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

typedef union
{
    FILE * unionFirst;
    FILE * unionSecond;
} CWE690_NULL_Deref_From_Return__w32_wfopen_34_unionType;

#ifndef OMITCASE0

void CWE690_NULL_Deref_From_Return__w32_wfopen_34_case0()
{
    FILE * data;
    CWE690_NULL_Deref_From_Return__w32_wfopen_34_unionType myUnion;
    /* Initialize data */
    data = NULL;
    /* NOTE: Open a file without checking the return value for NULL */
    data = _wfopen(L"file.txt", L"w+");
    myUnion.unionFirst = data;
    {
        FILE * data = myUnion.unionSecond;
        /* NOTE: if the fopen failed, data will be NULL here */
        fclose(data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2() uses the Case0Source with the Case1Sink */
static void case1V2()
{
    FILE * data;
    CWE690_NULL_Deref_From_Return__w32_wfopen_34_unionType myUnion;
    /* Initialize data */
    data = NULL;
    /* NOTE: Open a file without checking the return value for NULL */
    data = _wfopen(L"file.txt", L"w+");
    myUnion.unionFirst = data;
    {
        FILE * data = myUnion.unionSecond;
        /* ALT: check the return value */
        if (data != NULL)
        {
            fclose(data);
        }
    }
}

void CWE690_NULL_Deref_From_Return__w32_wfopen_34_case1()
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
    CWE690_NULL_Deref_From_Return__w32_wfopen_34_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE690_NULL_Deref_From_Return__w32_wfopen_34_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
