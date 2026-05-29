/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_81.h
Label Definition File: CWE404_Improper_Resource_Shutdown__open.label.xml
Template File: source-sinks-81.tmpl.h
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * Case0Source:  Open a file using open()
 * Sinks: w32CloseHandle
 *    Case1Sink: Close the file using close()
 *    Case0Sink : Close the file using CloseHandle
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
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

namespace CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_81
{

class CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_81_base
{
public:
    /* pure virtual function */
    virtual void action(int data) const = 0;
};

#ifndef OMITCASE0

class CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_81_case0 : public CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_81_base
{
public:
    void action(int data) const;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_81_case1V2 : public CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_81_base
{
public:
    void action(int data) const;
};

#endif /* OMITCASE1 */

}
