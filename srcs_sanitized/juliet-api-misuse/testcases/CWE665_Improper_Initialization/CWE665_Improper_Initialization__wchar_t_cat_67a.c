/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__wchar_t_cat_67a.c
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * Case0Source:  Do not initialize data properly
 * Case1Source: Initialize data
 * Sinks: cat
 *    Case0Sink : Copy string to data using wcscat
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE665_Improper_Initialization__wchar_t_cat_67_structType
{
    wchar_t * structFirst;
} CWE665_Improper_Initialization__wchar_t_cat_67_structType;

#ifndef OMITCASE0

/* case0 function declaration */
void CWE665_Improper_Initialization__wchar_t_cat_67b_case0Sink(CWE665_Improper_Initialization__wchar_t_cat_67_structType myStruct);

void CWE665_Improper_Initialization__wchar_t_cat_67_case0()
{
    wchar_t * data;
    CWE665_Improper_Initialization__wchar_t_cat_67_structType myStruct;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    /* NOTE: Do not initialize data */
    ; /* empty statement needed for some flow variants */
    myStruct.structFirst = data;
    CWE665_Improper_Initialization__wchar_t_cat_67b_case0Sink(myStruct);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE665_Improper_Initialization__wchar_t_cat_67b_case1V1Sink(CWE665_Improper_Initialization__wchar_t_cat_67_structType myStruct);

static void case1V1()
{
    wchar_t * data;
    CWE665_Improper_Initialization__wchar_t_cat_67_structType myStruct;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    /* ALT: Properly initialize data */
    data[0] = L'\0'; /* null terminate */
    myStruct.structFirst = data;
    CWE665_Improper_Initialization__wchar_t_cat_67b_case1V1Sink(myStruct);
}

void CWE665_Improper_Initialization__wchar_t_cat_67_case1()
{
    case1V1();
}

#endif /* OMITCASE1 */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITCASE1
    printLine("Calling case1()...");
    CWE665_Improper_Initialization__wchar_t_cat_67_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE665_Improper_Initialization__wchar_t_cat_67_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
