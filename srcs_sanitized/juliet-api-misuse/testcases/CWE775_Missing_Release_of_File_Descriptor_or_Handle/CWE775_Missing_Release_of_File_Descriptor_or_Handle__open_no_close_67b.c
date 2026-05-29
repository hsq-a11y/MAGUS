/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_67b.c
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close.label.xml
Template File: source-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * Case0Source:  Open a file using open()
 * Sinks:
 *    Case1Sink: Close the file using close()
 *    Case0Sink : Do not close file
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

typedef struct _CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_67_structType
{
    int structFirst;
} CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_67_structType;

#ifndef OMITCASE0

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_67b_case0Sink(CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_67_structType myStruct)
{
    int data = myStruct.structFirst;
    /* NOTE: No attempt to close the file */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_67b_case1V2Sink(CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_67_structType myStruct)
{
    int data = myStruct.structFirst;
    /* ALT: If the file is still opened, close it */
    if (data != -1)
    {
        CLOSE(data);
    }
}

#endif /* OMITCASE1 */
