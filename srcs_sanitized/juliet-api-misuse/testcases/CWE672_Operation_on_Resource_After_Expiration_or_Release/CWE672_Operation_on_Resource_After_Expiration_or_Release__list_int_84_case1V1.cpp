/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_84_case1V1.cpp
Label Definition File: CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int.label.xml
Template File: sources-sinks-84_case1V1.tmpl.cpp
*/
/*
 * @description
 * CWE: 672 Operation on Resource After Expiration or Release
 * Case0Source:  Add values to the list, including the number zero
 * Case1Source: Add value to the list that are not zero
 * Sinks:
 *    Case1Sink: Iterate through the list without attempting to clear its contents
 *    Case0Sink : Iterate through the list, but clear the list if it contains a zero
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITCASE1

#include "std_testcase.h"
#include "CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_84.h"

namespace CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_84
{
CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_84_case1V1::CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_84_case1V1(list<int>  dataCopy)
{
    data = dataCopy;
    /* ALT: Insert non-zero values into the list */
    data.push_back(100);
    data.push_back(200);
}

CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_84_case1V1::~CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_84_case1V1()
{
    {
        list<int> ::iterator i;
        cout << "The list contains: ";
        for( i = data.begin(); i != data.end(); i++)
        {
            if (!*i)
            {
                data.clear();
            }
            /* NOTE: Dereference the iterator, which may be invalid if data is cleared */
            cout << " " << *i;
        }
        cout << endl;
    }
}
}
#endif /* OMITCASE1 */
