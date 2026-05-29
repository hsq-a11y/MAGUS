/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__malloc_char_memmove_84.h
Label Definition File: CWE126_Buffer_Overread__malloc.label.xml
Template File: sources-sink-84.tmpl.h
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * Case0Source:  Use a small buffer
 * Case1Source: Use a large buffer
 * Sinks: memmove
 *    Case0Sink : Copy data to string using memmove
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE126_Buffer_Overread__malloc_char_memmove_84
{

#ifndef OMITCASE0

class CWE126_Buffer_Overread__malloc_char_memmove_84_case0
{
public:
    CWE126_Buffer_Overread__malloc_char_memmove_84_case0(char * dataCopy);
    ~CWE126_Buffer_Overread__malloc_char_memmove_84_case0();

private:
    char * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE126_Buffer_Overread__malloc_char_memmove_84_case1V1
{
public:
    CWE126_Buffer_Overread__malloc_char_memmove_84_case1V1(char * dataCopy);
    ~CWE126_Buffer_Overread__malloc_char_memmove_84_case1V1();

private:
    char * data;
};

#endif /* OMITCASE1 */

}
