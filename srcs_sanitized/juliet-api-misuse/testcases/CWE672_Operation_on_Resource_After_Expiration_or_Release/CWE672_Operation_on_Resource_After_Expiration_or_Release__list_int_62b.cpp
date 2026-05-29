/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_62b.cpp
Label Definition File: CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int.label.xml
Template File: sources-sinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 672 Operation on Resource After Expiration or Release
 * Case0Source:  Add values to the list, including the number zero
 * Case1Source: Add value to the list that are not zero
 * Sinks:
 *    Case1Sink: Iterate through the list without attempting to clear its contents
 *    Case0Sink : Iterate through the list, but clear the list if it contains a zero
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#include <list>
#include <iostream>

using namespace std;

namespace CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_62
{

#ifndef OMITCASE0

void case0Source(list<int>  &data)
{
    /* NOTE: Insert a zero into the list */
    data.push_back(100);
    data.push_back(0);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1() uses the Case1Source with the Case0Sink */
void case1V1Source(list<int>  &data)
{
    /* ALT: Insert non-zero values into the list */
    data.push_back(100);
    data.push_back(200);
}

/* case1V2() uses the Case0Source with the Case1Sink */
void case1V2Source(list<int>  &data)
{
    /* NOTE: Insert a zero into the list */
    data.push_back(100);
    data.push_back(0);
}

#endif /* OMITCASE1 */

} /* close namespace */
