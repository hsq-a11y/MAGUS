/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__fopen_w32_close_81_case0.cpp
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-81_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source: fopen Open a file using fopen()
 * Sinks: w32_close
 *    Case1Sink: Close the file using fclose()
 *    Case0Sink : Close the file using close()
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE404_Improper_Resource_Shutdown__fopen_w32_close_81.h"

namespace CWE404_Improper_Resource_Shutdown__fopen_w32_close_81
{

void CWE404_Improper_Resource_Shutdown__fopen_w32_close_81_case0::action(FILE * data) const
{
    if (data != NULL)
    {
        /* NOTE: Attempt to close the file using close() instead of fclose() */
        _close((int)data);
    }
}

}
#endif /* OMITCASE0 */
