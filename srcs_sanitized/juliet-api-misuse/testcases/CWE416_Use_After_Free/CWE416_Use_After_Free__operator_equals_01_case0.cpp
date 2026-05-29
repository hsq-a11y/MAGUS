/*
 * @description Use After Free
 * 
 * */

#include "std_testcase.h"

namespace CWE416_Use_After_Free__operator_equals_01
{

#ifndef OMITCASE0

class Case0Class 
{
    public:
        Case0Class() 
        {
            name = NULL;
        }
    
        Case0Class(const char * name)
        {
            if (name)
            {
                this->name = new char[strlen(name) + 1];
                strcpy(this->name, name);
            } 
            else 
            {
                this->name = new char[1];
                *(this->name) = '\0';
            }
        }

        ~Case0Class()
        {
            delete [] name;
        }

        /* copy constructor is only here to avoid double free incidentals */
        Case0Class(Case0Class &case0ClassObject)
        { 
            this->name = new char[strlen(case0ClassObject.name)+1]; 
            strcpy(this->name, case0ClassObject.name);
        }
        
        Case0Class& operator=(const Case0Class& case0ClassObject) 
        {
            /* No check for self-assignment */
            delete [] this->name;
            this->name = new char[strlen(case0ClassObject.name)+1]; 
            strcpy(this->name, case0ClassObject.name); /* NOTE - if this is a self-assignment, 
                case0ClassObject.name has already been deleted, so this is a use after free (CWE-416). */
            return *this;
        }
        
        char * name;
};

void case0()
{
    Case0Class case0ClassObject("Case0Class");
    case0ClassObject = case0ClassObject;
    printLine(case0ClassObject.name);
}

#endif /* OMITCASE0 */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on 
 * its own for testing or for building a binary to use in testing binary 
 * analysis tools. It is not used when compiling all the testcases as one 
 * application, which is how source code analysis tools are tested. 
 */ 

#ifdef INCLUDEMAIN

using namespace CWE416_Use_After_Free__operator_equals_01; /* so that we can use case1 and case0 easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITCASE0
    printLine("Calling case0()...");
    case0();
    printLine("Finished case0()");
#endif /* OMITCASE0 */
    return 0;
}

#endif
