/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_54c.cpp
Label Definition File: CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int.label.xml
Template File: sources-sinks-54c.tmpl.cpp
*/
/*
 * @description
 * CWE: 672 Operation on Resource After Expiration or Release
 * Case0Source:  Add values to the list, including the number zero
 * Case1Source: Add value to the list that are not zero
 * Sinks:
 *    Case1Sink: Iterate through the list without attempting to clear its contents
 *    Case0Sink : Iterate through the list, but clear the list if it contains a zero
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#include <list>
#include <iostream>

using namespace std;

namespace CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_54
{

#ifndef OMITCASE0

/* case0 function declaration */
void case0Sink_d(list<int>  data);

void case0Sink_c(list<int>  data)
{
    case0Sink_d(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink_d(list<int>  data);

void case1V1Sink_c(list<int>  data)
{
    case1V1Sink_d(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Sink_d(list<int>  data);

void case1V2Sink_c(list<int>  data)
{
    case1V2Sink_d(data);
}

#endif /* OMITCASE1 */

} /* close namespace */
