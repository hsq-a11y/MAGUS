/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_83.h
Label Definition File: CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int.label.xml
Template File: sources-sinks-83.tmpl.h
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

#include "std_testcase.h"

#include <wchar.h>
#include <list>
#include <iostream>

using namespace std;

namespace CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_83
{

#ifndef OMITCASE0

class CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_83_case0
{
public:
    CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_83_case0(list<int>  dataCopy);
    ~CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_83_case0();

private:
    list<int>  data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_83_case1V1
{
public:
    CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_83_case1V1(list<int>  dataCopy);
    ~CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_83_case1V1();

private:
    list<int>  data;
};

class CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_83_case1V2
{
public:
    CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_83_case1V2(list<int>  dataCopy);
    ~CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_83_case1V2();

private:
    list<int>  data;
};

#endif /* OMITCASE1 */

}
