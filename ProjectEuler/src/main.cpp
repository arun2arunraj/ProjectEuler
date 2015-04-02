// == Project Euler Problem Solver Framework ==
//
// Any problems?
// - Check ProblemX template as guide to use this framework
// - Good Luck!!
//
// Omer Akyol, 2011 
//

#include <ctime>

#include "problems/Problem25.h"


using std::clock;
using std::clock_t;

using namespace projectEuler;


int main()
{
    cout << "PROJECT EULER PROBLEM SOLVER" << endl;
    cout << "\t(P.E.P.S.)\n" << endl;
    cout << "Solving problem..." << endl;

    // Start clock
    clock_t clockStart = clock();                                   

    // Create problem
    ProblemBase* problem;
    problem = new Problem25();                                      

    // Solve & stop time
    problem->Solve();                                               
    float totalET = (clock() - clockStart) / (float)CLOCKS_PER_SEC;

    // Write out answer
    cout << "Problem solved in: " << totalET << " seconds." << endl;
    cout << "Answer: " << problem->GetAnswer();

    delete problem;
    
    getchar();// console pause
    return 0;
}