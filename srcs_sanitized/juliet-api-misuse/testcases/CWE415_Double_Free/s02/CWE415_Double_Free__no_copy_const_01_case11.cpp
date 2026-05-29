/*
 * @description Double Free
 * 
 * */

#include "std_testcase.h"

namespace CWE415_Double_Free__no_copy_const_01
{

#ifndef OMITCASE1

class Case1Class 
{
    public:
        Case1Class(const char *data)
        {
            if (data) 
            {
                this->data = new char[strlen(data) + 1];
                strcpy(this->data, data);
            } 
            else 
            {
                this->data = new char[1];
                *(this->data) = '\0';
            }
        }

        ~Case1Class()
        {
            delete [] data;
        }

        void printData()
        {
            printLine(data);
        }

        Case1Class(Case1Class &case1ClassObject)
        { 
            this->data = new char[strlen(case1ClassObject.data) + 1];
            strcpy(this->data, case1ClassObject.data);
        }

        Case1Class& operator=(const Case1Class &case1ClassObject) 
        { 
            if (&case1ClassObject != this) 
            { 
                this->data = new char[strlen(case1ClassObject.data) + 1];
                strcpy(this->data, case1ClassObject.data); 
            } 
            return *this; 
        }

    private:
        char *data;
};

static void case11()
{
    Case1Class case1ClassObject("One");

    /* ALT: There is a copy constructor defined in the class */
    Case1Class case1ClassObjectCopy(case1ClassObject);

    case1ClassObjectCopy.printData();
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

using namespace CWE415_Double_Free__no_copy_const_01; /* so that we can use case1 and case0 easily */

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
