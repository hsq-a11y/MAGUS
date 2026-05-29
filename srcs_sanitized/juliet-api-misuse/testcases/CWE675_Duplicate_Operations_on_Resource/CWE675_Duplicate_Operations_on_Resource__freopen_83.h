/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__freopen_83.h
Label Definition File: CWE675_Duplicate_Operations_on_Resource.label.xml
Template File: sources-sinks-83.tmpl.h
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * Case0Source: freopen Open and close a file using freopen() and flose()
 * Case1Source: Open a file using fopen()
 * Sinks:
 *    Case1Sink: Do nothing
 *    Case0Sink : Close the file
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"

namespace CWE675_Duplicate_Operations_on_Resource__freopen_83
{

#ifndef OMITCASE0

class CWE675_Duplicate_Operations_on_Resource__freopen_83_case0
{
public:
    CWE675_Duplicate_Operations_on_Resource__freopen_83_case0(FILE * dataCopy);
    ~CWE675_Duplicate_Operations_on_Resource__freopen_83_case0();

private:
    FILE * data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE675_Duplicate_Operations_on_Resource__freopen_83_case1V1
{
public:
    CWE675_Duplicate_Operations_on_Resource__freopen_83_case1V1(FILE * dataCopy);
    ~CWE675_Duplicate_Operations_on_Resource__freopen_83_case1V1();

private:
    FILE * data;
};

class CWE675_Duplicate_Operations_on_Resource__freopen_83_case1V2
{
public:
    CWE675_Duplicate_Operations_on_Resource__freopen_83_case1V2(FILE * dataCopy);
    ~CWE675_Duplicate_Operations_on_Resource__freopen_83_case1V2();

private:
    FILE * data;
};

#endif /* OMITCASE1 */

}
