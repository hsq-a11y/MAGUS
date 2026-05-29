/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__malloc_wchar_t_cpy_67a.c
Label Definition File: CWE127_Buffer_Underread__malloc.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * Case0Source:  Set data pointer to before the allocated memory buffer
 * Case1Source: Set data pointer to the allocated memory buffer
 * Sinks: cpy
 *    Case0Sink : Copy data to string using wcscpy
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE127_Buffer_Underread__malloc_wchar_t_cpy_67_structType
{
    wchar_t * structFirst;
} CWE127_Buffer_Underread__malloc_wchar_t_cpy_67_structType;

#ifndef OMITCASE0

/* case0 function declaration */
void CWE127_Buffer_Underread__malloc_wchar_t_cpy_67b_case0Sink(CWE127_Buffer_Underread__malloc_wchar_t_cpy_67_structType myStruct);

void CWE127_Buffer_Underread__malloc_wchar_t_cpy_67_case0()
{
    wchar_t * data;
    CWE127_Buffer_Underread__malloc_wchar_t_cpy_67_structType myStruct;
    data = NULL;
    {
        wchar_t * dataBuffer = (wchar_t *)malloc(100*sizeof(wchar_t));
        if (dataBuffer == NULL) {exit(-1);}
        wmemset(dataBuffer, L'A', 100-1);
        dataBuffer[100-1] = L'\0';
        /* NOTE: Set data pointer to before the allocated memory buffer */
        data = dataBuffer - 8;
    }
    myStruct.structFirst = data;
    CWE127_Buffer_Underread__malloc_wchar_t_cpy_67b_case0Sink(myStruct);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE127_Buffer_Underread__malloc_wchar_t_cpy_67b_case1V1Sink(CWE127_Buffer_Underread__malloc_wchar_t_cpy_67_structType myStruct);

static void case1V1()
{
    wchar_t * data;
    CWE127_Buffer_Underread__malloc_wchar_t_cpy_67_structType myStruct;
    data = NULL;
    {
        wchar_t * dataBuffer = (wchar_t *)malloc(100*sizeof(wchar_t));
        if (dataBuffer == NULL) {exit(-1);}
        wmemset(dataBuffer, L'A', 100-1);
        dataBuffer[100-1] = L'\0';
        /* ALT: Set data pointer to the allocated memory buffer */
        data = dataBuffer;
    }
    myStruct.structFirst = data;
    CWE127_Buffer_Underread__malloc_wchar_t_cpy_67b_case1V1Sink(myStruct);
}

void CWE127_Buffer_Underread__malloc_wchar_t_cpy_67_case1()
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
    CWE127_Buffer_Underread__malloc_wchar_t_cpy_67_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE127_Buffer_Underread__malloc_wchar_t_cpy_67_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
