/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_cpy_61b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE193.label.xml
Template File: sources-sink-61b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate memory for a string, but do not allocate space for NULL terminator
 * Case1Source: Allocate enough memory for a string and the NULL terminator
 * Sinks: cpy
 *    Case0Sink : Copy string to data using strcpy()
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

/* MAINTENANCE NOTE: The length of this string should equal the 10 */
#define SRC_STRING "AAAAAAAAAA"

#ifndef OMITCASE0

char * CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_cpy_61b_case0Source(char * data)
{
    /* NOTE: Did not leave space for a null terminator */
    data = (char *)malloc(10*sizeof(char));
    if (data == NULL) {exit(-1);}
    return data;
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
char * CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_cpy_61b_case1V1Source(char * data)
{
    /* ALT: Allocate space for a null terminator */
    data = (char *)malloc((10+1)*sizeof(char));
    if (data == NULL) {exit(-1);}
    return data;
}

#endif /* OMITCASE1 */
