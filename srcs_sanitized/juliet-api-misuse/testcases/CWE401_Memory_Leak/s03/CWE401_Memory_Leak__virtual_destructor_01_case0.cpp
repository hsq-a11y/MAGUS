/*
 * @description Memory Leak
 * 
 * */

#include "std_testcase.h"

namespace CWE401_Memory_Leak__virtual_destructor_01
{

#ifndef OMITCASE0

class Case0BaseClass
{
    public:
        Case0BaseClass()
        { 
            printLine("Constructor: Case0BaseClass");
        }
        
        /* NOTE: Non-virtual destructor - the destructor of the 
         * derived class will not be called */
        ~Case0BaseClass()
        { 
            printLine("Destructor : Case0BaseClass");
        }
};

class Case0DerivedClass: public Case0BaseClass
{
    public:
        Case0DerivedClass(const char * name)
        {
            printLine("Constructor: Case0DerivedClass");
            if (name)
            {
                this->name = new char[strlen(name) + 1];
                strcpy(this->name, name);
                printLine(this->name);
            }
            else
            {
                this->name = new char[1];
                *(this->name) = '\0';
            }
        }
        
        ~Case0DerivedClass()
        {
            /* This should never be executed */
            printLine("Destructor : Case0DerivedClass");
            delete [] name;
        }

        /* copy constructor is only here to avoid double free incidentals */
        Case0DerivedClass(Case0DerivedClass &derivedClassObject)
        { 
            this->name = new char[strlen(derivedClassObject.name) + 1];
            strcpy(this->name, derivedClassObject.name);
        }

        /* operator= is only here to avoid double free incidentals */
        Case0DerivedClass& operator=(const Case0DerivedClass &derivedClassObject)
        { 
            if (&derivedClassObject != this) 
            { 
                this->name = new char[strlen(derivedClassObject.name) + 1];
                strcpy(this->name, derivedClassObject.name);
            } 
            return *this; 
        }

    private:
        char * name;
};

void case0()
{
    Case0BaseClass * baseClassObject = new Case0DerivedClass("Case0Class");

    delete baseClassObject;
}

#endif /* OMITCASE0 */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on 
 * its own for testing or for building a binary to use in testing binary 
 * analysis tools. It is not used when compiling all the testcases as one 
 * application, which is how source code analysis tools are tested. 
 */ 

#ifdef INCLUDEMAIN

using namespace CWE401_Memory_Leak__virtual_destructor_01; /* so that we can use case1 and case0 easily */

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
