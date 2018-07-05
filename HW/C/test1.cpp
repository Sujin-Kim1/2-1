/*

    Problem:
            개수구하기

*/
/*
    국민대학교 소프트웨어융합대학 소프트웨어학부 2학년
    20171596 김수진
    
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void ProblemSolving(std::ifstream& inStream);

int main(void) {
    // open the input file
    ifstream inStream;
    inStream.open("input.txt");

    // read the number of test cases
    int numTestCases;
    inStream >> numTestCases;

    for (int i = 0; i < numTestCases; ++i) {
        ProblemSolving(inStream);
    }

    return 0;
}

void ProblemSolving(std::ifstream& inStream) {
    int numTest;
    inStream >> numTest;

    int find;
    inStream >> find;

    int output;
    output = 0;
    for(int i = 0; i < numTest; ++i) {
        int tmp;
        inStream >> tmp;
        if (tmp == find) ++output;
    }
    cout << output << endl;
}

