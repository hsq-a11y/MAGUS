/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__char_cat_83.h
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-83.tmpl.h
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

#include "std_testcase.h"

#include <wchar.h>

namespace CWE665_Improper_Initialization__char_cat_83
{

#ifndef OMITCASE0

class CWE665_Improper_Initialization__char_cat_83_case0
{
public:
    CWE665_Improper_Initialization__char_cat_83_case0(char * dataCopy);
    ~CWE665_Improper_Initialization__char_cat_83_case0();

private:
    char * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE665_Improper_Initialization__char_cat_83_case1V1
{
public:
    CWE665_Improper_Initialization__char_cat_83_case1V1(char * dataCopy);
    ~CWE665_Improper_Initialization__char_cat_83_case1V1();

private:
    char * data;
};

#endif /* OMITCASE1 */

}
