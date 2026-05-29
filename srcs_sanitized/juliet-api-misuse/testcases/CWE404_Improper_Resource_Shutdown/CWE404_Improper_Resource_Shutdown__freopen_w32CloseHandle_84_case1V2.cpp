/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_84_case1V2.cpp
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-84_case1V2.tmpl.cpp
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source: freopen Open a file using freopen()
 * Sinks: w32CloseHandle
 *    Case1Sink: Close the file using fclose()
 *    Case0Sink : Close the file using CloseHandle
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_84.h"

#include <windows.h>

namespace CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_84
{
CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_84_case1V2::CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_84_case1V2(FILE * dataCopy)
{
    data = dataCopy;
    /* NOTE: Open a file - need to make sure it is closed properly in the sink */
    data = freopen("Case0Source_freopen.txt","w+",stdin);
}

CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_84_case1V2::~CWE404_Improper_Resource_Shutdown__freopen_w32CloseHandle_84_case1V2()
{
    if (data != NULL)
    {
        /* ALT: Close the file using fclose() */
        fclose(data);
    }
}
}
#endif /* OMITCASE1 */
