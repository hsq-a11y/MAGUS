/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__new_char_rand_84.h
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__new.label.xml
Template File: sources-sinks-84.tmpl.h
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * Case0Source: rand Set data to result of rand(), which may be zero
 * Case1Source: Small number greater than zero
 * Sinks:
 *    Case1Sink: Allocate memory with new [] and check the size of the memory to be allocated
 *    Case0Sink : Allocate memory with new [], but incorrectly check the size of the memory to be allocated
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE789_Uncontrolled_Mem_Alloc__new_char_rand_84
{

#ifndef OMITCASE0

class CWE789_Uncontrolled_Mem_Alloc__new_char_rand_84_case0
{
public:
    CWE789_Uncontrolled_Mem_Alloc__new_char_rand_84_case0(size_t dataCopy);
    ~CWE789_Uncontrolled_Mem_Alloc__new_char_rand_84_case0();

private:
    size_t data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE789_Uncontrolled_Mem_Alloc__new_char_rand_84_case1V1
{
public:
    CWE789_Uncontrolled_Mem_Alloc__new_char_rand_84_case1V1(size_t dataCopy);
    ~CWE789_Uncontrolled_Mem_Alloc__new_char_rand_84_case1V1();

private:
    size_t data;
};

class CWE789_Uncontrolled_Mem_Alloc__new_char_rand_84_case1V2
{
public:
    CWE789_Uncontrolled_Mem_Alloc__new_char_rand_84_case1V2(size_t dataCopy);
    ~CWE789_Uncontrolled_Mem_Alloc__new_char_rand_84_case1V2();

private:
    size_t data;
};

#endif /* OMITCASE1 */

}
