/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_83.h
Label Definition File: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open.label.xml
Template File: source-sinks-83.tmpl.h
*/
/*
 * @description
 * CWE: 773 Missing Reference to Active File Descriptor or Handle
 * Case0Source:  Create a file descriptor using open()
 * Sinks:
 *    Case1Sink: Close the file before reusing the file descriptor
 *    Case0Sink : Reassign the file descriptor before closing the file
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define OPEN _open
#define CLOSE _close
#else
#include <unistd.h>
#define OPEN open
#define CLOSE close
#endif

namespace CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_83
{

#ifndef OMITCASE0

class CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_83_case0
{
public:
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_83_case0(int dataCopy);
    ~CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_83_case0();

private:
    int data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_83_case1V2
{
public:
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_83_case1V2(int dataCopy);
    ~CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_83_case1V2();

private:
    int data;
};

#endif /* OMITCASE1 */

}
