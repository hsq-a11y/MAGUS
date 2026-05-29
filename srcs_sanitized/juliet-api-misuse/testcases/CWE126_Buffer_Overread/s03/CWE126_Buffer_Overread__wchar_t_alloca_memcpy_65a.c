/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__wchar_t_alloca_memcpy_65a.c
Label Definition File: CWE126_Buffer_Overread.stack.label.xml
Template File: sources-sink-65a.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * Case0Source:  Set data pointer to a small buffer
 * Case1Source: Set data pointer to a large buffer
 * Sinks: memcpy
 *    Case0Sink : Copy data to string using memcpy
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

/* case0 function declaration */
void CWE126_Buffer_Overread__wchar_t_alloca_memcpy_65b_case0Sink(wchar_t * data);

void CWE126_Buffer_Overread__wchar_t_alloca_memcpy_65_case0()
{
    wchar_t * data;
    /* define a function pointer */
    void (*funcPtr) (wchar_t *) = CWE126_Buffer_Overread__wchar_t_alloca_memcpy_65b_case0Sink;
    wchar_t * dataCase0Buffer = (wchar_t *)ALLOCA(50*sizeof(wchar_t));
    wchar_t * dataCase1Buffer = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
    wmemset(dataCase0Buffer, L'A', 50-1); /* fill with 'A's */
    dataCase0Buffer[50-1] = L'\0'; /* null terminate */
    wmemset(dataCase1Buffer, L'A', 100-1); /* fill with 'A's */
    dataCase1Buffer[100-1] = L'\0'; /* null terminate */
    /* NOTE: Set data pointer to a small buffer */
    data = dataCase0Buffer;
    /* use the function pointer */
    funcPtr(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE126_Buffer_Overread__wchar_t_alloca_memcpy_65b_case1V1Sink(wchar_t * data);

static void case1V1()
{
    wchar_t * data;
    void (*funcPtr) (wchar_t *) = CWE126_Buffer_Overread__wchar_t_alloca_memcpy_65b_case1V1Sink;
    wchar_t * dataCase0Buffer = (wchar_t *)ALLOCA(50*sizeof(wchar_t));
    wchar_t * dataCase1Buffer = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
    wmemset(dataCase0Buffer, L'A', 50-1); /* fill with 'A's */
    dataCase0Buffer[50-1] = L'\0'; /* null terminate */
    wmemset(dataCase1Buffer, L'A', 100-1); /* fill with 'A's */
    dataCase1Buffer[100-1] = L'\0'; /* null terminate */
    /* ALT: Set data pointer to a large buffer */
    data = dataCase1Buffer;
    funcPtr(data);
}

void CWE126_Buffer_Overread__wchar_t_alloca_memcpy_65_case1()
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
    CWE126_Buffer_Overread__wchar_t_alloca_memcpy_65_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE126_Buffer_Overread__wchar_t_alloca_memcpy_65_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
