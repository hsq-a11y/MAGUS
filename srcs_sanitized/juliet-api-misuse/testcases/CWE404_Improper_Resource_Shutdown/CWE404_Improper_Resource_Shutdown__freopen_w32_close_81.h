/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__freopen_w32_close_81.h
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-81.tmpl.h
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source: freopen Open a file using freopen()
 * Sinks: w32_close
 *    Case1Sink: Close the file using fclose()
 *    Case0Sink : Close the file using close()
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"

namespace CWE404_Improper_Resource_Shutdown__freopen_w32_close_81
{

class CWE404_Improper_Resource_Shutdown__freopen_w32_close_81_base
{
public:
    /* pure virtual function */
    virtual void action(FILE * data) const = 0;
};

#ifndef OMITCASE0

class CWE404_Improper_Resource_Shutdown__freopen_w32_close_81_case0 : public CWE404_Improper_Resource_Shutdown__freopen_w32_close_81_base
{
public:
    void action(FILE * data) const;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE404_Improper_Resource_Shutdown__freopen_w32_close_81_case1V2 : public CWE404_Improper_Resource_Shutdown__freopen_w32_close_81_base
{
public:
    void action(FILE * data) const;
};

#endif /* OMITCASE1 */

}
