/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_54b.c
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close.label.xml
Template File: source-sinks-54b.tmpl.c
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * Case0Source:  Open a file using open()
 * Sinks:
 *    Case1Sink: Close the file using close()
 *    Case0Sink : Do not close file
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
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
void CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_54c_case0Sink(int data);

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_54b_case0Sink(int data)
{
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_54c_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_54c_case1V2Sink(int data);

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_54b_case1V2Sink(int data)
{
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_54c_case1V2Sink(data);
}

#endif /* OMITCASE1 */
