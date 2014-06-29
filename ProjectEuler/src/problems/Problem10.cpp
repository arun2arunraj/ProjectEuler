#include "Problem10.h"

namespace projectEuler
{

// Constructor
Problem10::Problem10()
{
    
}


// Destructor
Problem10::~Problem10()
{

}


// Solver
void Problem10::Solve()
{
    long long total = 0;

    for(long long i = 1; i < 2000000; i++)
    {
        if(Cebir::IsPrimeNumber(i))
        {
            //cout << i << endl;
            total += i;
        }
    }

    mAnswer << total;
}

}
