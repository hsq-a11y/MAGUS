/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__fopen_62b.cpp
Label Definition File: CWE675_Duplicate_Operations_on_Resource.label.xml
Template File: sources-sinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * Case0Source: fopen Open and close a file using fopen() and flose()
 * Case1Source: Open a file using fopen()
 * Sinks:
 *    Case1Sink: Do nothing
 *    Case0Sink : Close the file
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE675_Duplicate_Operations_on_Resource__fopen_62
{

#ifndef OMITCASE0

void case0Source(FILE * &data)
{
    data = fopen("Case0Source_fopen.txt", "w+");
    /* NOTE: Close the file in the source */
    fclose(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
void case1V1Source(FILE * &data)
{
    /* ALT: Open, but do not close the file in the source */
    data = fopen("Case1Source_fopen.txt", "w+");
}

/* case1V2() uses the Case0Source with the Case1Sink */
void case1V2Source(FILE * &data)
{
    data = fopen("Case0Source_fopen.txt", "w+");
    /* NOTE: Close the file in the source */
    fclose(data);
}

#endif /* OMITCASE1 */

} /* close namespace */
