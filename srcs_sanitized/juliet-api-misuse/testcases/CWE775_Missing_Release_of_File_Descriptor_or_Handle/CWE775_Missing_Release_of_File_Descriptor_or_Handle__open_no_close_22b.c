/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_22b.c
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close.label.xml
Template File: source-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * Case0Source:  Open a file using open()
 * Sinks:
 *    Case1Sink: Close the file using close()
 *    Case0Sink : Do not close file
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
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

/* The global variable below is used to drive control flow in the sink function */
extern int CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_22_case0Global;

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_22_case0Sink(int data)
{
    if(CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_22_case0Global)
    {
        /* NOTE: No attempt to close the file */
        ; /* empty statement needed for some flow variants */
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the sink functions. */
extern int CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_22_case1V21Global;
extern int CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_22_case1V22Global;

/* case1V21() - use case0source and case1sink by setting the static variable to false instead of true */
void CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_22_case1V21Sink(int data)
{
    if(CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_22_case1V21Global)
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

/* case1V22() - use case0source and case1sink by reversing the blocks in the if in the sink function */
void CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_22_case1V22Sink(int data)
{
    if(CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_22_case1V22Global)
    {
        /* ALT: If the file is still opened, close it */
        if (data != -1)
        {
            CLOSE(data);
        }
    }
}

#endif /* OMITCASE1 */
