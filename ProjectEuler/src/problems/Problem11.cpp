#include "Problem11.h"

namespace projectEuler
{

// Constructor
Problem11::Problem11()
{
    
}


// Destructor
Problem11::~Problem11()
{

}


// Solver
void Problem11::Solve()
{
    FileReader reader("Data/Problem11/numbers.txt");
    stringstream data;
    data << reader.GetDataAsRow();

    int numbers[400];
    int number;

    // Parse
    for(int y = 0; y < 20; y++)
    {
        for(int x = 0; x < 20; x++)
        {
            data >> number;
            numbers[y*20 + x] = number;
          //  printf("%02d ", number);
        }

        //cout << endl;
    }

    int maxProduct = 0;

    // Calculate: ROWS
    for(int y = 0; y < 20; y++)
    {
        for(int x = 0; x < 20; x++)
        {
            int middleProduct = 1;
            
            for(int i = 0; i < 4 && (i+x)< 20; i++)
                middleProduct *= numbers[y*20 + x+i];

            if(middleProduct > maxProduct)
                maxProduct = middleProduct;
        }
    }

    // Calculate: COLUMNS
    for(int x = 0; x < 20; x++)
    {
        for(int y = 0; y < 20; y++)
        {
            int middleProduct = 1;

            for(int i = 0; i < 4 && (i+y)< 20; i++)
                middleProduct *= numbers[(y+i)*20 + x];

            if(middleProduct > maxProduct)
                maxProduct = middleProduct;
        }
    }

    // Calculate: DIAGONAL
    for(int y = 0; y < 20; y++)
    {
        for(int x = 0; x < 20; x++)
        {
            int middleProduct = 1;

            for(int i = 0; i < 4 && (i+y)< 20 && (i+x) < 20; i++)
                middleProduct *= numbers[(y+i)*20 + (x+i)];

            if(middleProduct > maxProduct)
                maxProduct = middleProduct;
        }
    }

    // Calculate: REVERSE-DIAGONAL
    for(int y = 19; y >= 0; y--)
    {
        for(int x = 0; x < 20; x++)
        {
            int middleProduct = 1;

            for(int i = 0; i < 4 && (i+y)< 20 && (y-i) >= 0 && (i+x) < 20; i++)
                middleProduct *= numbers[(y-i)*20 + (x+i)];

            if(middleProduct > maxProduct)
                maxProduct = middleProduct;
        }
    }

    mAnswer << maxProduct;
}

}
