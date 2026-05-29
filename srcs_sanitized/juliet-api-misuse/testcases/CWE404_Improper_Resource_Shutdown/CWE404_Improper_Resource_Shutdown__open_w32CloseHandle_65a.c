/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_65a.c
Label Definition File: CWE404_Improper_Resource_Shutdown__open.label.xml
Template File: source-sinks-65a.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source:  Open a file using open()
 * Sinks: w32CloseHandle
 *    Case1Sink: Close the file using close()
 *    Case0Sink : Close the file using CloseHandle
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define OPEN _open
#define CLOSE _close
#else
#include <unistd.h>
#define OPEN open
#define CLOSE close
#endif

#include <windows.h>

#ifndef OMITCASE0

/* case0 function declaration */
void CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_65b_case0Sink(int data);

void CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_65_case0()
{
    int data;
    /* define a function pointer */
    void (*funcPtr) (int) = CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_65b_case0Sink;
    /* Initialize data */
    data = -1;
    /* NOTE: Open a file - need to make sure it is closed properly in the sink */
    data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    /* use the function pointer */
    funcPtr(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_65b_case1V2Sink(int data);

static void case1V2()
{
    int data;
    void (*funcPtr) (int) = CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_65b_case1V2Sink;
    /* Initialize data */
    data = -1;
    /* NOTE: Open a file - need to make sure it is closed properly in the sink */
    data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    funcPtr(data);
}

void CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_65_case1()
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
    CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_65_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_65_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
