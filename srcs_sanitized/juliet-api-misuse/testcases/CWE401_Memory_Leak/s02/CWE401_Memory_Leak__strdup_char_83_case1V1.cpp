/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__strdup_char_83_case1V1.cpp
Label Definition File: CWE401_Memory_Leak__strdup.label.xml
Template File: sources-sinks-83_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Case0Source:  Allocate data using strdup()
 * Case1Source: Allocate data on the stack
 * Sinks:
 *    Case1Sink: call free() on data
 *    Case0Sink : no deallocation of data
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE401_Memory_Leak__strdup_char_83.h"

namespace CWE401_Memory_Leak__strdup_char_83
{
CWE401_Memory_Leak__strdup_char_83_case1V1::CWE401_Memory_Leak__strdup_char_83_case1V1(char * dataCopy)
{
    data = dataCopy;
    /* ALT: Use memory allocated on the stack with ALLOCA */
    data = (char *)ALLOCA(100*sizeof(char));
    /* Initialize then use data */
    strcpy(data, "a string");
    printLine(data);
}

CWE401_Memory_Leak__strdup_char_83_case1V1::~CWE401_Memory_Leak__strdup_char_83_case1V1()
{
    /* NOTE: No deallocation of memory */
    /* no deallocation */
    ; /* empty statement needed for some flow variants */
}
}
#endif /* OMITCASE1 */
