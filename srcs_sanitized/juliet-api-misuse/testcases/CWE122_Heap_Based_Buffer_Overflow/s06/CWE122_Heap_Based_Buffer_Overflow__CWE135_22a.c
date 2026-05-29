/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__CWE135_22a.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__CWE135.label.xml
Template File: sources-sinks-22a.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Void pointer to a wchar_t array
 * Case1Source: Void pointer to a char array
 * Sinks:
 *    Case1Sink: Allocate memory using wcslen() and copy data
 *    Case0Sink : Allocate memory using strlen() and copy data
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the sink function */
int CWE122_Heap_Based_Buffer_Overflow__CWE135_22_case0Global = 0;

void CWE122_Heap_Based_Buffer_Overflow__CWE135_22_case0Sink(void * data);

void CWE122_Heap_Based_Buffer_Overflow__CWE135_22_case0()
{
    void * data;
    data = NULL;
    {
        wchar_t * dataCase0Buffer = (wchar_t *)malloc(50*sizeof(wchar_t));
        if (dataCase0Buffer == NULL) {exit(-1);}
        wmemset(dataCase0Buffer, L'A', 50-1);
        dataCase0Buffer[50-1] = L'\0';
        /* NOTE: Set data to point to a wide string */
        data = (void *)dataCase0Buffer;
    }
    CWE122_Heap_Based_Buffer_Overflow__CWE135_22_case0Global = 1; /* true */
    CWE122_Heap_Based_Buffer_Overflow__CWE135_22_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the sink functions. */
int CWE122_Heap_Based_Buffer_Overflow__CWE135_22_case1V21Global = 0;
int CWE122_Heap_Based_Buffer_Overflow__CWE135_22_case1V22Global = 0;
int CWE122_Heap_Based_Buffer_Overflow__CWE135_22_case1V1Global = 0;

/* case1V21() - use case0source and case1sink by setting the static variable to false instead of true */
void CWE122_Heap_Based_Buffer_Overflow__CWE135_22_case1V21Sink(void * data);

static void case1V21()
{
    void * data;
    data = NULL;
    {
        wchar_t * dataCase0Buffer = (wchar_t *)malloc(50*sizeof(wchar_t));
        if (dataCase0Buffer == NULL) {exit(-1);}
        wmemset(dataCase0Buffer, L'A', 50-1);
        dataCase0Buffer[50-1] = L'\0';
        /* NOTE: Set data to point to a wide string */
        data = (void *)dataCase0Buffer;
    }
    CWE122_Heap_Based_Buffer_Overflow__CWE135_22_case1V21Global = 0; /* false */
    CWE122_Heap_Based_Buffer_Overflow__CWE135_22_case1V21Sink(data);
}

/* case1V22() - use case0source and case1sink by reversing the blocks in the if in the sink function */
void CWE122_Heap_Based_Buffer_Overflow__CWE135_22_case1V22Sink(void * data);

static void case1V22()
{
    void * data;
    data = NULL;
    {
        wchar_t * dataCase0Buffer = (wchar_t *)malloc(50*sizeof(wchar_t));
        if (dataCase0Buffer == NULL) {exit(-1);}
        wmemset(dataCase0Buffer, L'A', 50-1);
        dataCase0Buffer[50-1] = L'\0';
        /* NOTE: Set data to point to a wide string */
        data = (void *)dataCase0Buffer;
    }
    CWE122_Heap_Based_Buffer_Overflow__CWE135_22_case1V22Global = 1; /* true */
    CWE122_Heap_Based_Buffer_Overflow__CWE135_22_case1V22Sink(data);
}

/* case1V1() - use case1source and case0sink */
void CWE122_Heap_Based_Buffer_Overflow__CWE135_22_case1V1Sink(void * data);

static void case1V1()
{
    void * data;
    data = NULL;
    {
        char * dataCase1Buffer = (char *)malloc(50*sizeof(char));
        if (dataCase1Buffer == NULL) {exit(-1);}
        memset(dataCase1Buffer, 'A', 50-1);
        dataCase1Buffer[50-1] = '\0';
        /* ALT: Set data to point to a char string */
        data = (void *)dataCase1Buffer;
    }
    CWE122_Heap_Based_Buffer_Overflow__CWE135_22_case1V1Global = 1; /* true */
    CWE122_Heap_Based_Buffer_Overflow__CWE135_22_case1V1Sink(data);
}

void CWE122_Heap_Based_Buffer_Overflow__CWE135_22_case1()
{
    case1V21();
    case1V22();
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
    CWE122_Heap_Based_Buffer_Overflow__CWE135_22_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE122_Heap_Based_Buffer_Overflow__CWE135_22_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
