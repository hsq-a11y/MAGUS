/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_83.h
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-83.tmpl.h
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source: fopen Open a file using fopen()
 * Sinks: w32CloseHandle
 *    Case1Sink: Close the file using fclose()
 *    Case0Sink : Close the file using CloseHandle
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"

namespace CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_83
{

#ifndef OMITCASE0

class CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_83_case0
{
public:
    CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_83_case0(FILE * dataCopy);
    ~CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_83_case0();

private:
    FILE * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_83_case1V2
{
public:
    CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_83_case1V2(FILE * dataCopy);
    ~CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_83_case1V2();

private:
    FILE * data;
};

#endif /* OMITCASE1 */

}
