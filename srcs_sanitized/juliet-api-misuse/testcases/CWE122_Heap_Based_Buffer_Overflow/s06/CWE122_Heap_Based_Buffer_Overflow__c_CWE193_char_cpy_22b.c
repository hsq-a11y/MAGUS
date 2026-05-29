/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_cpy_22b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE193.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate memory for a string, but do not allocate space for NULL terminator
 * Case1Source: Allocate enough memory for a string and the NULL terminator
 * Sink: cpy
 *    Case0Sink : Copy string to data using strcpy()
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

/* MAINTENANCE NOTE: The length of this string should equal the 10 */
#define SRC_STRING "AAAAAAAAAA"

#ifndef OMITCASE0

/* The global variable below is used to drive control flow in the source function */
extern int CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_cpy_22_case0Global;

char * CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_cpy_22_case0Source(char * data)
{
    if(CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_cpy_22_case0Global)
    {
        /* NOTE: Did not leave space for a null terminator */
        data = (char *)malloc(10*sizeof(char));
        if (data == NULL) {exit(-1);}
    }
    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* The global variables below are used to drive control flow in the source functions. */
extern int CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_cpy_22_case1V11Global;
extern int CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_cpy_22_case1V12Global;

/* case1V11() - use case1source and case0sink by setting the static variable to false instead of true */
char * CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_cpy_22_case1V11Source(char * data)
{
    if(CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_cpy_22_case1V11Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* ALT: Allocate space for a null terminator */
        data = (char *)malloc((10+1)*sizeof(char));
        if (data == NULL) {exit(-1);}
    }
    return data;
}

/* case1V12() - use case1source and case0sink by reversing the blocks in the if in the source function */
char * CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_cpy_22_case1V12Source(char * data)
{
    if(CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_cpy_22_case1V12Global)
    {
        /* ALT: Allocate space for a null terminator */
        data = (char *)malloc((10+1)*sizeof(char));
        if (data == NULL) {exit(-1);}
    }
    return data;
}

#endif /* OMITCASE1 */
