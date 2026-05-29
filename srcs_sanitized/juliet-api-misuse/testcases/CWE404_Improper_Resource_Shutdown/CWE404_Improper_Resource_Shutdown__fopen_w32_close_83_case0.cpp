/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__fopen_w32_close_83_case0.cpp
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-83_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source: fopen Open a file using fopen()
 * Sinks: w32_close
 *    Case1Sink: Close the file using fclose()
 *    Case0Sink : Close the file using close()
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE404_Improper_Resource_Shutdown__fopen_w32_close_83.h"

namespace CWE404_Improper_Resource_Shutdown__fopen_w32_close_83
{
CWE404_Improper_Resource_Shutdown__fopen_w32_close_83_case0::CWE404_Improper_Resource_Shutdown__fopen_w32_close_83_case0(FILE * dataCopy)
{
    data = dataCopy;
    /* NOTE: Open a file - need to make sure it is closed properly in the sink */
    data = fopen("Case0Source_fopen.txt", "w+");
}

CWE404_Improper_Resource_Shutdown__fopen_w32_close_83_case0::~CWE404_Improper_Resource_Shutdown__fopen_w32_close_83_case0()
{
    if (data != NULL)
    {
        /* NOTE: Attempt to close the file using close() instead of fclose() */
        _close((int)data);
    }
}
}
#endif /* OMITCASE0 */
