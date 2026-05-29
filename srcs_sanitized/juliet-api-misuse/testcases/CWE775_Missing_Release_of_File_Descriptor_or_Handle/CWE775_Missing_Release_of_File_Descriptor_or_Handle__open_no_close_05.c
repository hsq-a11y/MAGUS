/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_05.c
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close.label.xml
Template File: source-sinks-05.tmpl.c
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * Case0Source:  Open a file using open()
 * Sinks:
 *    Case1Sink: Close the file using close()
 *    Case0Sink : Do not close file
 * Flow Variant: 05 Control flow: if(staticTrue) and if(staticFalse)
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

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int staticTrue = 1; /* true */
static int staticFalse = 0; /* false */

#ifndef OMITCASE0

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_05_case0()
{
    int data;
    /* Initialize data */
    data = -1;
    /* NOTE: Open a file without closing it */
    data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    if(staticTrue)
    {
        /* NOTE: No attempt to close the file */
        ; /* empty statement needed for some flow variants */
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V21() - use case0source and case1sink by changing staticTrue to staticFalse */
static void case1V21()
{
    int data;
    /* Initialize data */
    data = -1;
    /* NOTE: Open a file without closing it */
    data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    if(staticFalse)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: If the file is still opened, close it */
        if (data != -1)
        {
            CLOSE(data);
        }
    }
}

/* case1V22() - use case0source and case1sink by reversing statements in if  */
static void case1V22()
{
    int data;
    /* Initialize data */
    data = -1;
    /* NOTE: Open a file without closing it */
    data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    if(staticTrue)
    {
        /* ALT: If the file is still opened, close it */
        if (data != -1)
        {
            CLOSE(data);
        }
    }
}

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_05_case1()
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
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_05_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_05_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
