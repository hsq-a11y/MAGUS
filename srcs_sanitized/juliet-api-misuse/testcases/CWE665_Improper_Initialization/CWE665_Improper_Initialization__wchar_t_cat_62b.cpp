/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__wchar_t_cat_62b.cpp
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * Case0Source:  Do not initialize data properly
 * Case1Source: Initialize data
 * Sinks: cat
 *    Case0Sink : Copy string to data using wcscat
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE665_Improper_Initialization__wchar_t_cat_62
{

#ifndef OMITCASE0

void case0Source(wchar_t * &data)
{
    /* NOTE: Do not initialize data */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
void case1V1Source(wchar_t * &data)
{
    /* ALT: Properly initialize data */
    data[0] = L'\0'; /* null terminate */
}

#endif /* OMITCASE1 */

} /* close namespace */
