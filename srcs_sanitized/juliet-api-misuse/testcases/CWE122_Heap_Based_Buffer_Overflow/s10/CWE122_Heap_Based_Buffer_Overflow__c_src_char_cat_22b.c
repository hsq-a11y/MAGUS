/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_src_char_cat_22b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_src.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Initialize data as a large string
 * Case1Source: Initialize data as a small string
 * Sink: cat
 *    Case0Sink : Copy data to string using strcat
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the source function */
extern int CWE122_Heap_Based_Buffer_Overflow__c_src_char_cat_22_case0Global;

char * CWE122_Heap_Based_Buffer_Overflow__c_src_char_cat_22_case0Source(char * data)
{
    if(CWE122_Heap_Based_Buffer_Overflow__c_src_char_cat_22_case0Global)
    {
        /* NOTE: Initialize data as a large buffer that is larger than the small buffer used in the sink */
        memset(data, 'A', 100-1); /* fill with 'A's */
        data[100-1] = '\0'; /* null terminate */
    }
    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the source functions. */
extern int CWE122_Heap_Based_Buffer_Overflow__c_src_char_cat_22_case1V11Global;
extern int CWE122_Heap_Based_Buffer_Overflow__c_src_char_cat_22_case1V12Global;

/* case1V11() - use case1source and case0sink by setting the static variable to false instead of true */
char * CWE122_Heap_Based_Buffer_Overflow__c_src_char_cat_22_case1V11Source(char * data)
{
    if(CWE122_Heap_Based_Buffer_Overflow__c_src_char_cat_22_case1V11Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: Initialize data as a small buffer that as small or smaller than the small buffer used in the sink */
        memset(data, 'A', 50-1); /* fill with 'A's */
        data[50-1] = '\0'; /* null terminate */
    }
    return data;
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the if in the source function */
char * CWE122_Heap_Based_Buffer_Overflow__c_src_char_cat_22_case1V12Source(char * data)
{
    if(CWE122_Heap_Based_Buffer_Overflow__c_src_char_cat_22_case1V12Global)
    {
        /* ALT: Initialize data as a small buffer that as small or smaller than the small buffer used in the sink */
        memset(data, 'A', 50-1); /* fill with 'A's */
        data[50-1] = '\0'; /* null terminate */
    }
    return data;
}

#endif /* OMITCASE1 */
