/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__wchar_t_ncat_82.h
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-82.tmpl.h
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * Case0Source:  Do not initialize data properly
 * Case1Source: Initialize data
 *    Case0Sink : Copy string to data using wcsncat
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE665_Improper_Initialization__wchar_t_ncat_82
{

class CWE665_Improper_Initialization__wchar_t_ncat_82_base
{
public:
    /* pure virtual function */
    virtual void action(wchar_t * data) = 0;
};

#ifndef OMITCASE0

class CWE665_Improper_Initialization__wchar_t_ncat_82_case0 : public CWE665_Improper_Initialization__wchar_t_ncat_82_base
{
public:
    void action(wchar_t * data);
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE665_Improper_Initialization__wchar_t_ncat_82_case1V1 : public CWE665_Improper_Initialization__wchar_t_ncat_82_base
{
public:
    void action(wchar_t * data);
};

#endif /* OMITCASE1 */

}
