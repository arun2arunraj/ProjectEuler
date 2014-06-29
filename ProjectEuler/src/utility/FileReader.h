#ifndef FILE_READER_H
#define FILE_READER_H

#include <iostream>
#include <fstream>
#include <string>

using std::ifstream;
using std::string;


namespace projectEuler
{

class FileReader
{
    public:
        FileReader(const string& filePath);
        ~FileReader();

        string GetDataAsRow();
        string GetDataAsTree();

    private:
        ifstream mDataFile;
};

}


#endif // FILE_READER_H
