/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__w32_wfopen_83_case1V2.cpp
Label Definition File: CWE690_NULL_Deref_From_Return.fclose.label.xml
Template File: source-sinks-83_case1V2.tmpl.cpp
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: w32_wfopen Open data with wfopen()
 * Sinks: 0
 *    Case1Sink: Check data for NULL
 *    Case0Sink : Do not check data for NULL
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE690_NULL_Deref_From_Return__w32_wfopen_83.h"

namespace CWE690_NULL_Deref_From_Return__w32_wfopen_83
{
CWE690_NULL_Deref_From_Return__w32_wfopen_83_case1V2::CWE690_NULL_Deref_From_Return__w32_wfopen_83_case1V2(FILE * dataCopy)
{
    data = dataCopy;
    /* NOTE: Open a file without checking the return value for NULL */
    data = _wfopen(L"file.txt", L"w+");
}

CWE690_NULL_Deref_From_Return__w32_wfopen_83_case1V2::~CWE690_NULL_Deref_From_Return__w32_wfopen_83_case1V2()
{
    /* ALT: check the return value */
    if (data != NULL)
    {
        fclose(data);
    }
}
}
#endif /* OMITCASE1 */
