/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_ncpy_83_case0.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE193.label.xml
Template File: sources-sink-83_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate memory for a string, but do not allocate space for NULL terminator
 * Case1Source: Allocate enough memory for a string and the NULL terminator
 * Sinks: ncpy
 *    Case0Sink : Copy string to data using strncpy()
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_ncpy_83.h"

namespace CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_ncpy_83
{
CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_ncpy_83_case0::CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_ncpy_83_case0(char * dataCopy)
{
    data = dataCopy;
    /* NOTE: Did not leave space for a null terminator */
    data = (char *)malloc(10*sizeof(char));
    if (data == NULL) {exit(-1);}
}

CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_ncpy_83_case0::~CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_ncpy_83_case0()
{
    {
        char source[10+1] = SRC_STRING;
        /* Copy length + 1 to include NUL terminator from source */
        /* NOTE: data may not have enough space to hold source */
        strncpy(data, source, strlen(source) + 1);
        printLine(data);
        free(data);
    }
}
}
#endif /* OMITCASE0 */
