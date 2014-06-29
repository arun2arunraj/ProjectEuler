#include "Problem17.h"

namespace projectEuler
{

// Constructor
Problem17::Problem17()
{
    numberMap[1]    = "one";
    numberMap[2]    = "two";
    numberMap[3]    = "three";
    numberMap[4]    = "four";
    numberMap[5]    = "five";
    numberMap[6]    = "six";
    numberMap[7]    = "seven";
    numberMap[8]    = "eight";
    numberMap[9]    = "nine";
    numberMap[10]   = "ten";
    numberMap[11]   = "eleven";
    numberMap[12]   = "twelve";
    numberMap[13]   = "thirteen";
    numberMap[14]   = "fourteen";
    numberMap[15]   = "fifteen";
    numberMap[16]   = "sixteen";
    numberMap[17]   = "seventeen";
    numberMap[18]   = "eighteen";
    numberMap[19]   = "nineteen";
    numberMap[20]   = "twenty";
    numberMap[30]   = "thirty";
    numberMap[40]   = "forty";
    numberMap[50]   = "fifty";
    numberMap[60]   = "sixty";
    numberMap[70]   = "seventy";
    numberMap[80]   = "eighty";
    numberMap[90]   = "ninety";
    numberMap[100]  = "hundred";
    numberMap[1000] = "thousand";
}


// Destructor
Problem17::~Problem17()
{

}


// Solver
void Problem17::Solve()
{
    int total = 0;

    for(int i = 1; i <= 1000; i++)
        total += LetterCountInNumber(i);

   /* total = LetterCountInNumber(115);*/

    mAnswer << total;
}


int Problem17::LetterCountInNumber(int number)
{
    string totalString = "";
    int thousands = 0;
    int hundreds  = 0;
    int tens      = 0;
    int units     = 0;

    thousands = number / 1000;
    number    -= thousands * 1000;
    hundreds  = number / 100;
    number    -= hundreds * 100;
    tens      = number / 10;
    number    -= tens * 10;
    units     = number;

    if (thousands > 0)
    {
        totalString.append(numberMap[thousands]);
        totalString.append(numberMap[1000]);
    }

    if(hundreds > 0)
    {
        totalString.append(numberMap[hundreds]);
        totalString.append(numberMap[100]);
    }

    if((thousands > 0 || hundreds > 0) && (tens > 0 || units > 0))
        totalString.append("and");

    if(tens > 0)
    {
        if(tens == 1)
        {
            totalString.append(numberMap[10 + units]);
        }
        else
        {
            totalString.append(numberMap[tens*10]);
        }
    }
    
    if(units > 0 && tens != 1)
    {
        totalString.append(numberMap[units]);
    }

    return totalString.size();
}

}
