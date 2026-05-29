/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__freopen_73b.cpp
Label Definition File: CWE675_Duplicate_Operations_on_Resource.label.xml
Template File: sources-sinks-73b.tmpl.cpp
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * Case0Source: freopen Open and close a file using freopen() and flose()
 * Case1Source: Open a file using fopen()
 * Sinks:
 *    Case1Sink: Do nothing
 *    Case0Sink : Close the file
 * Flow Variant: 73 Data flow: data passed in a list from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <list>

using namespace std;

namespace CWE675_Duplicate_Operations_on_Resource__freopen_73
{

#ifndef OMITCASE0

void case0Sink(list<FILE *> dataList)
{
    /* copy data out of dataList */
    FILE * data = dataList.back();
    /* NOTE: Close the file in the sink (it may have been closed in the Source) */
    fclose(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink(list<FILE *> dataList)
{
    FILE * data = dataList.back();
    /* NOTE: Close the file in the sink (it may have been closed in the Source) */
    fclose(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Sink(list<FILE *> dataList)
{
    FILE * data = dataList.back();
    /* Do nothing */
    /* ALT: Don't close the file in the sink */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITCASE1 */

} /* close namespace */
