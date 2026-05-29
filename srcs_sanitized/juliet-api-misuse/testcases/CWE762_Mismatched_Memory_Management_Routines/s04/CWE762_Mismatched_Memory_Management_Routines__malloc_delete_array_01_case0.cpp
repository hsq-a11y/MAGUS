/*
 * @description Mismatched Memory Management Routines
 * 
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__malloc_delete_array_01
{

#ifndef OMITCASE0

class Case0Class 
{
    public:
        Case0Class(char * name)
        {
            this->name = (char *)malloc(strlen(name)+1);
            if (this->name == NULL) {exit(-1);}
            strcpy(this->name, name);
        }

        ~Case0Class()
        {
            /* NOTE: Using delete [] to deallocate memory allocated with malloc() */
            delete [] name;
        }

        /* copy constructor is only here to avoid double free incidentals */
        Case0Class(Case0Class &case0ClassObject)
        { 
            this->name = (char *)malloc(strlen(case0ClassObject.name)+1);
            if (this->name == NULL) {exit(-1);}
            strcpy(this->name, case0ClassObject.name);
        }

        /* operator= is only here to avoid double free incidentals */
        Case0Class& operator=(const Case0Class &case0ClassObject) 
        { 
            if (&case0ClassObject != this) 
            { 
                this->name = (char *)malloc(strlen(case0ClassObject.name)+1);
                if (this->name == NULL) {exit(-1);}
                strcpy(this->name, case0ClassObject.name);
            } 
            return *this; 
        }

        void printName()
        {
            printLine(name);
        }

    private:
        char * name;
};

void case0()
{
    Case0Class case0ClassObject ("Case0Class");
    case0ClassObject.printName();
}

#endif /* OMITCASE0 */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on 
 * its own for testing or for building a binary to use in testing binary 
 * analysis tools. It is not used when compiling all the testcases as one 
 * application, which is how source code analysis tools are tested. 
 */ 

#ifdef INCLUDEMAIN

using namespace CWE762_Mismatched_Memory_Management_Routines__malloc_delete_array_01; /* so that we can use case1 and case0 easily */

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
