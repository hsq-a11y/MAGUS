/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__wchar_t_realloc_83.h
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-83.tmpl.h
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source: realloc Allocate data using realloc()
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call free() on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE401_Memory_Leak__wchar_t_realloc_83
{

#ifndef OMITCASE0

class CWE401_Memory_Leak__wchar_t_realloc_83_case0
{
public:
    CWE401_Memory_Leak__wchar_t_realloc_83_case0(wchar_t * dataCopy);
    ~CWE401_Memory_Leak__wchar_t_realloc_83_case0();

private:
    wchar_t * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE401_Memory_Leak__wchar_t_realloc_83_case1V1
{
public:
    CWE401_Memory_Leak__wchar_t_realloc_83_case1V1(wchar_t * dataCopy);
    ~CWE401_Memory_Leak__wchar_t_realloc_83_case1V1();

private:
    wchar_t * data;
};

class CWE401_Memory_Leak__wchar_t_realloc_83_case1V2
{
public:
    CWE401_Memory_Leak__wchar_t_realloc_83_case1V2(wchar_t * dataCopy);
    ~CWE401_Memory_Leak__wchar_t_realloc_83_case1V2();

private:
    wchar_t * data;
};

#endif /* OMITCASE1 */

}
