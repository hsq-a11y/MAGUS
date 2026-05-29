/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_22b.c
Label Definition File: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open.label.xml
Template File: source-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 773 Missing Reference to Active File Descriptor or Handle
 * Case0Source:  Create a file descriptor using open()
 * Sinks:
 *    Case1Sink: Close the file before reusing the file descriptor
 *    Case0Sink : Reassign the file descriptor before closing the file
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
extern int CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_22_case0Global;

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_22_case0Sink(int data)
{
    if(CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_22_case0Global)
    {
        /* NOTE: Assign data to another file descriptor without closing the descriptor from the source */
        data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
        /* avoid incidental for not closing the file */
        if (data != -1)
        {
            CLOSE(data);
        }
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the sink functions. */
extern int CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_22_case1V21Global;
extern int CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_22_case1V22Global;

/* case1V21() - use case0source and case1sink by setting the static variable to false instead of true */
void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_22_case1V21Sink(int data)
{
    if(CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_22_case1V21Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: Close the file from the source before reassigning data to a new file descriptor */
        if (data != -1)
        {
            CLOSE(data);
        }
        data = OPEN("Case1Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
        /* avoid incidental for not closing the file */
        if (data != -1)
        {
            CLOSE(data);
        }
    }
}

/* case1V22() - use case0source and case1sink by reversing the blocks in the if in the sink function */
void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_22_case1V22Sink(int data)
{
    if(CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_22_case1V22Global)
    {
        /* ALT: Close the file from the source before reassigning data to a new file descriptor */
        if (data != -1)
        {
            CLOSE(data);
        }
        data = OPEN("Case1Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
        /* avoid incidental for not closing the file */
        if (data != -1)
        {
            CLOSE(data);
        }
    }
}

#endif /* OMITCASE1 */
