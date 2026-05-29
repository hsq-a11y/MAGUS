/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__open_fclose_84.h
Label Definition File: CWE404_Improper_Resource_Shutdown__open.label.xml
Template File: source-sinks-84.tmpl.h
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source:  Open a file using open()
 * Sinks: fclose
 *    Case1Sink: Close the file using close()
 *    Case0Sink : Close the file using fclose()
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define OPEN _open
#define CLOSE _close
#else
#include <unistd.h>
#define OPEN open
#define CLOSE close
#endif

namespace CWE404_Improper_Resource_Shutdown__open_fclose_84
{

#ifndef OMITCASE0

class CWE404_Improper_Resource_Shutdown__open_fclose_84_case0
{
public:
    CWE404_Improper_Resource_Shutdown__open_fclose_84_case0(int dataCopy);
    ~CWE404_Improper_Resource_Shutdown__open_fclose_84_case0();

private:
    int data;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE404_Improper_Resource_Shutdown__open_fclose_84_case1V2
{
public:
    CWE404_Improper_Resource_Shutdown__open_fclose_84_case1V2(int dataCopy);
    ~CWE404_Improper_Resource_Shutdown__open_fclose_84_case1V2();

private:
    int data;
};

#endif /* OMITCASE1 */

}
