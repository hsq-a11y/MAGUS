/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_array_int64_t_calloc_83.h
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete_array.label.xml
Template File: sources-sinks-83.tmpl.h
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source: calloc Allocate data using calloc()
 * Case1Source: Allocate data using new []
 * Sinks:
 *    Case1Sink: Deallocate data using free()
 *    Case0Sink : Deallocate data using delete []
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__delete_array_int64_t_calloc_83
{

#ifndef OMITCASE0

class CWE762_Mismatched_Memory_Management_Routines__delete_array_int64_t_calloc_83_case0
{
public:
    CWE762_Mismatched_Memory_Management_Routines__delete_array_int64_t_calloc_83_case0(int64_t * dataCopy);
    ~CWE762_Mismatched_Memory_Management_Routines__delete_array_int64_t_calloc_83_case0();

private:
    int64_t * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE762_Mismatched_Memory_Management_Routines__delete_array_int64_t_calloc_83_case1V1
{
public:
    CWE762_Mismatched_Memory_Management_Routines__delete_array_int64_t_calloc_83_case1V1(int64_t * dataCopy);
    ~CWE762_Mismatched_Memory_Management_Routines__delete_array_int64_t_calloc_83_case1V1();

private:
    int64_t * data;
};

class CWE762_Mismatched_Memory_Management_Routines__delete_array_int64_t_calloc_83_case1V2
{
public:
    CWE762_Mismatched_Memory_Management_Routines__delete_array_int64_t_calloc_83_case1V2(int64_t * dataCopy);
    ~CWE762_Mismatched_Memory_Management_Routines__delete_array_int64_t_calloc_83_case1V2();

private:
    int64_t * data;
};

#endif /* OMITCASE1 */

}
