/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__CWE135_63b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__CWE135.label.xml
Template File: sources-sinks-63b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Void pointer to a wchar_t array
 * Case1Source: Void pointer to a char array
 * Sinks:
 *    Case1Sink: Allocate memory using wcslen() and copy data
 *    Case0Sink : Allocate memory using strlen() and copy data
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

void CWE122_Heap_Based_Buffer_Overflow__CWE135_63b_case0Sink(void * * dataPtr)
{
    void * data = *dataPtr;
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
void CWE122_Heap_Based_Buffer_Overflow__CWE135_63b_case1V1Sink(void * * dataPtr)
{
    void * data = *dataPtr;
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
void CWE122_Heap_Based_Buffer_Overflow__CWE135_63b_case1V2Sink(void * * dataPtr)
{
    void * data = *dataPtr;
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

#endif /* OMITCASE1 */
