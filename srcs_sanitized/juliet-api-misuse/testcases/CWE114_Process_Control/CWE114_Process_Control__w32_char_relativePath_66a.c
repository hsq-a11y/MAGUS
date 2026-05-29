/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_char_relativePath_66a.c
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-66a.tmpl.c
*/
/*
 * @description
 * CWE: 114 Process Control
 * Case0Source: relativePath Hard code the relative pathname to the library
 * Case1Source: Hard code the full pathname to the library
 * Sinks:
 *    Case0Sink : Load a dynamic link library
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#include <windows.h>

#ifndef OMITCASE0

/* case0 function declaration */
void CWE114_Process_Control__w32_char_relativePath_66b_case0Sink(char * dataArray[]);

void CWE114_Process_Control__w32_char_relativePath_66_case0()
{
    char * data;
    char * dataArray[5];
    char dataBuffer[100] = "";
    data = dataBuffer;
    /* NOTE: Specify just the file name for the library, not the full path */
    strcpy(data, "winsrv.dll");
    /* put data in array */
    dataArray[2] = data;
    CWE114_Process_Control__w32_char_relativePath_66b_case0Sink(dataArray);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE114_Process_Control__w32_char_relativePath_66b_case1V1Sink(char * dataArray[]);

static void case1V1()
{
    char * data;
    char * dataArray[5];
    char dataBuffer[100] = "";
    data = dataBuffer;
    /* ALT: Specify the full pathname for the library */
    strcpy(data, "C:\\Windows\\System32\\winsrv.dll");
    dataArray[2] = data;
    CWE114_Process_Control__w32_char_relativePath_66b_case1V1Sink(dataArray);
}

void CWE114_Process_Control__w32_char_relativePath_66_case1()
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
    CWE114_Process_Control__w32_char_relativePath_66_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE114_Process_Control__w32_char_relativePath_66_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
