/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_snprintf_68b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE806.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Initialize data as a large string
 * Case1Source: Initialize data as a small string
 * Sink: snprintf
 *    Case0Sink : Copy data to string using snprintf
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define SNPRINTF _snprintf
#else
#define SNPRINTF snprintf
#endif

extern char * CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_snprintf_68_case0Data;
extern char * CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_snprintf_68_case1V1Data;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITCASE0

void CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_snprintf_68b_case0Sink()
{
    char * data = CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_snprintf_68_case0Data;
    {
        char dest[50] = "";
        /* NOTE: Possible buffer overflow if data is larger than dest */
        SNPRINTF(dest, strlen(data), "%s", data);
        printLine(data);
        free(data);
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_snprintf_68b_case1V1Sink()
{
    char * data = CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_snprintf_68_case1V1Data;
    {
        char dest[50] = "";
        /* NOTE: Possible buffer overflow if data is larger than dest */
        SNPRINTF(dest, strlen(data), "%s", data);
        printLine(data);
        free(data);
    }
}

#endif /* OMITCASE1 */
