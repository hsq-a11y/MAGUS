/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_memcpy_67a.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE806.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Initialize data as a large string
 * Case1Source: Initialize data as a small string
 * Sinks: memcpy
 *    Case0Sink : Copy data to string using memcpy
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_memcpy_67_structType
{
    char * structFirst;
} CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_memcpy_67_structType;

#ifndef OMITCASE0

/* case0 function declaration */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_memcpy_67b_case0Sink(CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_memcpy_67_structType myStruct);

void CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_memcpy_67_case0()
{
    char * data;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_memcpy_67_structType myStruct;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    /* NOTE: Initialize data as a large buffer that is larger than the small buffer used in the sink */
    memset(data, 'A', 100-1); /* fill with 'A's */
    data[100-1] = '\0'; /* null terminate */
    myStruct.structFirst = data;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_memcpy_67b_case0Sink(myStruct);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_memcpy_67b_case1V1Sink(CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_memcpy_67_structType myStruct);

static void case1V1()
{
    char * data;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_memcpy_67_structType myStruct;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    /* ALT: Initialize data as a small buffer that as small or smaller than the small buffer used in the sink */
    memset(data, 'A', 50-1); /* fill with 'A's */
    data[50-1] = '\0'; /* null terminate */
    myStruct.structFirst = data;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_memcpy_67b_case1V1Sink(myStruct);
}

void CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_memcpy_67_case1()
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
    CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_memcpy_67_case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
#ifndef OMITCASE0
    printLine("Calling case0()...");
    CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_memcpy_67_case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
