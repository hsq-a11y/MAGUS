/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__CWE135_16.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__CWE135.label.xml
Template File: sources-sinks-16.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Void pointer to a wchar_t array
 * Case1Source: Void pointer to a char array
 * Sinks:
 *    Case1Sink: Allocate memory using wcslen() and copy data
 *    Case0Sink : Allocate memory using strlen() and copy data
 * Flow Variant: 16 Control flow: while(1)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

void CWE122_Heap_Based_Buffer_Overflow__CWE135_16_case0()
{
    void * data;
    data = NULL;
    while(1)
    {
        {
            wchar_t * dataCase0Buffer = (wchar_t *)malloc(50*sizeof(wchar_t));
            if (dataCase0Buffer == NULL) {exit(-1);}
            wmemset(dataCase0Buffer, L'A', 50-1);
            dataCase0Buffer[50-1] = L'\0';
            /* NOTE: Set data to point to a wide string */
            data = (void *)dataCase0Buffer;
        }
        break;
    }
    while(1)
    {
        {
            /* NOTE: treating pointer as a char* when it may point to a wide string */
            size_t dataLen = strlen((char *)data);
            void * dest = (void *)calloc(dataLen+1, sizeof(wchar_t));
            if (dest == NULL) {exit(-1);}
            (void)wcscpy(dest, data);
            printLine((char *)dest);
            free(dest);
        }
        break;
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2() - use case0source and case1sink by changing the sinks in the second while statement */
static void case1V2()
{
    void * data;
    data = NULL;
    while(1)
    {
        {
            wchar_t * dataCase0Buffer = (wchar_t *)malloc(50*sizeof(wchar_t));
            if (dataCase0Buffer == NULL) {exit(-1);}
            wmemset(dataCase0Buffer, L'A', 50-1);
            dataCase0Buffer[50-1] = L'\0';
            /* NOTE: Set data to point to a wide string */
            data = (void *)dataCase0Buffer;
        }
        break;
    }
    while(1)
    {
        {
            /* ALT: treating pointer like a wchar_t*  */
            size_t dataLen = wcslen((wchar_t *)data);
            void * dest = (void *)calloc(dataLen+1, sizeof(wchar_t));
            if (dest == NULL) {exit(-1);}
            (void)wcscpy(dest, data);
            printWLine((wchar_t *)dest);
            free(dest);
        }
        break;
    }
}

/* case1V1() - use case1source and case0sink by changing the sources in the first while statement */
static void case1V1()
{
    void * data;
    data = NULL;
    while(1)
    {
        {
            char * dataCase1Buffer = (char *)malloc(50*sizeof(char));
            if (dataCase1Buffer == NULL) {exit(-1);}
            memset(dataCase1Buffer, 'A', 50-1);
            dataCase1Buffer[50-1] = '\0';
            /* ALT: Set data to point to a char string */
            data = (void *)dataCase1Buffer;
        }
        break;
    }
    while(1)
    {
        {
            /* NOTE: treating pointer as a char* when it may point to a wide string */
            size_t dataLen = strlen((char *)data);
            void * dest = (void *)calloc(dataLen+1, 1);
            if (dest == NULL) {exit(-1);}
            (void)strcpy(dest, data);
            printLine((char *)dest);
            free(dest);
        }
        break;
    }
}

void CWE122_Heap_Based_Buffer_Overflow__CWE135_16_case1()
{
    case1V2();
    case1V1();
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
    CWE122_Heap_Based_Buffer_Overflow__CWE135_16_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE122_Heap_Based_Buffer_Overflow__CWE135_16_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
