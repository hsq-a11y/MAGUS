/*
 * @description Memory Leak
 * 
 * */

#include "std_testcase.h"

namespace CWE401_Memory_Leak__virtual_destructor_01
{

#ifndef OMITCASE1

class Case1BaseClass
{
    public:
        Case1BaseClass()
        { 
            printLine("Constructor: Case1BaseClass");
        }
        
        /* ALT: Use a virtual destructor in the base class */
        virtual ~Case1BaseClass()
        {
            printLine("Destructor : Case1BaseClass");
        }
};

class Case1DerivedClass: public Case1BaseClass
{
    public:
        Case1DerivedClass(const char * name)
        { 
            printLine("Constructor: Case1DerivedClass");
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
        
        ~Case1DerivedClass()
        { 
            printLine("Destructor : Case1DerivedClass");
            delete [] name;
        }

        /* copy constructor is only here to avoid double free incidentals */
        Case1DerivedClass(Case1DerivedClass &derivedClassObject)
        { 
            this->name = new char[strlen(derivedClassObject.name) + 1];
            strcpy(this->name, derivedClassObject.name);
        }

        /* operator= is only here to avoid double free incidentals */
        Case1DerivedClass& operator=(const Case1DerivedClass &derivedClassObject)
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

static void case11()
{
    Case1BaseClass * baseClassObject = new Case1DerivedClass("Case1Class");

    delete baseClassObject;
}

void case1()
{
    case11();
}

#endif /* OMITCASE1 */

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
#ifndef OMITCASE1
    printLine("Calling case1()...");
    case1();
    printLine("Finished case1()");
#endif /* OMITCASE1 */
    return 0;
}

#endif
