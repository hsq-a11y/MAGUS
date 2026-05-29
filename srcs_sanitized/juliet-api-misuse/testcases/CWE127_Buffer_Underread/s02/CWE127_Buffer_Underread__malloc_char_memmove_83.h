/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__malloc_char_memmove_83.h
Label Definition File: CWE127_Buffer_Underread__malloc.label.xml
Template File: sources-sink-83.tmpl.h
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * Case0Source:  Set data pointer to before the allocated memory buffer
 * Case1Source: Set data pointer to the allocated memory buffer
 * Sinks: memmove
 *    Case0Sink : Copy data to string using memmove
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE127_Buffer_Underread__malloc_char_memmove_83
{

#ifndef OMITCASE0

class CWE127_Buffer_Underread__malloc_char_memmove_83_case0
{
public:
    CWE127_Buffer_Underread__malloc_char_memmove_83_case0(char * dataCopy);
    ~CWE127_Buffer_Underread__malloc_char_memmove_83_case0();

private:
    char * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE127_Buffer_Underread__malloc_char_memmove_83_case1V1
{
public:
    CWE127_Buffer_Underread__malloc_char_memmove_83_case1V1(char * dataCopy);
    ~CWE127_Buffer_Underread__malloc_char_memmove_83_case1V1();

private:
    char * data;
};

#endif /* OMITCASE1 */

}
