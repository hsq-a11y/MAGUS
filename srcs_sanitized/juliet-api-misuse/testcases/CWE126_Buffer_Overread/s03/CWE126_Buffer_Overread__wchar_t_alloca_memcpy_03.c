/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__wchar_t_alloca_memcpy_03.c
Label Definition File: CWE126_Buffer_Overread.stack.label.xml
Template File: sources-sink-03.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * Case0Source:  Set data pointer to a small buffer
 * Case1Source: Set data pointer to a large buffer
 * Sink: memcpy
 *    Case0Sink : Copy data to string using memcpy
 * Flow Variant: 03 Control flow: if(5==5) and if(5!=5)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

void CWE126_Buffer_Overread__wchar_t_alloca_memcpy_03_case0()
{
    wchar_t * data;
    wchar_t * dataCase0Buffer = (wchar_t *)ALLOCA(50*sizeof(wchar_t));
    wchar_t * dataCase1Buffer = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
    wmemset(dataCase0Buffer, L'A', 50-1); /* fill with 'A's */
    dataCase0Buffer[50-1] = L'\0'; /* null terminate */
    wmemset(dataCase1Buffer, L'A', 100-1); /* fill with 'A's */
    dataCase1Buffer[100-1] = L'\0'; /* null terminate */
    if(5==5)
    {
        /* NOTE: Set data pointer to a small buffer */
        data = dataCase0Buffer;
    }
    {
        wchar_t dest[100];
        wmemset(dest, L'C', 100-1);
        dest[100-1] = L'\0'; /* null terminate */
        /* NOTE: using memcpy with the length of the dest where data
         * could be smaller than dest causing buffer overread */
        memcpy(dest, data, wcslen(dest)*sizeof(wchar_t));
        dest[100-1] = L'\0';
        printWLine(dest);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V11() - use case1source and case0sink by changing the 5==5 to 5!=5 */
static void case1V11()
{
    wchar_t * data;
    wchar_t * dataCase0Buffer = (wchar_t *)ALLOCA(50*sizeof(wchar_t));
    wchar_t * dataCase1Buffer = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
    wmemset(dataCase0Buffer, L'A', 50-1); /* fill with 'A's */
    dataCase0Buffer[50-1] = L'\0'; /* null terminate */
    wmemset(dataCase1Buffer, L'A', 100-1); /* fill with 'A's */
    dataCase1Buffer[100-1] = L'\0'; /* null terminate */
    if(5!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: Set data pointer to a large buffer */
        data = dataCase1Buffer;
    }
    {
        wchar_t dest[100];
        wmemset(dest, L'C', 100-1);
        dest[100-1] = L'\0'; /* null terminate */
        /* NOTE: using memcpy with the length of the dest where data
         * could be smaller than dest causing buffer overread */
        memcpy(dest, data, wcslen(dest)*sizeof(wchar_t));
        dest[100-1] = L'\0';
        printWLine(dest);
    }
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the if statement */
static void case1V12()
{
    wchar_t * data;
    wchar_t * dataCase0Buffer = (wchar_t *)ALLOCA(50*sizeof(wchar_t));
    wchar_t * dataCase1Buffer = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
    wmemset(dataCase0Buffer, L'A', 50-1); /* fill with 'A's */
    dataCase0Buffer[50-1] = L'\0'; /* null terminate */
    wmemset(dataCase1Buffer, L'A', 100-1); /* fill with 'A's */
    dataCase1Buffer[100-1] = L'\0'; /* null terminate */
    if(5==5)
    {
        /* ALT: Set data pointer to a large buffer */
        data = dataCase1Buffer;
    }
    {
        wchar_t dest[100];
        wmemset(dest, L'C', 100-1);
        dest[100-1] = L'\0'; /* null terminate */
        /* NOTE: using memcpy with the length of the dest where data
         * could be smaller than dest causing buffer overread */
        memcpy(dest, data, wcslen(dest)*sizeof(wchar_t));
        dest[100-1] = L'\0';
        printWLine(dest);
    }
}

void CWE126_Buffer_Overread__wchar_t_alloca_memcpy_03_case1()
{
    case1V11();
    case1V12();
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
    CWE126_Buffer_Overread__wchar_t_alloca_memcpy_03_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE126_Buffer_Overread__wchar_t_alloca_memcpy_03_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
