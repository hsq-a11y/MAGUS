/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__fopen_82.h
Label Definition File: CWE675_Duplicate_Operations_on_Resource.label.xml
Template File: sources-sinks-82.tmpl.h
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * Case0Source: fopen Open and close a file using fopen() and flose()
 * Case1Source: Open a file using fopen()
 * Sinks:
 *    Case1Sink: Do nothing
 *    Case0Sink : Close the file
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"

namespace CWE675_Duplicate_Operations_on_Resource__fopen_82
{

class CWE675_Duplicate_Operations_on_Resource__fopen_82_base
{
public:
    /* pure virtual function */
    virtual void action(FILE * data) = 0;
};

#ifndef OMITCASE0

class CWE675_Duplicate_Operations_on_Resource__fopen_82_case0 : public CWE675_Duplicate_Operations_on_Resource__fopen_82_base
{
public:
    void action(FILE * data);
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE675_Duplicate_Operations_on_Resource__fopen_82_case1V1 : public CWE675_Duplicate_Operations_on_Resource__fopen_82_base
{
public:
    void action(FILE * data);
};

class CWE675_Duplicate_Operations_on_Resource__fopen_82_case1V2 : public CWE675_Duplicate_Operations_on_Resource__fopen_82_base
{
public:
    void action(FILE * data);
};

#endif /* OMITCASE1 */

}
