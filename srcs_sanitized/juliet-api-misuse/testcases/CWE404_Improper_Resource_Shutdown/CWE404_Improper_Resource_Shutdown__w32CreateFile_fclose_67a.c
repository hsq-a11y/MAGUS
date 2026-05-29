/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_67a.c
Label Definition File: CWE404_Improper_Resource_Shutdown__w32CreateFile.label.xml
Template File: source-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source:  Open a file using CreateFile()
 * Sinks: fclose
 *    Case1Sink: Close the file using CloseHandle()
 *    Case0Sink : Close the file using fclose()
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>

typedef struct _CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_67_structType
{
    HANDLE structFirst;
} CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_67_structType;

#ifndef OMITCASE0

/* case0 function declaration */
void CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_67b_case0Sink(CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_67_structType myStruct);

void CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_67_case0()
{
    HANDLE data;
    CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_67_structType myStruct;
    /* Initialize data */
    data = INVALID_HANDLE_VALUE;
    /* NOTE: Open a file - need to make sure it is closed properly in the sink */
    data = CreateFile("Case0Source_w32CreateFile.txt",
                      (GENERIC_WRITE|GENERIC_READ),
                      0,
                      NULL,
                      OPEN_ALWAYS,
                      FILE_ATTRIBUTE_NORMAL,
                      NULL);
    myStruct.structFirst = data;
    CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_67b_case0Sink(myStruct);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_67b_case1V2Sink(CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_67_structType myStruct);

static void case1V2()
{
    HANDLE data;
    CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_67_structType myStruct;
    /* Initialize data */
    data = INVALID_HANDLE_VALUE;
    /* NOTE: Open a file - need to make sure it is closed properly in the sink */
    data = CreateFile("Case0Source_w32CreateFile.txt",
                      (GENERIC_WRITE|GENERIC_READ),
                      0,
                      NULL,
                      OPEN_ALWAYS,
                      FILE_ATTRIBUTE_NORMAL,
                      NULL);
    myStruct.structFirst = data;
    CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_67b_case1V2Sink(myStruct);
}

void CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_67_case1()
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
    CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_67_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_67_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
