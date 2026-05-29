/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_02.c
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close.label.xml
Template File: source-sinks-02.tmpl.c
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * Case0Source:  Open a file using fopen()
 * Sinks:
 *    Case1Sink: Close the file using fclose()
 *    Case0Sink : Do not close file
 * Flow Variant: 02 Control flow: if(1) and if(0)
 *
 * */

#include "std_testcase.h"

#ifndef OMITCASE0

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_02_case0()
{
    FILE * data;
    data = NULL;
    /* NOTE: Open a file without closing it */
    data = fopen("Case0Source_fopen.txt", "w+");
    if(1)
    {
        /* NOTE: No attempt to close the file */
        ; /* empty statement needed for some flow variants */
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V21() - use case0source and case1sink by changing 1 to 0 */
static void case1V21()
{
    FILE * data;
    data = NULL;
    /* NOTE: Open a file without closing it */
    data = fopen("Case0Source_fopen.txt", "w+");
    if(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: If the file is still opened, close it */
        if (data != NULL)
        {
            fclose(data);
        }
    }
}

/* case1V22() - use case0source and case1sink by reversing statements in if  */
static void case1V22()
{
    FILE * data;
    data = NULL;
    /* NOTE: Open a file without closing it */
    data = fopen("Case0Source_fopen.txt", "w+");
    if(1)
    {
        /* ALT: If the file is still opened, close it */
        if (data != NULL)
        {
            fclose(data);
        }
    }
}

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_02_case1()
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
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_02_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_02_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
