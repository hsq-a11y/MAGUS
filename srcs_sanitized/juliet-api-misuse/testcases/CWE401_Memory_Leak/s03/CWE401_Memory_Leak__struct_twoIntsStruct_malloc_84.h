/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__struct_twoIntsStruct_malloc_84.h
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-84.tmpl.h
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source: malloc Allocate data using malloc()
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call free() on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE401_Memory_Leak__struct_twoIntsStruct_malloc_84
{

#ifndef OMITCASE0

class CWE401_Memory_Leak__struct_twoIntsStruct_malloc_84_case0
{
public:
    CWE401_Memory_Leak__struct_twoIntsStruct_malloc_84_case0(struct _twoIntsStruct * dataCopy);
    ~CWE401_Memory_Leak__struct_twoIntsStruct_malloc_84_case0();

private:
    struct _twoIntsStruct * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE401_Memory_Leak__struct_twoIntsStruct_malloc_84_case1V1
{
public:
    CWE401_Memory_Leak__struct_twoIntsStruct_malloc_84_case1V1(struct _twoIntsStruct * dataCopy);
    ~CWE401_Memory_Leak__struct_twoIntsStruct_malloc_84_case1V1();

private:
    struct _twoIntsStruct * data;
};

class CWE401_Memory_Leak__struct_twoIntsStruct_malloc_84_case1V2
{
public:
    CWE401_Memory_Leak__struct_twoIntsStruct_malloc_84_case1V2(struct _twoIntsStruct * dataCopy);
    ~CWE401_Memory_Leak__struct_twoIntsStruct_malloc_84_case1V2();

private:
    struct _twoIntsStruct * data;
};

#endif /* OMITCASE1 */

}
