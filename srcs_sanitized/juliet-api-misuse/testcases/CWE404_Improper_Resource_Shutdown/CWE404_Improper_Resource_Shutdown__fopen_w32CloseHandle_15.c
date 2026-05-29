/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_15.c
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-15.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source: fopen Open a file using fopen()
 * Sinks: w32CloseHandle
 *    Case1Sink: Close the file using fclose()
 *    Case0Sink : Close the file using CloseHandle
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#ifndef OMITCASE0

void CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_15_case0()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    /* NOTE: Open a file - need to make sure it is closed properly in the sink */
    data = fopen("Case0Source_fopen.txt", "w+");
    switch(6)
    {
    case 6:
        if (data != NULL)
        {
            /* NOTE: Attempt to close the file using CloseHandle() instead of fclose() */
            CloseHandle((HANDLE)data);
        }
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V21() - use case0source and case1sink by changing the switch to switch(5) */
static void case1V21()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    /* NOTE: Open a file - need to make sure it is closed properly in the sink */
    data = fopen("Case0Source_fopen.txt", "w+");
    switch(5)
    {
    case 6:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    default:
        if (data != NULL)
        {
            /* ALT: Close the file using fclose() */
            fclose(data);
        }
        break;
    }
}

/* case1V22() - use case0source and case1sink by reversing the blocks in the switch */
static void case1V22()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    /* NOTE: Open a file - need to make sure it is closed properly in the sink */
    data = fopen("Case0Source_fopen.txt", "w+");
    switch(6)
    {
    case 6:
        if (data != NULL)
        {
            /* ALT: Close the file using fclose() */
            fclose(data);
        }
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    }
}

void CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_15_case1()
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
    CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_15_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_15_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
