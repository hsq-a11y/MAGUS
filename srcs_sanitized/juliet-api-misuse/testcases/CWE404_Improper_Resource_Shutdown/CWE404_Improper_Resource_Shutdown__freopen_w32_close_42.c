/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__freopen_w32_close_42.c
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-42.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source: freopen Open a file using freopen()
 * Sinks: w32_close
 *    Case1Sink: Close the file using fclose()
 *    Case0Sink : Close the file using close()
 * Flow Variant: 42 Data flow: data returned from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

static FILE * case0Source(FILE * data)
{
    /* NOTE: Open a file - need to make sure it is closed properly in the sink */
    data = freopen("Case0Source_freopen.txt","w+",stdin);
    return data;
}

void CWE404_Improper_Resource_Shutdown__freopen_w32_close_42_case0()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    data = case0Source(data);
    if (data != NULL)
    {
        /* NOTE: Attempt to close the file using close() instead of fclose() */
        _close((int)data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

static FILE * case1V2Source(FILE * data)
{
    /* NOTE: Open a file - need to make sure it is closed properly in the sink */
    data = freopen("Case0Source_freopen.txt","w+",stdin);
    return data;
}

/* case1V2 uses the Case0Source with the Case1Sink */
static void case1V2()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    data = case1V2Source(data);
    if (data != NULL)
    {
        /* ALT: Close the file using fclose() */
        fclose(data);
    }
}

void CWE404_Improper_Resource_Shutdown__freopen_w32_close_42_case1()
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
    CWE404_Improper_Resource_Shutdown__freopen_w32_close_42_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE404_Improper_Resource_Shutdown__freopen_w32_close_42_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
