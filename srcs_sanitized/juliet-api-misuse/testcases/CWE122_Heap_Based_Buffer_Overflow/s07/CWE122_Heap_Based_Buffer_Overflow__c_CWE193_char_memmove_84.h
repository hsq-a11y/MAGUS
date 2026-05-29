/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memmove_84.h
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE193.label.xml
Template File: sources-sink-84.tmpl.h
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * Case0Source:  Allocate memory for a string, but do not allocate space for NULL terminator
 * Case1Source: Allocate enough memory for a string and the NULL terminator
 * Sinks: memmove
 *    Case0Sink : Copy string to data using memmove()
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

/* MAINTENANCE NOTE: The length of this string should equal the 10 */
#define SRC_STRING "AAAAAAAAAA"

namespace CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memmove_84
{

#ifndef OMITCASE0

class CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memmove_84_case0
{
public:
    CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memmove_84_case0(char * dataCopy);
    ~CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memmove_84_case0();

private:
    char * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memmove_84_case1V1
{
public:
    CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memmove_84_case1V1(char * dataCopy);
    ~CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memmove_84_case1V1();

private:
    char * data;
};

#endif /* OMITCASE1 */

}
