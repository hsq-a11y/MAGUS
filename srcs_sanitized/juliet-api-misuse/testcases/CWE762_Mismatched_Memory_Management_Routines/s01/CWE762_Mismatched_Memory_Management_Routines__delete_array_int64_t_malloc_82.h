/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_array_int64_t_malloc_82.h
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete_array.label.xml
Template File: sources-sinks-82.tmpl.h
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source: malloc Allocate data using malloc()
 * Case1Source: Allocate data using new []
 * Sinks:
 *    Case1Sink: Deallocate data using free()
 *    Case0Sink : Deallocate data using delete []
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__delete_array_int64_t_malloc_82
{

class CWE762_Mismatched_Memory_Management_Routines__delete_array_int64_t_malloc_82_base
{
public:
    /* pure virtual function */
    virtual void action(int64_t * data) = 0;
};

#ifndef OMITCASE0

class CWE762_Mismatched_Memory_Management_Routines__delete_array_int64_t_malloc_82_case0 : public CWE762_Mismatched_Memory_Management_Routines__delete_array_int64_t_malloc_82_base
{
public:
    void action(int64_t * data);
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE762_Mismatched_Memory_Management_Routines__delete_array_int64_t_malloc_82_case1V1 : public CWE762_Mismatched_Memory_Management_Routines__delete_array_int64_t_malloc_82_base
{
public:
    void action(int64_t * data);
};

class CWE762_Mismatched_Memory_Management_Routines__delete_array_int64_t_malloc_82_case1V2 : public CWE762_Mismatched_Memory_Management_Routines__delete_array_int64_t_malloc_82_base
{
public:
    void action(int64_t * data);
};

#endif /* OMITCASE1 */

}
