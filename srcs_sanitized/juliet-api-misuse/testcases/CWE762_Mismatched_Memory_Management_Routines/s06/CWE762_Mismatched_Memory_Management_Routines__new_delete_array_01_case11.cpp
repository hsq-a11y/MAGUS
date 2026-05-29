/*
 * @description Mismatched Memory Management Routines
 * 
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_delete_array_01
{

#ifndef OMITCASE1

class Case1Class 
{
    public:    
        Case1Class(char letter)
        {
            this->letter = new char;
            memcpy(this->letter, &letter, sizeof(char));
        }

        ~Case1Class()
        {
            /* ALT: Use delete to deallocate memory allocated with new */
            delete letter;
        }

        /* copy constructor is only here to avoid double free incidentals */
        Case1Class(Case1Class &case1ClassObject)
        { 
            this->letter = new char;
            memcpy(this->letter, case1ClassObject.letter, sizeof(char));
        }

        /* operator= is only here to avoid double free incidentals */
        Case1Class& operator=(const Case1Class &case1ClassObject) 
        { 
            if (&case1ClassObject != this) 
            { 
                this->letter = new char;
                memcpy(this->letter, case1ClassObject.letter, sizeof(char));
            } 
            return *this; 
        }

        void printLetter()
        {
            printf("%c\n", *letter);
        }

    private:
        char * letter;
};

static void case11()
{
    Case1Class case1ClassObject ('G');
    case1ClassObject.printLetter();
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

using namespace CWE762_Mismatched_Memory_Management_Routines__new_delete_array_01; /* so that we can use case1 and case0 easily */

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
