/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_68a.c
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close.label.xml
Template File: source-sinks-68a.tmpl.c
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * Case0Source:  Open a file using CreateFile()
 * Sinks:
 *    Case1Sink: Close the file using CloseHandle()
 *    Case0Sink : Do not close file
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>

HANDLE CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_68_case0DataForCase0Sink;

HANDLE CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_68_case0DataForCase1Sink;

#ifndef OMITCASE0

/* case0 function declaration */
void CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_68b_case0Sink();

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_68_case0()
{
    HANDLE data;
    /* Initialize data */
    data = INVALID_HANDLE_VALUE;
    /* NOTE: Open a file without closing it */
    data = CreateFile("Case0Source_w32CreateFile.txt",
                      (GENERIC_WRITE|GENERIC_READ),
                      0,
                      NULL,
                      OPEN_ALWAYS,
                      FILE_ATTRIBUTE_NORMAL,
                      NULL);
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_68_case0DataForCase0Sink = data;
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_68b_case0Sink();
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declarations */
void CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_68b_case1V2Sink();

/* case1V2 uses the Case0Source with the Case1Sink */
static void case1V2()
{
    HANDLE data;
    /* Initialize data */
    data = INVALID_HANDLE_VALUE;
    /* NOTE: Open a file without closing it */
    data = CreateFile("Case0Source_w32CreateFile.txt",
                      (GENERIC_WRITE|GENERIC_READ),
                      0,
                      NULL,
                      OPEN_ALWAYS,
                      FILE_ATTRIBUTE_NORMAL,
                      NULL);
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_68_case0DataForCase1Sink = data;
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_68b_case1V2Sink();
}

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_68_case1()
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
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_68_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_68_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
