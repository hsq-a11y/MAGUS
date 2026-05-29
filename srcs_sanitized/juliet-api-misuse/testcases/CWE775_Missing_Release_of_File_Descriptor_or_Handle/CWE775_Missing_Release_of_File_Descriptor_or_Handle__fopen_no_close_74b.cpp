/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_74b.cpp
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close.label.xml
Template File: source-sinks-74b.tmpl.cpp
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * Case0Source:  Open a file using fopen()
 * Sinks:
 *    Case1Sink: Close the file using fclose()
 *    Case0Sink : Do not close file
 * Flow Variant: 74 Data flow: data passed in a map from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <map>

using namespace std;

namespace CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_74
{

#ifndef OMITCASE0

void case0Sink(map<int, FILE *> dataMap)
{
    /* copy data out of dataMap */
    FILE * data = dataMap[2];
    /* NOTE: No attempt to close the file */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Sink(map<int, FILE *> dataMap)
{
    FILE * data = dataMap[2];
    /* ALT: If the file is still opened, close it */
    if (data != NULL)
    {
        fclose(data);
    }
}

#endif /* OMITCASE1 */

} /* close namespace */
