/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__w32_wfopen_73b.cpp
Label Definition File: CWE690_NULL_Deref_From_Return.fclose.label.xml
Template File: source-sinks-73b.tmpl.cpp
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: w32_wfopen Open data with wfopen()
 * Sinks: 0
 *    Case1Sink: Check data for NULL
 *    Case0Sink : Do not check data for NULL
 * Flow Variant: 73 Data flow: data passed in a list from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <list>

using namespace std;

namespace CWE690_NULL_Deref_From_Return__w32_wfopen_73
{

#ifndef OMITCASE0

void case0Sink(list<FILE *> dataList)
{
    /* copy data out of dataList */
    FILE * data = dataList.back();
    /* NOTE: if the fopen failed, data will be NULL here */
    fclose(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Sink(list<FILE *> dataList)
{
    FILE * data = dataList.back();
    /* ALT: check the return value */
    if (data != NULL)
    {
        fclose(data);
    }
}

#endif /* OMITCASE1 */

} /* close namespace */
