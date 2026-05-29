/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__fopen_67a.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource.label.xml
Template File: sources-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * Case0Source: fopen Open and close a file using fopen() and flose()
 * Case1Source: Open a file using fopen()
 * Sinks:
 *    Case1Sink: Do nothing
 *    Case0Sink : Close the file
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE675_Duplicate_Operations_on_Resource__fopen_67_structType
{
    FILE * structFirst;
} CWE675_Duplicate_Operations_on_Resource__fopen_67_structType;

#ifndef OMITCASE0

/* case0 function declaration */
void CWE675_Duplicate_Operations_on_Resource__fopen_67b_case0Sink(CWE675_Duplicate_Operations_on_Resource__fopen_67_structType myStruct);

void CWE675_Duplicate_Operations_on_Resource__fopen_67_case0()
{
    FILE * data;
    CWE675_Duplicate_Operations_on_Resource__fopen_67_structType myStruct;
    data = NULL; /* Initialize data */
    data = fopen("Case0Source_fopen.txt", "w+");
    /* NOTE: Close the file in the source */
    fclose(data);
    myStruct.structFirst = data;
    CWE675_Duplicate_Operations_on_Resource__fopen_67b_case0Sink(myStruct);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE675_Duplicate_Operations_on_Resource__fopen_67b_case1V1Sink(CWE675_Duplicate_Operations_on_Resource__fopen_67_structType myStruct);

static void case1V1()
{
    FILE * data;
    CWE675_Duplicate_Operations_on_Resource__fopen_67_structType myStruct;
    data = NULL; /* Initialize data */
    /* ALT: Open, but do not close the file in the source */
    data = fopen("Case1Source_fopen.txt", "w+");
    myStruct.structFirst = data;
    CWE675_Duplicate_Operations_on_Resource__fopen_67b_case1V1Sink(myStruct);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE675_Duplicate_Operations_on_Resource__fopen_67b_case1V2Sink(CWE675_Duplicate_Operations_on_Resource__fopen_67_structType myStruct);

static void case1V2()
{
    FILE * data;
    CWE675_Duplicate_Operations_on_Resource__fopen_67_structType myStruct;
    data = NULL; /* Initialize data */
    data = fopen("Case0Source_fopen.txt", "w+");
    /* NOTE: Close the file in the source */
    fclose(data);
    myStruct.structFirst = data;
    CWE675_Duplicate_Operations_on_Resource__fopen_67b_case1V2Sink(myStruct);
}

void CWE675_Duplicate_Operations_on_Resource__fopen_67_case1()
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
    CWE675_Duplicate_Operations_on_Resource__fopen_67_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE675_Duplicate_Operations_on_Resource__fopen_67_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
