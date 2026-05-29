/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_81.h
Label Definition File: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen.label.xml
Template File: source-sinks-81.tmpl.h
*/
/*
 * @description
 * CWE: 773 Missing Reference to Active File Descriptor or Handle
 * Case0Source:  Create a file handle using fopen()
 * Sinks:
 *    Case1Sink: Close the file handle before reusing it
 *    Case0Sink : Reassign the file handle before closing it
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"

namespace CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_81
{

class CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_81_base
{
public:
    /* pure virtual function */
    virtual void action(FILE * data) const = 0;
};

#ifndef OMITCASE0

class CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_81_case0 : public CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_81_base
{
public:
    void action(FILE * data) const;
};

#endif /* OMITCASE0 */

#ifndef OMITCASE1

class CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_81_case1V2 : public CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_81_base
{
public:
    void action(FILE * data) const;
};

#endif /* OMITCASE1 */

}
