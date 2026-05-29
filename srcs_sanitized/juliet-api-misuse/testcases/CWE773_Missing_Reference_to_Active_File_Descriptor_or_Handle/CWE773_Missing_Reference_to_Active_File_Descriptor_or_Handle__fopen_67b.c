/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_67b.c
Label Definition File: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen.label.xml
Template File: source-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 773 Missing Reference to Active File Descriptor or Handle
 * Case0Source:  Create a file handle using fopen()
 * Sinks:
 *    Case1Sink: Close the file handle before reusing it
 *    Case0Sink : Reassign the file handle before closing it
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_67_structType
{
    FILE * structFirst;
} CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_67_structType;

#ifndef OMITCASE0

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_67b_case0Sink(CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_67_structType myStruct)
{
    FILE * data = myStruct.structFirst;
    /* NOTE: Point data to another file handle without closing the handle from the source */
    data = fopen("Case0Sink_fopen.txt", "w+");
    /* avoid incidental for not closing the file handle */
    if (data != NULL)
    {
        fclose(data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_67b_case1V2Sink(CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_67_structType myStruct)
{
    FILE * data = myStruct.structFirst;
    /* ALT: Close the file from the source before pointing data to a new file handle */
    if (data != NULL)
    {
        fclose(data);
    }
    data = fopen("Case1Sink_fopen.txt", "w+");
    /* avoid incidental for not closing the file handle */
    if (data != NULL)
    {
        fclose(data);
    }
}

#endif /* OMITCASE1 */
