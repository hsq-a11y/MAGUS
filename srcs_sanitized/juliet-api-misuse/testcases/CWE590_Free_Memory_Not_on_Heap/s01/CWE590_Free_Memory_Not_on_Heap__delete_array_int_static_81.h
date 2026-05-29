/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__delete_array_int_static_81.h
Label Definition File: CWE590_Free_Memory_Not_on_Heap__delete_array.label.xml
Template File: sources-sink-81.tmpl.h
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * Case0Source: static Data buffer is declared static on the stack
 * Case1Source: Allocate memory on the heap
 * Sinks:
 *    Case0Sink : Print then free data
 * Flow Variant: 81 Data flow: data passed in a parameter to a virtual method called via a reference
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE590_Free_Memory_Not_on_Heap__delete_array_int_static_81
{

class CWE590_Free_Memory_Not_on_Heap__delete_array_int_static_81_base
{
public:
    /* pure virtual function */
    virtual void action(int * data) const = 0;
};

#ifndef OMITCASE0

class CWE590_Free_Memory_Not_on_Heap__delete_array_int_static_81_case0 : public CWE590_Free_Memory_Not_on_Heap__delete_array_int_static_81_base
{
public:
    void action(int * data) const;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE590_Free_Memory_Not_on_Heap__delete_array_int_static_81_case1V1 : public CWE590_Free_Memory_Not_on_Heap__delete_array_int_static_81_base
{
public:
    void action(int * data) const;
};

#endif /* OMITCASE1 */

}
