/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_int_malloc_83.h
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete.label.xml
Template File: sources-sinks-83.tmpl.h
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source: malloc Allocate data using malloc()
 * Case1Source: Allocate data using new
 * Sinks:
 *    Case1Sink: Deallocate data using free()
 *    Case0Sink : Deallocate data using delete
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__delete_int_malloc_83
{

#ifndef OMITCASE0

class CWE762_Mismatched_Memory_Management_Routines__delete_int_malloc_83_case0
{
public:
    CWE762_Mismatched_Memory_Management_Routines__delete_int_malloc_83_case0(int * dataCopy);
    ~CWE762_Mismatched_Memory_Management_Routines__delete_int_malloc_83_case0();

private:
    int * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE762_Mismatched_Memory_Management_Routines__delete_int_malloc_83_case1V1
{
public:
    CWE762_Mismatched_Memory_Management_Routines__delete_int_malloc_83_case1V1(int * dataCopy);
    ~CWE762_Mismatched_Memory_Management_Routines__delete_int_malloc_83_case1V1();

private:
    int * data;
};

class CWE762_Mismatched_Memory_Management_Routines__delete_int_malloc_83_case1V2
{
public:
    CWE762_Mismatched_Memory_Management_Routines__delete_int_malloc_83_case1V2(int * dataCopy);
    ~CWE762_Mismatched_Memory_Management_Routines__delete_int_malloc_83_case1V2();

private:
    int * data;
};

#endif /* OMITCASE1 */

}
