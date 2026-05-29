/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__new_wchar_t_rand_83_case1V1.cpp
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__new.label.xml
Template File: sources-sinks-83_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * Case0Source: rand Set data to result of rand(), which may be zero
 * Case1Source: Small number greater than zero
 * Sinks:
 *    Case1Sink: Allocate memory with new [] and check the size of the memory to be allocated
 *    Case0Sink : Allocate memory with new [], but incorrectly check the size of the memory to be allocated
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE789_Uncontrolled_Mem_Alloc__new_wchar_t_rand_83.h"

#define HELLO_STRING L"hello"

namespace CWE789_Uncontrolled_Mem_Alloc__new_wchar_t_rand_83
{
CWE789_Uncontrolled_Mem_Alloc__new_wchar_t_rand_83_case1V1::CWE789_Uncontrolled_Mem_Alloc__new_wchar_t_rand_83_case1V1(size_t dataCopy)
{
    data = dataCopy;
    /* ALT: Use a relatively small number for memory allocation */
    data = 20;
}

CWE789_Uncontrolled_Mem_Alloc__new_wchar_t_rand_83_case1V1::~CWE789_Uncontrolled_Mem_Alloc__new_wchar_t_rand_83_case1V1()
{
    {
        wchar_t * myString;
        /* NOTE: No MAXIMUM limitation for memory allocation, but ensure data is large enough
         * for the wcscpy() function to not cause a buffer overflow */
        /* INCIDENTAL NOTE: The source could cause a type overrun in data or in the memory allocation */
        if (data > wcslen(HELLO_STRING))
        {
            myString = new wchar_t[data];
            /* Copy a small string into myString */
            wcscpy(myString, HELLO_STRING);
            printWLine(myString);
            delete [] myString;
        }
        else
        {
            printLine("Input is less than the length of the source string");
        }
    }
}
}
#endif /* OMITCASE1 */
