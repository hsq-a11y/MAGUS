/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_52b.c
Label Definition File: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open.label.xml
Template File: source-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 773 Missing Reference to Active File Descriptor or Handle
 * Case0Source:  Create a file descriptor using open()
 * Sinks:
 *    Case1Sink: Close the file before reusing the file descriptor
 *    Case0Sink : Reassign the file descriptor before closing the file
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
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

/* case0 function declaration */
void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_52c_case0Sink(int data);

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_52b_case0Sink(int data)
{
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_52c_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_52c_case1V2Sink(int data);

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_52b_case1V2Sink(int data)
{
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_52c_case1V2Sink(data);
}

#endif /* OMITCASE1 */
