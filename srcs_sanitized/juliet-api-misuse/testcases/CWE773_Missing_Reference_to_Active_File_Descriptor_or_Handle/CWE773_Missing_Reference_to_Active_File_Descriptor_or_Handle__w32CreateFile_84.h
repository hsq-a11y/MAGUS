/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_84.h
Label Definition File: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile.label.xml
Template File: source-sinks-84.tmpl.h
*/
/*
 * @description
 * CWE: 773 Missing Reference to Active File Descriptor or Handle
 * Case0Source:  Create a file handle using CreateFile()
 * Sinks:
 *    Case1Sink: Close the file handle before reusing it
 *    Case0Sink : Reassign the file handle before closing it
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"

#include <windows.h>

namespace CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_84
{

#ifndef OMITCASE0

class CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_84_case0
{
public:
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_84_case0(HANDLE dataCopy);
    ~CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_84_case0();

private:
    HANDLE data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_84_case1V2
{
public:
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_84_case1V2(HANDLE dataCopy);
    ~CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_84_case1V2();

private:
    HANDLE data;
};

#endif /* OMITCASE1 */

}
