/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_82.h
Label Definition File: CWE404_Improper_Resource_Shutdown__w32CreateFile.label.xml
Template File: source-sinks-82.tmpl.h
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source:  Open a file using CreateFile()
 * Sinks: fclose
 *    Case1Sink: Close the file using CloseHandle()
 *    Case0Sink : Close the file using fclose()
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"

#include <windows.h>

namespace CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_82
{

class CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_82_base
{
public:
    /* pure virtual function */
    virtual void action(HANDLE data) = 0;
};

#ifndef OMITCASE0

class CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_82_case0 : public CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_82_base
{
public:
    void action(HANDLE data);
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_82_case1V2 : public CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_82_base
{
public:
    void action(HANDLE data);
};

#endif /* OMITCASE1 */

}
