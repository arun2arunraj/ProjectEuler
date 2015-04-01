#include "Problem20.h"

namespace projectEuler
{

// Constructor
Problem20::Problem20()
{
    
}


// Destructor
Problem20::~Problem20()
{

}


// Solver
void Problem20::Solve()
{
    InfiniteInteger number("100");
    string result = Cebir::Factorial(number).GetNumberStr();

    cout << result << endl;

    int total = 0;

    for(size_t i = 0; i < result.length(); i++)
    {
        stringstream tempStream;
        int tempNumber = 0;
        tempStream << result[i];
        tempStream >> tempNumber;
        total += tempNumber;
    }
    
    mAnswer << total; 
}

}
