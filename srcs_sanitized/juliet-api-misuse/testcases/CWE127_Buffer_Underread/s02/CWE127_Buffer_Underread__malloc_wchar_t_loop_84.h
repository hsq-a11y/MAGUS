/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__malloc_wchar_t_loop_84.h
Label Definition File: CWE127_Buffer_Underread__malloc.label.xml
Template File: sources-sink-84.tmpl.h
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * Case0Source:  Set data pointer to before the allocated memory buffer
 * Case1Source: Set data pointer to the allocated memory buffer
 * Sinks: loop
 *    Case0Sink : Copy data to string using a loop
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE127_Buffer_Underread__malloc_wchar_t_loop_84
{

#ifndef OMITCASE0

class CWE127_Buffer_Underread__malloc_wchar_t_loop_84_case0
{
public:
    CWE127_Buffer_Underread__malloc_wchar_t_loop_84_case0(wchar_t * dataCopy);
    ~CWE127_Buffer_Underread__malloc_wchar_t_loop_84_case0();

private:
    wchar_t * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE127_Buffer_Underread__malloc_wchar_t_loop_84_case1V1
{
public:
    CWE127_Buffer_Underread__malloc_wchar_t_loop_84_case1V1(wchar_t * dataCopy);
    ~CWE127_Buffer_Underread__malloc_wchar_t_loop_84_case1V1();

private:
    wchar_t * data;
};

#endif /* OMITCASE1 */

}
