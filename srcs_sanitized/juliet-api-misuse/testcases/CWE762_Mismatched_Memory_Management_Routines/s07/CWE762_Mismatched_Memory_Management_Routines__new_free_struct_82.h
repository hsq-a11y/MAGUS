/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_free_struct_82.h
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_free.label.xml
Template File: sources-sinks-82.tmpl.h
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source:  Allocate data using new
 * Case1Source: Allocate data using malloc()
 * Sinks:
 *    Case1Sink: Deallocate data using delete
 *    Case0Sink : Deallocate data using free()
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_free_struct_82
{

class CWE762_Mismatched_Memory_Management_Routines__new_free_struct_82_base
{
public:
    /* pure virtual function */
    virtual void action(twoIntsStruct * data) = 0;
};

#ifndef OMITCASE0

class CWE762_Mismatched_Memory_Management_Routines__new_free_struct_82_case0 : public CWE762_Mismatched_Memory_Management_Routines__new_free_struct_82_base
{
public:
    void action(twoIntsStruct * data);
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE762_Mismatched_Memory_Management_Routines__new_free_struct_82_case1V1 : public CWE762_Mismatched_Memory_Management_Routines__new_free_struct_82_base
{
public:
    void action(twoIntsStruct * data);
};

class CWE762_Mismatched_Memory_Management_Routines__new_free_struct_82_case1V2 : public CWE762_Mismatched_Memory_Management_Routines__new_free_struct_82_base
{
public:
    void action(twoIntsStruct * data);
};

#endif /* OMITCASE1 */

}
