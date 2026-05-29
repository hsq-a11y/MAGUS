/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_free_long_81.h
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_free.label.xml
Template File: sources-sinks-81.tmpl.h
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source:  Allocate data using new
 * Case1Source: Allocate data using malloc()
 * Sinks:
 *    Case1Sink: Deallocate data using delete
 *    Case0Sink : Deallocate data using free()
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_free_long_81
{

class CWE762_Mismatched_Memory_Management_Routines__new_free_long_81_base
{
public:
    /* pure virtual function */
    virtual void action(long * data) const = 0;
};

#ifndef OMITCASE0

class CWE762_Mismatched_Memory_Management_Routines__new_free_long_81_case0 : public CWE762_Mismatched_Memory_Management_Routines__new_free_long_81_base
{
public:
    void action(long * data) const;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE762_Mismatched_Memory_Management_Routines__new_free_long_81_case1V1 : public CWE762_Mismatched_Memory_Management_Routines__new_free_long_81_base
{
public:
    void action(long * data) const;
};

class CWE762_Mismatched_Memory_Management_Routines__new_free_long_81_case1V2 : public CWE762_Mismatched_Memory_Management_Routines__new_free_long_81_base
{
public:
    void action(long * data) const;
};

#endif /* OMITCASE1 */

}
