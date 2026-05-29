/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__w32CreateFile_81.h
Label Definition File: CWE675_Duplicate_Operations_on_Resource__w32CreateFile.label.xml
Template File: sources-sinks-81.tmpl.h
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * Case0Source:  Open and close a file using CreateFile() and CloseHandle()
 * Case1Source: Open a file using CreateFile()
 * Sinks:
 *    Case1Sink: Do nothing
 *    Case0Sink : Close the file
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"

#include <windows.h>

namespace CWE675_Duplicate_Operations_on_Resource__w32CreateFile_81
{

class CWE675_Duplicate_Operations_on_Resource__w32CreateFile_81_base
{
public:
    /* pure virtual function */
    virtual void action(HANDLE data) const = 0;
};

#ifndef OMITCASE0

class CWE675_Duplicate_Operations_on_Resource__w32CreateFile_81_case0 : public CWE675_Duplicate_Operations_on_Resource__w32CreateFile_81_base
{
public:
    void action(HANDLE data) const;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE675_Duplicate_Operations_on_Resource__w32CreateFile_81_case1V1 : public CWE675_Duplicate_Operations_on_Resource__w32CreateFile_81_base
{
public:
    void action(HANDLE data) const;
};

class CWE675_Duplicate_Operations_on_Resource__w32CreateFile_81_case1V2 : public CWE675_Duplicate_Operations_on_Resource__w32CreateFile_81_base
{
public:
    void action(HANDLE data) const;
};

#endif /* OMITCASE1 */

}
