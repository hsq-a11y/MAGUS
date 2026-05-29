/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_62b.cpp
Label Definition File: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open.label.xml
Template File: source-sinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 773 Missing Reference to Active File Descriptor or Handle
 * Case0Source:  Create a file descriptor using open()
 * Sinks:
 *    Case1Sink: Close the file before reusing the file descriptor
 *    Case0Sink : Reassign the file descriptor before closing the file
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
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

namespace CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_62
{

#ifndef OMITCASE0

void case0Source(int &data)
{
    /* NOTE: Create a file descriptor using open() that may not be closed properly */
    data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2() uses the Case0Source with the Case1Sink */
void case1V2Source(int &data)
{
    /* NOTE: Create a file descriptor using open() that may not be closed properly */
    data = OPEN("Case0Source_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
}

#endif /* OMITCASE1 */

} /* close namespace */
