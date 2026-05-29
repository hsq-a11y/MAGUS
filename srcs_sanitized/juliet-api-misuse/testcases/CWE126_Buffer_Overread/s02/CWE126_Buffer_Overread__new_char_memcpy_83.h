/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__new_char_memcpy_83.h
Label Definition File: CWE126_Buffer_Overread__new.label.xml
Template File: sources-sink-83.tmpl.h
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * Case0Source:  Use a small buffer
 * Case1Source: Use a large buffer
 * Sinks: memcpy
 *    Case0Sink : Copy data to string using memcpy
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE126_Buffer_Overread__new_char_memcpy_83
{

#ifndef OMITCASE0

class CWE126_Buffer_Overread__new_char_memcpy_83_case0
{
public:
    CWE126_Buffer_Overread__new_char_memcpy_83_case0(char * dataCopy);
    ~CWE126_Buffer_Overread__new_char_memcpy_83_case0();

private:
    char * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE126_Buffer_Overread__new_char_memcpy_83_case1V1
{
public:
    CWE126_Buffer_Overread__new_char_memcpy_83_case1V1(char * dataCopy);
    ~CWE126_Buffer_Overread__new_char_memcpy_83_case1V1();

private:
    char * data;
};

#endif /* OMITCASE1 */

}
