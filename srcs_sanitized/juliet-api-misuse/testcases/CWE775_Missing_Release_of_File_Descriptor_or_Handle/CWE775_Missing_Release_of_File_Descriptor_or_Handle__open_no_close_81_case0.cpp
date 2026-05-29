/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_81_case0.cpp
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close.label.xml
Template File: source-sinks-81_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * Case0Source:  Open a file using open()
 * Sinks:
 *    Case1Sink: Close the file using close()
 *    Case0Sink : Do not close file
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_81.h"

namespace CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_81
{

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_81_case0::action(int data) const
{
    /* NOTE: No attempt to close the file */
    ; /* empty statement needed for some flow variants */
}

}
#endif /* OMITCASE0 */
