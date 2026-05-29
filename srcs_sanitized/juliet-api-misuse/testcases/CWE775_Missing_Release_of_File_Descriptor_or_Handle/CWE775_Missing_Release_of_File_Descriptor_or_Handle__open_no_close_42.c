/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_42.c
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close.label.xml
Template File: source-sinks-42.tmpl.c
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * Case0Source:  Open a file using open()
 * Sinks:
 *    Case1Sink: Close the file using close()
 *    Case0Sink : Do not close file
 * Flow Variant: 42 Data flow: data returned from one function to another in the same source file
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

#ifndef OMITCASE0

static int case0Source(int data)
{
    /* NOTE: Open a file without closing it */
    data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    return data;
}

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_42_case0()
{
    int data;
    /* Initialize data */
    data = -1;
    data = case0Source(data);
    /* NOTE: No attempt to close the file */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

static int case1V2Source(int data)
{
    /* NOTE: Open a file without closing it */
    data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    return data;
}

/* case1V2 uses the Case0Source with the Case1Sink */
static void case1V2()
{
    int data;
    /* Initialize data */
    data = -1;
    data = case1V2Source(data);
    /* ALT: If the file is still opened, close it */
    if (data != -1)
    {
        CLOSE(data);
    }
}

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_42_case1()
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
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_42_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_42_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
