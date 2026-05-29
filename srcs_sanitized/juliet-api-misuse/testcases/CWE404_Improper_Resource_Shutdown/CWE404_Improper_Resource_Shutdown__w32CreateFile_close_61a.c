/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__w32CreateFile_close_61a.c
Label Definition File: CWE404_Improper_Resource_Shutdown__w32CreateFile.label.xml
Template File: source-sinks-61a.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source:  Open a file using CreateFile()
 * Sinks: close
 *    Case1Sink: Close the file using CloseHandle()
 *    Case0Sink : Close the file using close()
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#ifndef OMITCASE0

/* case0 function declaration */
HANDLE CWE404_Improper_Resource_Shutdown__w32CreateFile_close_61b_case0Source(HANDLE data);

void CWE404_Improper_Resource_Shutdown__w32CreateFile_close_61_case0()
{
    HANDLE data;
    /* Initialize data */
    data = INVALID_HANDLE_VALUE;
    data = CWE404_Improper_Resource_Shutdown__w32CreateFile_close_61b_case0Source(data);
    if (data != INVALID_HANDLE_VALUE)
    {
        /* NOTE: Attempt to close the file using close() instead of CloseHandle() */
        _close((int)data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
HANDLE CWE404_Improper_Resource_Shutdown__w32CreateFile_close_61b_case1V2Source(HANDLE data);

static void case1V2()
{
    HANDLE data;
    /* Initialize data */
    data = INVALID_HANDLE_VALUE;
    data = CWE404_Improper_Resource_Shutdown__w32CreateFile_close_61b_case1V2Source(data);
    if (data != INVALID_HANDLE_VALUE)
    {
        /* ALT: Close the file using CloseHandle() */
        CloseHandle(data);
    }
}

void CWE404_Improper_Resource_Shutdown__w32CreateFile_close_61_case1()
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
    CWE404_Improper_Resource_Shutdown__w32CreateFile_close_61_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE404_Improper_Resource_Shutdown__w32CreateFile_close_61_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
