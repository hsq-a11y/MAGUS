/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__freopen_w32_close_84.h
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-84.tmpl.h
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source: freopen Open a file using freopen()
 * Sinks: w32_close
 *    Case1Sink: Close the file using fclose()
 *    Case0Sink : Close the file using close()
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"

namespace CWE404_Improper_Resource_Shutdown__freopen_w32_close_84
{

#ifndef OMITCASE0

class CWE404_Improper_Resource_Shutdown__freopen_w32_close_84_case0
{
public:
    CWE404_Improper_Resource_Shutdown__freopen_w32_close_84_case0(FILE * dataCopy);
    ~CWE404_Improper_Resource_Shutdown__freopen_w32_close_84_case0();

private:
    FILE * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE404_Improper_Resource_Shutdown__freopen_w32_close_84_case1V2
{
public:
    CWE404_Improper_Resource_Shutdown__freopen_w32_close_84_case1V2(FILE * dataCopy);
    ~CWE404_Improper_Resource_Shutdown__freopen_w32_close_84_case1V2();

private:
    FILE * data;
};

#endif /* OMITCASE1 */

}
