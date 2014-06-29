#include "Problem12.h"

namespace projectEuler
{

// Constructor
Problem12::Problem12()
{
    
}


// Destructor
Problem12::~Problem12()
{

}


// Solver
void Problem12::Solve()
{
    int maxSize = 0;

    for(long long i = 1; i < LONG_MAX; i++)
    {
        const long long triangle = (i*(i+1))/2;
        const int size = Cebir::FactorCount(triangle);

        if(size >= maxSize)
        {
            cout << i << " -- " << triangle << " -- " << size << endl;
            maxSize = size;
        }

        if(maxSize > 500)
        {
            mAnswer << triangle;
            break;
        }
    }
}

}
