/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__open_fclose_82_case1V2.cpp
Label Definition File: CWE404_Improper_Resource_Shutdown__open.label.xml
Template File: source-sinks-82_case1V2.tmpl.cpp
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source:  Open a file using open()
 * Sinks: fclose
 *    Case1Sink: Close the file using close()
 *    Case0Sink : Close the file using fclose()
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE404_Improper_Resource_Shutdown__open_fclose_82.h"

namespace CWE404_Improper_Resource_Shutdown__open_fclose_82
{

void CWE404_Improper_Resource_Shutdown__open_fclose_82_case1V2::action(int data)
{
    if (data != -1)
    {
        /* ALT: Close the file using close() */
        CLOSE(data);
    }
}

}
#endif /* OMITCASE1 */
