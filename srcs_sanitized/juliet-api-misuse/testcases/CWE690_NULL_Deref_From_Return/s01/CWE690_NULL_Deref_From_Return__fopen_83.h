/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__fopen_83.h
Label Definition File: CWE690_NULL_Deref_From_Return.fclose.label.xml
Template File: source-sinks-83.tmpl.h
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: fopen Open data with fopen()
 * Sinks: 0
 *    Case1Sink: Check data for NULL
 *    Case0Sink : Do not check data for NULL
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"

namespace CWE690_NULL_Deref_From_Return__fopen_83
{

#ifndef OMITCASE0

class CWE690_NULL_Deref_From_Return__fopen_83_case0
{
public:
    CWE690_NULL_Deref_From_Return__fopen_83_case0(FILE * dataCopy);
    ~CWE690_NULL_Deref_From_Return__fopen_83_case0();

private:
    FILE * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE690_NULL_Deref_From_Return__fopen_83_case1V2
{
public:
    CWE690_NULL_Deref_From_Return__fopen_83_case1V2(FILE * dataCopy);
    ~CWE690_NULL_Deref_From_Return__fopen_83_case1V2();

private:
    FILE * data;
};

#endif /* OMITCASE1 */

}
