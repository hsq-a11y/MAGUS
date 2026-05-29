/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__strdup_delete_char_82.h
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__strdup_delete.label.xml
Template File: sources-sinks-82.tmpl.h
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source:  Allocate data using strdup()
 * Case1Source: Allocate data using new
 * Sinks:
 *    Case1Sink: Deallocate data using free()
 *    Case0Sink : Deallocate data using delete
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE762_Mismatched_Memory_Management_Routines__strdup_delete_char_82
{

class CWE762_Mismatched_Memory_Management_Routines__strdup_delete_char_82_base
{
public:
    /* pure virtual function */
    virtual void action(char * data) = 0;
};

#ifndef OMITCASE0

class CWE762_Mismatched_Memory_Management_Routines__strdup_delete_char_82_case0 : public CWE762_Mismatched_Memory_Management_Routines__strdup_delete_char_82_base
{
public:
    void action(char * data);
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE762_Mismatched_Memory_Management_Routines__strdup_delete_char_82_case1V1 : public CWE762_Mismatched_Memory_Management_Routines__strdup_delete_char_82_base
{
public:
    void action(char * data);
};

class CWE762_Mismatched_Memory_Management_Routines__strdup_delete_char_82_case1V2 : public CWE762_Mismatched_Memory_Management_Routines__strdup_delete_char_82_base
{
public:
    void action(char * data);
};

#endif /* OMITCASE1 */

}
