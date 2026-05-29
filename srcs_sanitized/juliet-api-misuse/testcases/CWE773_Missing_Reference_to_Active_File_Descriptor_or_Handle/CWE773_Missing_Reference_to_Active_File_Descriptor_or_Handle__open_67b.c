/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_67b.c
Label Definition File: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open.label.xml
Template File: source-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 773 Missing Reference to Active File Descriptor or Handle
 * Case0Source:  Create a file descriptor using open()
 * Sinks:
 *    Case1Sink: Close the file before reusing the file descriptor
 *    Case0Sink : Reassign the file descriptor before closing the file
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
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

typedef struct _CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_67_structType
{
    int structFirst;
} CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_67_structType;

#ifndef OMITCASE0

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_67b_case0Sink(CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_67_structType myStruct)
{
    int data = myStruct.structFirst;
    /* NOTE: Assign data to another file descriptor without closing the descriptor from the source */
    data = OPEN("Case0Sink_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    /* avoid incidental for not closing the file */
    if (data != -1)
    {
        CLOSE(data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_67b_case1V2Sink(CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_67_structType myStruct)
{
    int data = myStruct.structFirst;
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

#endif /* OMITCASE1 */
