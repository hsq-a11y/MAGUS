/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_char_relativePath_68a.c
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 114 Process Control
 * Case0Source: relativePath Hard code the relative pathname to the library
 * Case1Source: Hard code the full pathname to the library
 * Sink:
 *    Case0Sink : Load a dynamic link library
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#include <windows.h>

char * CWE114_Process_Control__w32_char_relativePath_68_case0Data;
char * CWE114_Process_Control__w32_char_relativePath_68_case1V1Data;

#ifndef OMITCASE0

/* case0 function declaration */
void CWE114_Process_Control__w32_char_relativePath_68b_case0Sink();

void CWE114_Process_Control__w32_char_relativePath_68_case0()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    /* NOTE: Specify just the file name for the library, not the full path */
    strcpy(data, "winsrv.dll");
    CWE114_Process_Control__w32_char_relativePath_68_case0Data = data;
    CWE114_Process_Control__w32_char_relativePath_68b_case0Sink();
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declarations */
void CWE114_Process_Control__w32_char_relativePath_68b_case1V1Sink();

/* case1V1 uses the Case1Source with the Case0Sink */
static void case1V1()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    /* ALT: Specify the full pathname for the library */
    strcpy(data, "C:\\Windows\\System32\\winsrv.dll");
    CWE114_Process_Control__w32_char_relativePath_68_case1V1Data = data;
    CWE114_Process_Control__w32_char_relativePath_68b_case1V1Sink();
}

void CWE114_Process_Control__w32_char_relativePath_68_case1()
{
    case1V1();
}

#endif /* OMITCASE1 */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITCASE1
    printLine("Calling case1()...");
    CWE114_Process_Control__w32_char_relativePath_68_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE114_Process_Control__w32_char_relativePath_68_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
