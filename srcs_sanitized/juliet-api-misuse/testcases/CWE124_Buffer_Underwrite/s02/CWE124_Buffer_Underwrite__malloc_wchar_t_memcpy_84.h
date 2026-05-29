/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__malloc_wchar_t_memcpy_84.h
Label Definition File: CWE124_Buffer_Underwrite__malloc.label.xml
Template File: sources-sink-84.tmpl.h
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * Case0Source:  Set data pointer to before the allocated memory buffer
 * Case1Source: Set data pointer to the allocated memory buffer
 * Sinks: memcpy
 *    Case0Sink : Copy string to data using memcpy
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE124_Buffer_Underwrite__malloc_wchar_t_memcpy_84
{

#ifndef OMITCASE0

class CWE124_Buffer_Underwrite__malloc_wchar_t_memcpy_84_case0
{
public:
    CWE124_Buffer_Underwrite__malloc_wchar_t_memcpy_84_case0(wchar_t * dataCopy);
    ~CWE124_Buffer_Underwrite__malloc_wchar_t_memcpy_84_case0();

private:
    wchar_t * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE124_Buffer_Underwrite__malloc_wchar_t_memcpy_84_case1V1
{
public:
    CWE124_Buffer_Underwrite__malloc_wchar_t_memcpy_84_case1V1(wchar_t * dataCopy);
    ~CWE124_Buffer_Underwrite__malloc_wchar_t_memcpy_84_case1V1();

private:
    wchar_t * data;
};

#endif /* OMITCASE1 */

}
