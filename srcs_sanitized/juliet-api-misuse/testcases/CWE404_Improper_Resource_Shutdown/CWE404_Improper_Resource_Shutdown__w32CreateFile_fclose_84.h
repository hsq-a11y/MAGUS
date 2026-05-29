/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_84.h
Label Definition File: CWE404_Improper_Resource_Shutdown__w32CreateFile.label.xml
Template File: source-sinks-84.tmpl.h
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source:  Open a file using CreateFile()
 * Sinks: fclose
 *    Case1Sink: Close the file using CloseHandle()
 *    Case0Sink : Close the file using fclose()
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"

#include <windows.h>

namespace CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_84
{

#ifndef OMITCASE0

class CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_84_case0
{
public:
    CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_84_case0(HANDLE dataCopy);
    ~CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_84_case0();

private:
    HANDLE data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_84_case1V2
{
public:
    CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_84_case1V2(HANDLE dataCopy);
    ~CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_84_case1V2();

private:
    HANDLE data;
};

#endif /* OMITCASE1 */

}
