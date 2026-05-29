/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__wchar_t_alloca_memcpy_67a.c
Label Definition File: CWE126_Buffer_Overread.stack.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * Case0Source:  Set data pointer to a small buffer
 * Case1Source: Set data pointer to a large buffer
 * Sinks: memcpy
 *    Case0Sink : Copy data to string using memcpy
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE126_Buffer_Overread__wchar_t_alloca_memcpy_67_structType
{
    wchar_t * structFirst;
} CWE126_Buffer_Overread__wchar_t_alloca_memcpy_67_structType;

#ifndef OMITCASE0

/* case0 function declaration */
void CWE126_Buffer_Overread__wchar_t_alloca_memcpy_67b_case0Sink(CWE126_Buffer_Overread__wchar_t_alloca_memcpy_67_structType myStruct);

void CWE126_Buffer_Overread__wchar_t_alloca_memcpy_67_case0()
{
    wchar_t * data;
    CWE126_Buffer_Overread__wchar_t_alloca_memcpy_67_structType myStruct;
    wchar_t * dataCase0Buffer = (wchar_t *)ALLOCA(50*sizeof(wchar_t));
    wchar_t * dataCase1Buffer = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
    wmemset(dataCase0Buffer, L'A', 50-1); /* fill with 'A's */
    dataCase0Buffer[50-1] = L'\0'; /* null terminate */
    wmemset(dataCase1Buffer, L'A', 100-1); /* fill with 'A's */
    dataCase1Buffer[100-1] = L'\0'; /* null terminate */
    /* NOTE: Set data pointer to a small buffer */
    data = dataCase0Buffer;
    myStruct.structFirst = data;
    CWE126_Buffer_Overread__wchar_t_alloca_memcpy_67b_case0Sink(myStruct);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE126_Buffer_Overread__wchar_t_alloca_memcpy_67b_case1V1Sink(CWE126_Buffer_Overread__wchar_t_alloca_memcpy_67_structType myStruct);

static void case1V1()
{
    wchar_t * data;
    CWE126_Buffer_Overread__wchar_t_alloca_memcpy_67_structType myStruct;
    wchar_t * dataCase0Buffer = (wchar_t *)ALLOCA(50*sizeof(wchar_t));
    wchar_t * dataCase1Buffer = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
    wmemset(dataCase0Buffer, L'A', 50-1); /* fill with 'A's */
    dataCase0Buffer[50-1] = L'\0'; /* null terminate */
    wmemset(dataCase1Buffer, L'A', 100-1); /* fill with 'A's */
    dataCase1Buffer[100-1] = L'\0'; /* null terminate */
    /* ALT: Set data pointer to a large buffer */
    data = dataCase1Buffer;
    myStruct.structFirst = data;
    CWE126_Buffer_Overread__wchar_t_alloca_memcpy_67b_case1V1Sink(myStruct);
}

void CWE126_Buffer_Overread__wchar_t_alloca_memcpy_67_case1()
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
    CWE126_Buffer_Overread__wchar_t_alloca_memcpy_67_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE126_Buffer_Overread__wchar_t_alloca_memcpy_67_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
