/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_67b.c
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__malloc.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * Case0Source: fgets Read data from the console using fgets()
 * Case1Source: Small number greater than zero
 * Sinks:
 *    Case1Sink: Allocate memory with malloc() and check the size of the memory to be allocated
 *    Case0Sink : Allocate memory with malloc(), but incorrectly check the size of the memory to be allocated
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)

#define HELLO_STRING "hello"

typedef struct _CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_67_structType
{
    size_t structFirst;
} CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_67_structType;

#ifndef OMITCASE0

void CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_67b_case0Sink(CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_67_structType myStruct)
{
    size_t data = myStruct.structFirst;
    {
        char * myString;
        /* NOTE: No MAXIMUM limitation for memory allocation, but ensure data is large enough
         * for the strcpy() function to not cause a buffer overflow */
        /* INCIDENTAL NOTE: The source could cause a type overrun in data or in the memory allocation */
        if (data > strlen(HELLO_STRING))
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
            printLine("Input is less than the length of the source string");
        }
    }
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_67b_case1V1Sink(CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_67_structType myStruct)
{
    size_t data = myStruct.structFirst;
    {
        char * myString;
        /* NOTE: No MAXIMUM limitation for memory allocation, but ensure data is large enough
         * for the strcpy() function to not cause a buffer overflow */
        /* INCIDENTAL NOTE: The source could cause a type overrun in data or in the memory allocation */
        if (data > strlen(HELLO_STRING))
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
            printLine("Input is less than the length of the source string");
        }
    }
}

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_67b_case1V2Sink(CWE789_Uncontrolled_Mem_Alloc__malloc_char_fgets_67_structType myStruct)
{
    size_t data = myStruct.structFirst;
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

#endif /* OMITCASE1 */
