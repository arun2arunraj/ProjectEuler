#include "Problem22.h"

namespace projectEuler
{

// Constructor
Problem22::Problem22()
{

}


// Destructor
Problem22::~Problem22()
{

}


// Solver
void Problem22::Solve()
{
    FillNames();
    SortNames();

    int answer = 0;

    for(size_t i = 0; i < mNames.size(); i++)
    {
        //cout << "Name: " << mNames[i] << endl;
        answer += AlphabeticValue(mNames[i]) * (i+1);
    }

    mAnswer << answer; 
}

void Problem22::FillNames()
{
    // Read
    FileReader fileReader("Data/Problem22/names.txt");
    string data = fileReader.GetDataAsRow();// yoyo test

    // Tokenize
    char* token = strtok (&data[0], "\",");

    while (token != NULL)
    {
        if(token[0] != ' ')
        {
            //cout << "Name: " << token << endl;
            mNames.push_back(token);
        }

        token = strtok (NULL, "\",");
    }

    cout << "TOTAL NAMES: " << mNames.size() << endl;
}

void Problem22::SortNames()
{
    std::sort(mNames.begin(), mNames.end());
}

int Problem22::AlphabeticValue(const string& name)
{
    int alphaValue = 0;

    for(size_t i = 0; i < name.length(); i++)
    {
        alphaValue += ((int)name[i] - 64);
    }

    return alphaValue;
}

}
