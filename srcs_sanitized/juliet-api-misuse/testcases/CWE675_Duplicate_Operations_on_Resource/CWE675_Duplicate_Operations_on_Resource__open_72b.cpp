/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__open_72b.cpp
Label Definition File: CWE675_Duplicate_Operations_on_Resource__open.label.xml
Template File: sources-sinks-72b.tmpl.cpp
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * Case0Source:  Open and close a file using open() and close()
 * Case1Source: Open a file using open()
 * Sinks:
 *    Case1Sink: Do nothing
 *    Case0Sink : Close the file
 * Flow Variant: 72 Data flow: data passed in a vector from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <vector>

#ifdef _WIN32
# define OPEN _open
# define CLOSE _close
#else
#include <unistd.h>
# define OPEN open
# define CLOSE close
#endif

using namespace std;

namespace CWE675_Duplicate_Operations_on_Resource__open_72
{

#ifndef OMITCASE0

void case0Sink(vector<int> dataVector)
{
    /* copy data out of dataVector */
    int data = dataVector[2];
    /* NOTE: Close the file in the sink (it may have been closed in the Source) */
    CLOSE(data);
}

#endif /* OMITCASE0 */

#ifndef OMITCASE1

/* case1V1 uses the Case1Source with the Case0Sink */
void case1V1Sink(vector<int> dataVector)
{
    int data = dataVector[2];
    /* NOTE: Close the file in the sink (it may have been closed in the Source) */
    CLOSE(data);
}

/* case1V2 uses the Case0Source with the Case1Sink */
void case1V2Sink(vector<int> dataVector)
{
    int data = dataVector[2];
    /* Do nothing */
    /* ALT: Don't close the file in the sink */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITCASE1 */

} /* close namespace */
