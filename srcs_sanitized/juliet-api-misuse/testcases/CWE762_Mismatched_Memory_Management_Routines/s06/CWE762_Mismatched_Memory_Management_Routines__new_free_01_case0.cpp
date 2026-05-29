/*
 * @description Mismatched Memory Management Routines
 * 
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_free_01
{

#ifndef OMITCASE0

class Case0Class 
{
    public:
        Case0Class(char letter)
        {
            this->letter = new char;
            memcpy(this->letter, &letter, sizeof(char));
        }

        ~Case0Class()
        {
            /* NOTE: Using free to deallocate memory allocated with new */
            free(letter);
        }

        /* copy constructor is only here to avoid double free incidentals */
        Case0Class(Case0Class &case0ClassObject)
        { 
            this->letter = new char;
            memcpy(this->letter, case0ClassObject.letter, sizeof(char));
        }

        /* operator= is only here to avoid double free incidentals */
        Case0Class& operator=(const Case0Class &case0ClassObject) 
        { 
            if (&case0ClassObject != this) 
            { 
                this->letter = new char;
                memcpy(this->letter, case0ClassObject.letter, sizeof(char));
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

void case0()
{
    Case0Class case0ClassObject ('B');
    case0ClassObject.printLetter();
}

#endif /* OMITCASE0 */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on 
 * its own for testing or for building a binary to use in testing binary 
 * analysis tools. It is not used when compiling all the testcases as one 
 * application, which is how source code analysis tools are tested. 
 */ 

#ifdef INCLUDEMAIN

using namespace CWE762_Mismatched_Memory_Management_Routines__new_free_01; /* so that we can use case1 and case0 easily */

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
