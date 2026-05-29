/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__open_84.h
Label Definition File: CWE675_Duplicate_Operations_on_Resource__open.label.xml
Template File: sources-sinks-84.tmpl.h
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * Case0Source:  Open and close a file using open() and close()
 * Case1Source: Open a file using open()
 * Sinks:
 *    Case1Sink: Do nothing
 *    Case0Sink : Close the file
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
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

namespace CWE675_Duplicate_Operations_on_Resource__open_84
{

#ifndef OMITCASE0

class CWE675_Duplicate_Operations_on_Resource__open_84_case0
{
public:
    CWE675_Duplicate_Operations_on_Resource__open_84_case0(int dataCopy);
    ~CWE675_Duplicate_Operations_on_Resource__open_84_case0();

private:
    int data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE675_Duplicate_Operations_on_Resource__open_84_case1V1
{
public:
    CWE675_Duplicate_Operations_on_Resource__open_84_case1V1(int dataCopy);
    ~CWE675_Duplicate_Operations_on_Resource__open_84_case1V1();

private:
    int data;
};

class CWE675_Duplicate_Operations_on_Resource__open_84_case1V2
{
public:
    CWE675_Duplicate_Operations_on_Resource__open_84_case1V2(int dataCopy);
    ~CWE675_Duplicate_Operations_on_Resource__open_84_case1V2();

private:
    int data;
};

#endif /* OMITCASE1 */

}
