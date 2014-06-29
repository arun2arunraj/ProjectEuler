#include "Problem18.h"

namespace projectEuler
{

// Constructor
Problem18::Problem18()
{

}


// Destructor
Problem18::~Problem18()
{

}


// Solver
void Problem18::Solve()
{
    FileReader fileReader("Data/Problem18/numberTree.txt");

    stringstream data;
    vector<string> rows;
    vector<vector<int>> tree;
    string item;
    data << fileReader.GetDataAsTree();

    while(getline(data, item, ';'))
    {
        rows.push_back(item);
    }

    // Fill tree structure
    for(size_t i = 0; i < rows.size(); i++)
    {
        stringstream tempStream;
        tempStream << rows[i];
        vector<int> treeRow;

        for(size_t j = 0; j < i + 1; j++)
        {
            int tempValue;
            tempStream >> tempValue;
            //cout << tempValue << "-";
            treeRow.push_back(tempValue);
        }

        tree.push_back(treeRow);
        //cout << endl;
    }

    // Actual back traverse calculation!
    for(size_t y = tree.size()-1; y > 0; y--)
    {
        for(size_t x = 0; x < tree[y].size()-1; x++)
        {
            int bigger = tree[y][x] > tree[y][x+1] ? tree[y][x] : tree[y][x+1];
            tree[y-1][x] += bigger;
        }
    }

    mAnswer << tree[0][0];
}

}
