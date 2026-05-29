/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_free_char_83.h
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_free.label.xml
Template File: sources-sinks-83.tmpl.h
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * Case0Source:  Allocate data using new
 * Case1Source: Allocate data using malloc()
 * Sinks:
 *    Case1Sink: Deallocate data using delete
 *    Case0Sink : Deallocate data using free()
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_free_char_83
{

#ifndef OMITCASE0

class CWE762_Mismatched_Memory_Management_Routines__new_free_char_83_case0
{
public:
    CWE762_Mismatched_Memory_Management_Routines__new_free_char_83_case0(char * dataCopy);
    ~CWE762_Mismatched_Memory_Management_Routines__new_free_char_83_case0();

private:
    char * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE762_Mismatched_Memory_Management_Routines__new_free_char_83_case1V1
{
public:
    CWE762_Mismatched_Memory_Management_Routines__new_free_char_83_case1V1(char * dataCopy);
    ~CWE762_Mismatched_Memory_Management_Routines__new_free_char_83_case1V1();

private:
    char * data;
};

class CWE762_Mismatched_Memory_Management_Routines__new_free_char_83_case1V2
{
public:
    CWE762_Mismatched_Memory_Management_Routines__new_free_char_83_case1V2(char * dataCopy);
    ~CWE762_Mismatched_Memory_Management_Routines__new_free_char_83_case1V2();

private:
    char * data;
};

#endif /* OMITCASE1 */

}
