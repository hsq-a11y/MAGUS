/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_84.h
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close.label.xml
Template File: source-sinks-84.tmpl.h
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * Case0Source:  Open a file using open()
 * Sinks:
 *    Case1Sink: Close the file using close()
 *    Case0Sink : Do not close file
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
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

namespace CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_84
{

#ifndef OMITCASE0

class CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_84_case0
{
public:
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_84_case0(int dataCopy);
    ~CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_84_case0();

private:
    int data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_84_case1V2
{
public:
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_84_case1V2(int dataCopy);
    ~CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_84_case1V2();

private:
    int data;
};

#endif /* OMITCASE1 */

}
