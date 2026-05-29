/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_83_case0.cpp
Label Definition File: CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int.label.xml
Template File: sources-sinks-83_case0.tmpl.cpp
*/
/*
 * @description
 * CWE: 672 Operation on Resource After Expiration or Release
 * Case0Source:  Add values to the list, including the number zero
 * Case1Source: Add value to the list that are not zero
 * Sinks:
 *    Case1Sink: Iterate through the list without attempting to clear its contents
 *    Case0Sink : Iterate through the list, but clear the list if it contains a zero
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITCASE0

#include "std_testcase.h"
#include "CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_83.h"

namespace CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_83
{
CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_83_case0::CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_83_case0(list<int>  dataCopy)
{
    data = dataCopy;
    /* NOTE: Insert a zero into the list */
    data.push_back(100);
    data.push_back(0);
}

CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_83_case0::~CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_83_case0()
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
#endif /* OMITCASE0 */
