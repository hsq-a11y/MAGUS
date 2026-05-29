/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_char_relativePath_62b.cpp
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 114 Process Control
 * Case0Source: relativePath Hard code the relative pathname to the library
 * Case1Source: Hard code the full pathname to the library
 * Sinks:
 *    Case0Sink : Load a dynamic link library
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE114_Process_Control__w32_char_relativePath_62
{

#ifndef OMITCASE0

void case0Source(char * &data)
{
    /* NOTE: Specify just the file name for the library, not the full path */
    strcpy(data, "winsrv.dll");
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
void case1V1Source(char * &data)
{
    /* ALT: Specify the full pathname for the library */
    strcpy(data, "C:\\Windows\\System32\\winsrv.dll");
}

#endif /* OMITCASE1 */

} /* close namespace */
