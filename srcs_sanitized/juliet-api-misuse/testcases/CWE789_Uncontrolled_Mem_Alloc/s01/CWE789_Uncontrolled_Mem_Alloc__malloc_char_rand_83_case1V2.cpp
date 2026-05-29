/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__malloc_char_rand_83_case1V2.cpp
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__malloc.label.xml
Template File: sources-sinks-83_case1V2.tmpl.cpp
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * Case0Source: rand Set data to result of rand(), which may be zero
 * Case1Source: Small number greater than zero
 * Sinks:
 *    Case1Sink: Allocate memory with malloc() and check the size of the memory to be allocated
 *    Case0Sink : Allocate memory with malloc(), but incorrectly check the size of the memory to be allocated
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE789_Uncontrolled_Mem_Alloc__malloc_char_rand_83.h"

#define HELLO_STRING "hello"

namespace CWE789_Uncontrolled_Mem_Alloc__malloc_char_rand_83
{
CWE789_Uncontrolled_Mem_Alloc__malloc_char_rand_83_case1V2::CWE789_Uncontrolled_Mem_Alloc__malloc_char_rand_83_case1V2(size_t dataCopy)
{
    data = dataCopy;
    /* NOTE: Set data to a random value */
    data = rand();
}

CWE789_Uncontrolled_Mem_Alloc__malloc_char_rand_83_case1V2::~CWE789_Uncontrolled_Mem_Alloc__malloc_char_rand_83_case1V2()
{
    {
        char * myString;
        /* ALT: Include a MAXIMUM limitation for memory allocation and a check to ensure data is large enough
         * for the strcpy() function to not cause a buffer overflow */
        /* INCIDENTAL NOTE: The source could cause a type overrun in data or in the memory allocation */
        if (data > strlen(HELLO_STRING) && data < 100)
        {
            myString = (char *)malloc(data*sizeof(char));
            if (myString == NULL) {exit(-1);}
            /* Copy a small string into myString */
            strcpy(myString, HELLO_STRING);
            printLine(myString);
            free(myString);
        }
        else
        {
            printLine("Input is less than the length of the source string or too large");
        }
    }
}
}
#endif /* OMITCASE1 */
