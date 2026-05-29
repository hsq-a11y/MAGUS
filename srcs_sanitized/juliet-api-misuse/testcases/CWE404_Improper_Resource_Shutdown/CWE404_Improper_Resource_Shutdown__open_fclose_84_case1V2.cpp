/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__open_fclose_84_case1V2.cpp
Label Definition File: CWE404_Improper_Resource_Shutdown__open.label.xml
Template File: source-sinks-84_case1V2.tmpl.cpp
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source:  Open a file using open()
 * Sinks: fclose
 *    Case1Sink: Close the file using close()
 *    Case0Sink : Close the file using fclose()
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE404_Improper_Resource_Shutdown__open_fclose_84.h"

namespace CWE404_Improper_Resource_Shutdown__open_fclose_84
{
CWE404_Improper_Resource_Shutdown__open_fclose_84_case1V2::CWE404_Improper_Resource_Shutdown__open_fclose_84_case1V2(int dataCopy)
{
    data = dataCopy;
    /* NOTE: Open a file - need to make sure it is closed properly in the sink */
    data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
}

CWE404_Improper_Resource_Shutdown__open_fclose_84_case1V2::~CWE404_Improper_Resource_Shutdown__open_fclose_84_case1V2()
{
    if (data != -1)
    {
        /* ALT: Close the file using close() */
        CLOSE(data);
    }
}
}
#endif /* OMITCASE1 */
