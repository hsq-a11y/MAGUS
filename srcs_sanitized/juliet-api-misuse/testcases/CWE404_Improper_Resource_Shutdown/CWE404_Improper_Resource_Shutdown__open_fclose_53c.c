/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__open_fclose_53c.c
Label Definition File: CWE404_Improper_Resource_Shutdown__open.label.xml
Template File: source-sinks-53c.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source:  Open a file using open()
 * Sinks: fclose
 *    Case1Sink: Close the file using close()
 *    Case0Sink : Close the file using fclose()
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
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

#ifndef OMITCASE0

/* case0 function declaration */
void CWE404_Improper_Resource_Shutdown__open_fclose_53d_case0Sink(int data);

void CWE404_Improper_Resource_Shutdown__open_fclose_53c_case0Sink(int data)
{
    CWE404_Improper_Resource_Shutdown__open_fclose_53d_case0Sink(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void CWE404_Improper_Resource_Shutdown__open_fclose_53d_case1V2Sink(int data);

void CWE404_Improper_Resource_Shutdown__open_fclose_53c_case1V2Sink(int data)
{
    CWE404_Improper_Resource_Shutdown__open_fclose_53d_case1V2Sink(data);
}

#endif /* OMITCASE1 */
