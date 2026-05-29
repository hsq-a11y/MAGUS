/*
 * @description Double Free
 * 
 * */

#include "std_testcase.h"

namespace CWE415_Double_Free__no_assignment_op_01
{

#ifndef OMITCASE0

class Case0Class 
{
    public:
        Case0Class(const char *data)
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

        ~Case0Class()
        {
            delete [] data;
        }

        void printData()
        {
            printLine(data);
        }

        Case0Class(Case0Class &case0ClassObject)
        { 
            this->data = new char[strlen(case0ClassObject.data) + 1];
            strcpy(this->data, case0ClassObject.data); 
        }

    private:
        char *data;
};

void case0()
{
    Case0Class case0ClassObject1("One"), case0ClassObject2("Two");

    /* NOTE: There is no assignment operator in the class - this will cause a double free in the destructor */
    case0ClassObject2 = case0ClassObject1;

    case0ClassObject2.printData();
}

#endif /* OMITCASE0 */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on 
 * its own for testing or for building a binary to use in testing binary 
 * analysis tools. It is not used when compiling all the testcases as one 
 * application, which is how source code analysis tools are tested. 
 */ 

#ifdef INCLUDEMAIN

using namespace CWE415_Double_Free__no_assignment_op_01; /* so that we can use case1 and case0 easily */

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
