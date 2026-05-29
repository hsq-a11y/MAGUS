/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__fopen_81.h
Label Definition File: CWE690_NULL_Deref_From_Return.fclose.label.xml
Template File: source-sinks-81.tmpl.h
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * Case0Source: fopen Open data with fopen()
 * Sinks: 0
 *    Case1Sink: Check data for NULL
 *    Case0Sink : Do not check data for NULL
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"

namespace CWE690_NULL_Deref_From_Return__fopen_81
{

class CWE690_NULL_Deref_From_Return__fopen_81_base
{
public:
    /* pure virtual function */
    virtual void action(FILE * data) const = 0;
};

#ifndef OMITCASE0

class CWE690_NULL_Deref_From_Return__fopen_81_case0 : public CWE690_NULL_Deref_From_Return__fopen_81_base
{
public:
    void action(FILE * data) const;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE690_NULL_Deref_From_Return__fopen_81_case1V2 : public CWE690_NULL_Deref_From_Return__fopen_81_base
{
public:
    void action(FILE * data) const;
};

#endif /* OMITCASE1 */

}
