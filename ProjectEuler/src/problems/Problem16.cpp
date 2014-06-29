#include "Problem16.h"

namespace projectEuler
{

// Constructor
Problem16::Problem16()
{
    
}


// Destructor
Problem16::~Problem16()
{

}


// Solver
void Problem16::Solve()
{
    InfiniteInteger num1("2");
    InfiniteInteger num2("2");

    for (int i = 1; i < 1000; i++)
        num2 *= num1;

    string numStr = num2.GetNumberStr();
    int digitSum = 0;

    for(size_t i = 0; i < numStr.size(); ++i)
        digitSum += (numStr[i] - '0');

    mAnswer << digitSum;
}

}
