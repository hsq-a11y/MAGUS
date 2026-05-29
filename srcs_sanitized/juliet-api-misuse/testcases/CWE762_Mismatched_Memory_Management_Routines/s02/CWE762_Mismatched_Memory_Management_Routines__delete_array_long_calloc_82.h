/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_array_long_calloc_82.h
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete_array.label.xml
Template File: sources-sinks-82.tmpl.h
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source: calloc Allocate data using calloc()
 * Case1Source: Allocate data using new []
 * Sinks:
 *    Case1Sink: Deallocate data using free()
 *    Case0Sink : Deallocate data using delete []
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__delete_array_long_calloc_82
{

class CWE762_Mismatched_Memory_Management_Routines__delete_array_long_calloc_82_base
{
public:
    /* pure virtual function */
    virtual void action(long * data) = 0;
};

#ifndef OMITCASE0

class CWE762_Mismatched_Memory_Management_Routines__delete_array_long_calloc_82_case0 : public CWE762_Mismatched_Memory_Management_Routines__delete_array_long_calloc_82_base
{
public:
    void action(long * data);
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE762_Mismatched_Memory_Management_Routines__delete_array_long_calloc_82_case1V1 : public CWE762_Mismatched_Memory_Management_Routines__delete_array_long_calloc_82_base
{
public:
    void action(long * data);
};

class CWE762_Mismatched_Memory_Management_Routines__delete_array_long_calloc_82_case1V2 : public CWE762_Mismatched_Memory_Management_Routines__delete_array_long_calloc_82_base
{
public:
    void action(long * data);
};

#endif /* OMITCASE1 */

}
