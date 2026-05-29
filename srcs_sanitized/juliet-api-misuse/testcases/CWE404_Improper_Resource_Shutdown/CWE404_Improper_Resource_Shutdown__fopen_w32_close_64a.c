/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__fopen_w32_close_64a.c
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-64a.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source: fopen Open a file using fopen()
 * Sinks: w32_close
 *    Case1Sink: Close the file using fclose()
 *    Case0Sink : Close the file using close()
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

/* case0 function declaration */
void CWE404_Improper_Resource_Shutdown__fopen_w32_close_64b_case0Sink(void * dataVoidPtr);

void CWE404_Improper_Resource_Shutdown__fopen_w32_close_64_case0()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    /* NOTE: Open a file - need to make sure it is closed properly in the sink */
    data = fopen("Case0Source_fopen.txt", "w+");
    CWE404_Improper_Resource_Shutdown__fopen_w32_close_64b_case0Sink(&data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE404_Improper_Resource_Shutdown__fopen_w32_close_64b_case1V2Sink(void * dataVoidPtr);

static void case1V2()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    /* NOTE: Open a file - need to make sure it is closed properly in the sink */
    data = fopen("Case0Source_fopen.txt", "w+");
    CWE404_Improper_Resource_Shutdown__fopen_w32_close_64b_case1V2Sink(&data);
}

void CWE404_Improper_Resource_Shutdown__fopen_w32_close_64_case1()
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
    CWE404_Improper_Resource_Shutdown__fopen_w32_close_64_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE404_Improper_Resource_Shutdown__fopen_w32_close_64_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
