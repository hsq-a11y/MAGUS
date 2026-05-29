/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__fopen_w32_close_62b.cpp
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source: fopen Open a file using fopen()
 * Sinks: w32_close
 *    Case1Sink: Close the file using fclose()
 *    Case0Sink : Close the file using close()
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE404_Improper_Resource_Shutdown__fopen_w32_close_62
{

#ifndef OMITCASE0

void case0Source(FILE * &data)
{
    /* NOTE: Open a file - need to make sure it is closed properly in the sink */
    data = fopen("Case0Source_fopen.txt", "w+");
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2() uses the Case0Source with the Case1Sink */
void case1V2Source(FILE * &data)
{
    /* NOTE: Open a file - need to make sure it is closed properly in the sink */
    data = fopen("Case0Source_fopen.txt", "w+");
}

#endif /* OMITCASE1 */

} /* close namespace */
