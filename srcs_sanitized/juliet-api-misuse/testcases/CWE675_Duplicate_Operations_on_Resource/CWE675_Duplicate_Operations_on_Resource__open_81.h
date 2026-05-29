/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__open_81.h
Label Definition File: CWE675_Duplicate_Operations_on_Resource__open.label.xml
Template File: sources-sinks-81.tmpl.h
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * Case0Source:  Open and close a file using open() and close()
 * Case1Source: Open a file using open()
 * Sinks:
 *    Case1Sink: Do nothing
 *    Case0Sink : Close the file
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define OPEN _open
# define CLOSE _close
#else
#include <unistd.h>
# define OPEN open
# define CLOSE close
#endif

namespace CWE675_Duplicate_Operations_on_Resource__open_81
{

class CWE675_Duplicate_Operations_on_Resource__open_81_base
{
public:
    /* pure virtual function */
    virtual void action(int data) const = 0;
};

#ifndef OMITCASE0

class CWE675_Duplicate_Operations_on_Resource__open_81_case0 : public CWE675_Duplicate_Operations_on_Resource__open_81_base
{
public:
    void action(int data) const;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE675_Duplicate_Operations_on_Resource__open_81_case1V1 : public CWE675_Duplicate_Operations_on_Resource__open_81_base
{
public:
    void action(int data) const;
};

class CWE675_Duplicate_Operations_on_Resource__open_81_case1V2 : public CWE675_Duplicate_Operations_on_Resource__open_81_base
{
public:
    void action(int data) const;
};

#endif /* OMITCASE1 */

}
