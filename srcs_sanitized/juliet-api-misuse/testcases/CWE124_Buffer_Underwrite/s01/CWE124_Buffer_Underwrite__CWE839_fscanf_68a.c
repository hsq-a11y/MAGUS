/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__CWE839_fscanf_68a.c
Label Definition File: CWE124_Buffer_Underwrite__CWE839.label.xml
Template File: sources-sinks-68a.tmpl.c
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * Case0Source: fscanf Read data from the console using fscanf()
 * Case1Source: Non-negative but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking the lower bound
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

int CWE124_Buffer_Underwrite__CWE839_fscanf_68_case0Data;
int CWE124_Buffer_Underwrite__CWE839_fscanf_68_case1V1Data;
int CWE124_Buffer_Underwrite__CWE839_fscanf_68_case1V2Data;

#ifndef OMITCASE0

/* case0 function declaration */
void CWE124_Buffer_Underwrite__CWE839_fscanf_68b_case0Sink();

void CWE124_Buffer_Underwrite__CWE839_fscanf_68_case0()
{
    int data;
    /* Initialize data */
    data = -1;
    /* NOTE: Read data from the console using fscanf() */
    fscanf(stdin, "%d", &data);
    CWE124_Buffer_Underwrite__CWE839_fscanf_68_case0Data = data;
    CWE124_Buffer_Underwrite__CWE839_fscanf_68b_case0Sink();
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1 function declarations */
void CWE124_Buffer_Underwrite__CWE839_fscanf_68b_case1V1Sink();
void CWE124_Buffer_Underwrite__CWE839_fscanf_68b_case1V2Sink();

/* case1V1 uses the Case1Source with the Case0Sink */
static void case1V1()
{
    int data;
    /* Initialize data */
    data = -1;
    /* ALT: Use a value greater than 0, but less than 10 to avoid attempting to
    * access an index of the array in the sink that is out-of-bounds */
    data = 7;
    CWE124_Buffer_Underwrite__CWE839_fscanf_68_case1V1Data = data;
    CWE124_Buffer_Underwrite__CWE839_fscanf_68b_case1V1Sink();
}

/* case1V2 uses the Case0Source with the Case1Sink */
static void case1V2()
{
    int data;
    /* Initialize data */
    data = -1;
    /* NOTE: Read data from the console using fscanf() */
    fscanf(stdin, "%d", &data);
    CWE124_Buffer_Underwrite__CWE839_fscanf_68_case1V2Data = data;
    CWE124_Buffer_Underwrite__CWE839_fscanf_68b_case1V2Sink();
}

void CWE124_Buffer_Underwrite__CWE839_fscanf_68_case1()
{
    case1V1();
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
    CWE124_Buffer_Underwrite__CWE839_fscanf_68_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE124_Buffer_Underwrite__CWE839_fscanf_68_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
