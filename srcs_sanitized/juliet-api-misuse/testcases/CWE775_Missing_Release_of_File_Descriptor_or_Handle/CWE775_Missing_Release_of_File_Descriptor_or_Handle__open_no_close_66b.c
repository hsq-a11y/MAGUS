/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_66b.c
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close.label.xml
Template File: source-sinks-66b.tmpl.c
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * Case0Source:  Open a file using open()
 * Sinks:
 *    Case1Sink: Close the file using close()
 *    Case0Sink : Do not close file
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
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

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_66b_case0Sink(int dataArray[])
{
    /* copy data out of dataArray */
    int data = dataArray[2];
    /* NOTE: No attempt to close the file */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_66b_case1V2Sink(int dataArray[])
{
    int data = dataArray[2];
    /* ALT: If the file is still opened, close it */
    if (data != -1)
    {
        CLOSE(data);
    }
}

#endif /* OMITCASE1 */
