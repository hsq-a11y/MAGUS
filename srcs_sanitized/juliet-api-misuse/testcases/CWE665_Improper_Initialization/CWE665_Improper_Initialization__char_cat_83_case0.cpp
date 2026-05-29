/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__char_cat_83_case0.cpp
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-83_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * Case0Source:  Do not initialize data properly
 * Case1Source: Initialize data
 * Sinks: cat
 *    Case0Sink : Copy string to data using strcat
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE665_Improper_Initialization__char_cat_83.h"

namespace CWE665_Improper_Initialization__char_cat_83
{
CWE665_Improper_Initialization__char_cat_83_case0::CWE665_Improper_Initialization__char_cat_83_case0(char * dataCopy)
{
    data = dataCopy;
    /* NOTE: Do not initialize data */
    ; /* empty statement needed for some flow variants */
}

CWE665_Improper_Initialization__char_cat_83_case0::~CWE665_Improper_Initialization__char_cat_83_case0()
{
    {
        char source[100];
        memset(source, 'C', 100-1); /* fill with 'C's */
        source[100-1] = '\0'; /* null terminate */
        /* NOTE: If data is not initialized properly, strcat() may not function correctly */
        strcat(data, source);
        printLine(data);
    }
}
}
#endif /* OMITCASE0 */
