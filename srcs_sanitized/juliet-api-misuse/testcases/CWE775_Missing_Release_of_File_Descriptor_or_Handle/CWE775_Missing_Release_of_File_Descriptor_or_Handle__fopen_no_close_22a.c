/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_22a.c
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close.label.xml
Template File: source-sinks-22a.tmpl.c
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * Case0Source:  Open a file using fopen()
 * Sinks:
 *    Case1Sink: Close the file using fclose()
 *    Case0Sink : Do not close file
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the sink function */
int CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_22_case0Global = 0;

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_22_case0Sink(FILE * data);

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_22_case0()
{
    FILE * data;
    data = NULL;
    /* NOTE: Open a file without closing it */
    data = fopen("Case0Source_fopen.txt", "w+");
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_22_case0Global = 1; /* true */
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_22_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the sink functions. */
int CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_22_case1V21Global = 0;
int CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_22_case1V22Global = 0;

/* case1V21() - use case0source and case1sink by setting the static variable to false instead of true */
void CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_22_case1V21Sink(FILE * data);

static void case1V21()
{
    FILE * data;
    data = NULL;
    /* NOTE: Open a file without closing it */
    data = fopen("Case0Source_fopen.txt", "w+");
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_22_case1V21Global = 0; /* false */
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_22_case1V21Sink(data);
}

/* case1V22() - use case0source and case1sink by reversing the blocks in the if in the sink function */
void CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_22_case1V22Sink(FILE * data);

static void case1V22()
{
    FILE * data;
    data = NULL;
    /* NOTE: Open a file without closing it */
    data = fopen("Case0Source_fopen.txt", "w+");
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_22_case1V22Global = 1; /* true */
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_22_case1V22Sink(data);
}

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_22_case1()
{
    case1V21();
    case1V22();
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
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_22_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_22_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
