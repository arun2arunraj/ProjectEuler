#ifndef PROBLEM_BASE_H
#define PROBLEM_BASE_H

#include <iostream>
#include <string>
#include <sstream>
#include "../utility/Cebir.h"
#include "../utility/InfiniteInteger.h"
#include "../utility/FileReader.h"
#include "../utility/Tree.h"

using std::cout;
using std::endl;
using std::string;
using std::stringstream;


namespace projectEuler
{

//
// Problem base for other problem classes
//
class ProblemBase
{
    public:
        ProblemBase() {}
        virtual ~ProblemBase() {}

        virtual void Solve() = 0;
        inline string GetAnswer() { return mAnswer.str(); }

    protected:
        stringstream mAnswer;
};

}

#endif // PROBLEM_BASE_H
