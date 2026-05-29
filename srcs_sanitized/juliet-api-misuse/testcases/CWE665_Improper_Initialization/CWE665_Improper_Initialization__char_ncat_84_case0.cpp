/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__char_ncat_84_case0.cpp
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-84_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * Case0Source:  Do not initialize data properly
 * Case1Source: Initialize data
 * Sinks: ncat
 *    Case0Sink : Copy string to data using strncat
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE665_Improper_Initialization__char_ncat_84.h"

namespace CWE665_Improper_Initialization__char_ncat_84
{
CWE665_Improper_Initialization__char_ncat_84_case0::CWE665_Improper_Initialization__char_ncat_84_case0(char * dataCopy)
{
    data = dataCopy;
    /* NOTE: Do not initialize data */
    ; /* empty statement needed for some flow variants */
}

CWE665_Improper_Initialization__char_ncat_84_case0::~CWE665_Improper_Initialization__char_ncat_84_case0()
{
    {
        size_t sourceLen;
        char source[100];
        memset(source, 'C', 100-1); /* fill with 'C's */
        source[100-1] = '\0'; /* null terminate */
        sourceLen = strlen(source);
        /* NOTE: If data is not initialized properly, strncat() may not function correctly */
        strncat(data, source, sourceLen);
        printLine(data);
    }
}
}
#endif /* OMITCASE0 */
