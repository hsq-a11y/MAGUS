/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__w32CreateFile_83.h
Label Definition File: CWE675_Duplicate_Operations_on_Resource__w32CreateFile.label.xml
Template File: sources-sinks-83.tmpl.h
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * Case0Source:  Open and close a file using CreateFile() and CloseHandle()
 * Case1Source: Open a file using CreateFile()
 * Sinks:
 *    Case1Sink: Do nothing
 *    Case0Sink : Close the file
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"

#include <windows.h>

namespace CWE675_Duplicate_Operations_on_Resource__w32CreateFile_83
{

#ifndef OMITCASE0

class CWE675_Duplicate_Operations_on_Resource__w32CreateFile_83_case0
{
public:
    CWE675_Duplicate_Operations_on_Resource__w32CreateFile_83_case0(HANDLE dataCopy);
    ~CWE675_Duplicate_Operations_on_Resource__w32CreateFile_83_case0();

private:
    HANDLE data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE675_Duplicate_Operations_on_Resource__w32CreateFile_83_case1V1
{
public:
    CWE675_Duplicate_Operations_on_Resource__w32CreateFile_83_case1V1(HANDLE dataCopy);
    ~CWE675_Duplicate_Operations_on_Resource__w32CreateFile_83_case1V1();

private:
    HANDLE data;
};

class CWE675_Duplicate_Operations_on_Resource__w32CreateFile_83_case1V2
{
public:
    CWE675_Duplicate_Operations_on_Resource__w32CreateFile_83_case1V2(HANDLE dataCopy);
    ~CWE675_Duplicate_Operations_on_Resource__w32CreateFile_83_case1V2();

private:
    HANDLE data;
};

#endif /* OMITCASE1 */

}
