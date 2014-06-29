#include "Problem13.h"

namespace projectEuler
{

// Constructor
Problem13::Problem13()
{
    
}


// Destructor
Problem13::~Problem13()
{

}


// Solver
void Problem13::Solve()
{
    FileReader reader("Data/Problem13/numbers.txt");
    stringstream data;
    data << reader.GetDataAsRow();

    string str = "";
    InfiniteInteger total;
    InfiniteInteger temp;

    for (int i = 0; i < 100; i++)
    {
        data >> str;
        temp = str;
        total += temp;
    }

    mAnswer << total.GetNumberStr();
}

}
