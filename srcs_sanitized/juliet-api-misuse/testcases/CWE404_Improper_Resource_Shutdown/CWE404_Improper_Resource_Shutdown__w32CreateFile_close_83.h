/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__w32CreateFile_close_83.h
Label Definition File: CWE404_Improper_Resource_Shutdown__w32CreateFile.label.xml
Template File: source-sinks-83.tmpl.h
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source:  Open a file using CreateFile()
 * Sinks: close
 *    Case1Sink: Close the file using CloseHandle()
 *    Case0Sink : Close the file using close()
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"

#include <windows.h>

namespace CWE404_Improper_Resource_Shutdown__w32CreateFile_close_83
{

#ifndef OMITCASE0

class CWE404_Improper_Resource_Shutdown__w32CreateFile_close_83_case0
{
public:
    CWE404_Improper_Resource_Shutdown__w32CreateFile_close_83_case0(HANDLE dataCopy);
    ~CWE404_Improper_Resource_Shutdown__w32CreateFile_close_83_case0();

private:
    HANDLE data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE404_Improper_Resource_Shutdown__w32CreateFile_close_83_case1V2
{
public:
    CWE404_Improper_Resource_Shutdown__w32CreateFile_close_83_case1V2(HANDLE dataCopy);
    ~CWE404_Improper_Resource_Shutdown__w32CreateFile_close_83_case1V2();

private:
    HANDLE data;
};

#endif /* OMITCASE1 */

}
