#include "FileReader.h"

namespace projectEuler
{

FileReader::FileReader(const string& fileName)
{
    mDataFile.open(fileName);
}


FileReader::~FileReader()
{
    mDataFile.close();
}


string FileReader::GetDataAsRow()
{
    string data = ""; 

    if(mDataFile.is_open())
    {
        string line = "";

        while(mDataFile.good())
        {
            getline(mDataFile, line);
            data += (line + " ");
        }
    }

    return data;
}

string FileReader::GetDataAsTree()
{
    string data = ""; 

    if(mDataFile.is_open())
    {
        string line = "";

        while(mDataFile.good())
        {
            getline(mDataFile, line);
            data += (line + ";");
        }
    }

    return data;
}


}
