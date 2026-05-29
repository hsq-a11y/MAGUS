/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__w32_wfopen_74b.cpp
Label Definition File: CWE690_NULL_Deref_From_Return.fclose.label.xml
Template File: source-sinks-74b.tmpl.cpp
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: w32_wfopen Open data with wfopen()
 * Sinks: 0
 *    Case1Sink: Check data for NULL
 *    Case0Sink : Do not check data for NULL
 * Flow Variant: 74 Data flow: data passed in a map from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <map>

using namespace std;

namespace CWE690_NULL_Deref_From_Return__w32_wfopen_74
{

#ifndef OMITCASE0

void case0Sink(map<int, FILE *> dataMap)
{
    /* copy data out of dataMap */
    FILE * data = dataMap[2];
    /* NOTE: if the fopen failed, data will be NULL here */
    fclose(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Sink(map<int, FILE *> dataMap)
{
    FILE * data = dataMap[2];
    /* ALT: check the return value */
    if (data != NULL)
    {
        fclose(data);
    }
}

#endif /* OMITCASE1 */

} /* close namespace */
