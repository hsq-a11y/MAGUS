/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__char_cat_84.h
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-84.tmpl.h
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * Case0Source:  Do not initialize data properly
 * Case1Source: Initialize data
 * Sinks: cat
 *    Case0Sink : Copy string to data using strcat
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE665_Improper_Initialization__char_cat_84
{

#ifndef OMITCASE0

class CWE665_Improper_Initialization__char_cat_84_case0
{
public:
    CWE665_Improper_Initialization__char_cat_84_case0(char * dataCopy);
    ~CWE665_Improper_Initialization__char_cat_84_case0();

private:
    char * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE665_Improper_Initialization__char_cat_84_case1V1
{
public:
    CWE665_Improper_Initialization__char_cat_84_case1V1(char * dataCopy);
    ~CWE665_Improper_Initialization__char_cat_84_case1V1();

private:
    char * data;
};

#endif /* OMITCASE1 */

}
