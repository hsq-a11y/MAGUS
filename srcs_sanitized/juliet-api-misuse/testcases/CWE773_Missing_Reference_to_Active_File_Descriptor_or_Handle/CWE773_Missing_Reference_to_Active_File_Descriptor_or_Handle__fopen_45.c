/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_45.c
Label Definition File: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen.label.xml
Template File: source-sinks-45.tmpl.c
*/
/*
 * @description
 * CWE: 773 Missing Reference to Active File Descriptor or Handle
 * Case0Source:  Create a file handle using fopen()
 * Sinks:
 *    Case1Sink: Close the file handle before reusing it
 *    Case0Sink : Reassign the file handle before closing it
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

static FILE * CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_45_case0Data;
static FILE * CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_45_case1V2Data;

#ifndef OMITCASE0

static void case0Sink()
{
    FILE * data = CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_45_case0Data;
    /* NOTE: Point data to another file handle without closing the handle from the source */
    data = fopen("Case0Sink_fopen.txt", "w+");
    /* avoid incidental for not closing the file handle */
    if (data != NULL)
    {
        fclose(data);
    }
}

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_45_case0()
{
    FILE * data;
    data = NULL;
    /* NOTE: Create a file handle using fopen() that may not be closed properly */
    data = fopen("Case0Source_fopen.txt", "w+");
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_45_case0Data = data;
    case0Sink();
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2() uses the Case0Source with the Case1Sink */
static void case1V2Sink()
{
    FILE * data = CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_45_case1V2Data;
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

static void case1V2()
{
    FILE * data;
    data = NULL;
    /* NOTE: Create a file handle using fopen() that may not be closed properly */
    data = fopen("Case0Source_fopen.txt", "w+");
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_45_case1V2Data = data;
    case1V2Sink();
}

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_45_case1()
{
    case1V2();
}

#endif /* OMITCASE1 */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */
#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITCASE1
    printLine("Calling case1()...");
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_45_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_45_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
