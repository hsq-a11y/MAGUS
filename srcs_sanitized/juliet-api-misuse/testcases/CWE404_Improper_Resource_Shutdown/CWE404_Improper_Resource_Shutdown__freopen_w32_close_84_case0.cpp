/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__freopen_w32_close_84_case0.cpp
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-84_case0.tmpl.cpp
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
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE404_Improper_Resource_Shutdown__freopen_w32_close_84.h"

namespace CWE404_Improper_Resource_Shutdown__freopen_w32_close_84
{
CWE404_Improper_Resource_Shutdown__freopen_w32_close_84_case0::CWE404_Improper_Resource_Shutdown__freopen_w32_close_84_case0(FILE * dataCopy)
{
    data = dataCopy;
    /* NOTE: Open a file - need to make sure it is closed properly in the sink */
    data = freopen("Case0Source_freopen.txt","w+",stdin);
}

CWE404_Improper_Resource_Shutdown__freopen_w32_close_84_case0::~CWE404_Improper_Resource_Shutdown__freopen_w32_close_84_case0()
{
    if (data != NULL)
    {
        /* NOTE: Attempt to close the file using close() instead of fclose() */
        _close((int)data);
    }
}
}
#endif /* OMITCASE0 */
