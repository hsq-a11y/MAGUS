/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__CWE839_negative_67a.c
Label Definition File: CWE124_Buffer_Underwrite__CWE839.label.xml
Template File: sources-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * Case0Source: negative Negative index value
 * Case1Source: Non-negative but less than 10
 * Sinks:
 *    Case1Sink: Ensure the array index is valid
 *    Case0Sink : Improperly check the array index by not checking the lower bound
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE124_Buffer_Underwrite__CWE839_negative_67_structType
{
    int structFirst;
} CWE124_Buffer_Underwrite__CWE839_negative_67_structType;

#ifndef OMITCASE0

/* case0 function declaration */
void CWE124_Buffer_Underwrite__CWE839_negative_67b_case0Sink(CWE124_Buffer_Underwrite__CWE839_negative_67_structType myStruct);

void CWE124_Buffer_Underwrite__CWE839_negative_67_case0()
{
    int data;
    CWE124_Buffer_Underwrite__CWE839_negative_67_structType myStruct;
    /* Initialize data */
    data = -1;
    /* NOTE: Use an invalid index */
    data = -5;
    myStruct.structFirst = data;
    CWE124_Buffer_Underwrite__CWE839_negative_67b_case0Sink(myStruct);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE124_Buffer_Underwrite__CWE839_negative_67b_case1V1Sink(CWE124_Buffer_Underwrite__CWE839_negative_67_structType myStruct);

static void case1V1()
{
    int data;
    CWE124_Buffer_Underwrite__CWE839_negative_67_structType myStruct;
    /* Initialize data */
    data = -1;
    /* ALT: Use a value greater than 0, but less than 10 to avoid attempting to
    * access an index of the array in the sink that is out-of-bounds */
    data = 7;
    myStruct.structFirst = data;
    CWE124_Buffer_Underwrite__CWE839_negative_67b_case1V1Sink(myStruct);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE124_Buffer_Underwrite__CWE839_negative_67b_case1V2Sink(CWE124_Buffer_Underwrite__CWE839_negative_67_structType myStruct);

static void case1V2()
{
    int data;
    CWE124_Buffer_Underwrite__CWE839_negative_67_structType myStruct;
    /* Initialize data */
    data = -1;
    /* NOTE: Use an invalid index */
    data = -5;
    myStruct.structFirst = data;
    CWE124_Buffer_Underwrite__CWE839_negative_67b_case1V2Sink(myStruct);
}

void CWE124_Buffer_Underwrite__CWE839_negative_67_case1()
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
    CWE124_Buffer_Underwrite__CWE839_negative_67_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE124_Buffer_Underwrite__CWE839_negative_67_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
