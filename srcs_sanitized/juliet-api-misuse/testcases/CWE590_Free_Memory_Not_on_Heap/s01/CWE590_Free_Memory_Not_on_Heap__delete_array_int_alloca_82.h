/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__delete_array_int_alloca_82.h
Label Definition File: CWE590_Free_Memory_Not_on_Heap__delete_array.label.xml
Template File: sources-sink-82.tmpl.h
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * Case0Source: alloca Data buffer is allocated on the stack with alloca()
 * Case1Source: Allocate memory on the heap
 * Sinks:
 *    Case0Sink : Print then free data
 * Flow Variant: 82 Data flow: data passed in a parameter to a virtual method called via a pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE590_Free_Memory_Not_on_Heap__delete_array_int_alloca_82
{

class CWE590_Free_Memory_Not_on_Heap__delete_array_int_alloca_82_base
{
public:
    /* pure virtual function */
    virtual void action(int * data) = 0;
};

#ifndef OMITCASE0

class CWE590_Free_Memory_Not_on_Heap__delete_array_int_alloca_82_case0 : public CWE590_Free_Memory_Not_on_Heap__delete_array_int_alloca_82_base
{
public:
    void action(int * data);
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE590_Free_Memory_Not_on_Heap__delete_array_int_alloca_82_case1V1 : public CWE590_Free_Memory_Not_on_Heap__delete_array_int_alloca_82_base
{
public:
    void action(int * data);
};

#endif /* OMITCASE1 */

}
