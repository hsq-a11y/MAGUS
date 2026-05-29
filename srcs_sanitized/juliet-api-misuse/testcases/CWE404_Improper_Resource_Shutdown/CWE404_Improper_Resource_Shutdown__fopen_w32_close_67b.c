/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__fopen_w32_close_67b.c
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source: fopen Open a file using fopen()
 * Sinks: w32_close
 *    Case1Sink: Close the file using fclose()
 *    Case0Sink : Close the file using close()
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE404_Improper_Resource_Shutdown__fopen_w32_close_67_structType
{
    FILE * structFirst;
} CWE404_Improper_Resource_Shutdown__fopen_w32_close_67_structType;

#ifndef OMITCASE0

void CWE404_Improper_Resource_Shutdown__fopen_w32_close_67b_case0Sink(CWE404_Improper_Resource_Shutdown__fopen_w32_close_67_structType myStruct)
{
    FILE * data = myStruct.structFirst;
    if (data != NULL)
    {
        /* NOTE: Attempt to close the file using close() instead of fclose() */
        _close((int)data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE404_Improper_Resource_Shutdown__fopen_w32_close_67b_case1V2Sink(CWE404_Improper_Resource_Shutdown__fopen_w32_close_67_structType myStruct)
{
    FILE * data = myStruct.structFirst;
    if (data != NULL)
    {
        /* ALT: Close the file using fclose() */
        fclose(data);
    }
}

#endif /* OMITCASE1 */
