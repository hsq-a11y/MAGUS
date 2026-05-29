/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__CWE135_61a.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__CWE135.label.xml
Template File: sources-sinks-61a.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Void pointer to a wchar_t array
 * Case1Source: Void pointer to a char array
 * Sinks:
 *    Case1Sink: Allocate memory using wcslen() and copy data
 *    Case0Sink : Allocate memory using strlen() and copy data
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

/* case0 function declaration */
void * CWE122_Heap_Based_Buffer_Overflow__CWE135_61b_case0Source(void * data);

void CWE122_Heap_Based_Buffer_Overflow__CWE135_61_case0()
{
    void * data;
    data = NULL;
    data = CWE122_Heap_Based_Buffer_Overflow__CWE135_61b_case0Source(data);
    {
        /* NOTE: treating pointer as a char* when it may point to a wide string */
        size_t dataLen = strlen((char *)data);
        void * dest = (void *)calloc(dataLen+1, sizeof(wchar_t));
        if (dest == NULL) {exit(-1);}
        (void)wcscpy(dest, data);
        printLine((char *)dest);
        free(dest);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void * CWE122_Heap_Based_Buffer_Overflow__CWE135_61b_case1V1Source(void * data);

static void case1V1()
{
    void * data;
    data = NULL;
    data = CWE122_Heap_Based_Buffer_Overflow__CWE135_61b_case1V1Source(data);
    {
        /* NOTE: treating pointer as a char* when it may point to a wide string */
        size_t dataLen = strlen((char *)data);
        void * dest = (void *)calloc(dataLen+1, 1);
        if (dest == NULL) {exit(-1);}
        (void)strcpy(dest, data);
        printLine((char *)dest);
        free(dest);
    }
}

/* case1V2 uses the Case0Source with the Case1Sink */
void * CWE122_Heap_Based_Buffer_Overflow__CWE135_61b_case1V2Source(void * data);

static void case1V2()
{
    void * data;
    data = NULL;
    data = CWE122_Heap_Based_Buffer_Overflow__CWE135_61b_case1V2Source(data);
    {
        /* ALT: treating pointer like a wchar_t*  */
        size_t dataLen = wcslen((wchar_t *)data);
        void * dest = (void *)calloc(dataLen+1, sizeof(wchar_t));
        if (dest == NULL) {exit(-1);}
        (void)wcscpy(dest, data);
        printWLine((wchar_t *)dest);
        free(dest);
    }
}

void CWE122_Heap_Based_Buffer_Overflow__CWE135_61_case1()
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
    CWE122_Heap_Based_Buffer_Overflow__CWE135_61_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE122_Heap_Based_Buffer_Overflow__CWE135_61_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
