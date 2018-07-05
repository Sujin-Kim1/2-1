/*

    Problem:
            보드게임

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
    inStream.close();
    return 0;
}

void ProblemSolving(std::ifstream& inStream) {
    int a, b, aOutput, bOutput, result;
    inStream >> a;
    inStream >> b;
    aOutput = 0;
    bOutput = 0;
    
    aOutput += a / 16 * 2 + a % 16;

    bOutput += b / 16 * 2 + b % 16;

    if (b % 16 == 0) {
    if (aOutput >= bOutput) {
        result = aOutput;
    } else result = bOutput;

    cout << result << endl;
}