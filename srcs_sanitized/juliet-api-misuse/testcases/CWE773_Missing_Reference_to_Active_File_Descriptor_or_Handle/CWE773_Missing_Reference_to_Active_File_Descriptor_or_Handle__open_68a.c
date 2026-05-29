/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_68a.c
Label Definition File: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open.label.xml
Template File: source-sinks-68a.tmpl.c
*/
/*
 * @description
 * CWE: 773 Missing Reference to Active File Descriptor or Handle
 * Case0Source:  Create a file descriptor using open()
 * Sinks:
 *    Case1Sink: Close the file before reusing the file descriptor
 *    Case0Sink : Reassign the file descriptor before closing the file
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
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

int CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_68_case0DataForCase0Sink;

int CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_68_case0DataForCase1Sink;

#ifndef OMITCASE0

/* case0 function declaration */
void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_68b_case0Sink();

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_68_case0()
{
    int data;
    /* Initialize data */
    data = -1;
    /* NOTE: Create a file descriptor using open() that may not be closed properly */
    data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_68_case0DataForCase0Sink = data;
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_68b_case0Sink();
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declarations */
void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_68b_case1V2Sink();

/* case1V2 uses the Case0Source with the Case1Sink */
static void case1V2()
{
    int data;
    /* Initialize data */
    data = -1;
    /* NOTE: Create a file descriptor using open() that may not be closed properly */
    data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_68_case0DataForCase1Sink = data;
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_68b_case1V2Sink();
}

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_68_case1()
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
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_68_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_68_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
