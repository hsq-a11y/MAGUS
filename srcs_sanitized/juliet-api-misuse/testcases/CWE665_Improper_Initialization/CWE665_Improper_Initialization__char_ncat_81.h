/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__char_ncat_81.h
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-81.tmpl.h
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * Case0Source:  Do not initialize data properly
 * Case1Source: Initialize data
 * Sinks: ncat
 *    Case0Sink : Copy string to data using strncat
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE665_Improper_Initialization__char_ncat_81
{

class CWE665_Improper_Initialization__char_ncat_81_base
{
public:
    /* pure virtual function */
    virtual void action(char * data) const = 0;
};

#ifndef OMITCASE0

class CWE665_Improper_Initialization__char_ncat_81_case0 : public CWE665_Improper_Initialization__char_ncat_81_base
{
public:
    void action(char * data) const;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE665_Improper_Initialization__char_ncat_81_case1V1 : public CWE665_Improper_Initialization__char_ncat_81_base
{
public:
    void action(char * data) const;
};

#endif /* OMITCASE1 */

}
