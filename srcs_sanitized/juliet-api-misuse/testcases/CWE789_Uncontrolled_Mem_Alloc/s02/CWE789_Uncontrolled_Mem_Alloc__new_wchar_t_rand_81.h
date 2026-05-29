/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__new_wchar_t_rand_81.h
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__new.label.xml
Template File: sources-sinks-81.tmpl.h
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * Case0Source: rand Set data to result of rand(), which may be zero
 * Case1Source: Small number greater than zero
 * Sinks:
 *    Case1Sink: Allocate memory with new [] and check the size of the memory to be allocated
 *    Case0Sink : Allocate memory with new [], but incorrectly check the size of the memory to be allocated
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE789_Uncontrolled_Mem_Alloc__new_wchar_t_rand_81
{

class CWE789_Uncontrolled_Mem_Alloc__new_wchar_t_rand_81_base
{
public:
    /* pure virtual function */
    virtual void action(size_t data) const = 0;
};

#ifndef OMITCASE0

class CWE789_Uncontrolled_Mem_Alloc__new_wchar_t_rand_81_case0 : public CWE789_Uncontrolled_Mem_Alloc__new_wchar_t_rand_81_base
{
public:
    void action(size_t data) const;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE789_Uncontrolled_Mem_Alloc__new_wchar_t_rand_81_case1V1 : public CWE789_Uncontrolled_Mem_Alloc__new_wchar_t_rand_81_base
{
public:
    void action(size_t data) const;
};

class CWE789_Uncontrolled_Mem_Alloc__new_wchar_t_rand_81_case1V2 : public CWE789_Uncontrolled_Mem_Alloc__new_wchar_t_rand_81_base
{
public:
    void action(size_t data) const;
};

#endif /* OMITCASE1 */

}
