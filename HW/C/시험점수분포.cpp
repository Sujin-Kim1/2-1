#include <iostream>
#include <fstream>
#include <algorithm>

void ProblemSolving(std::ifstream &inStream);

int main()
{
    // read the file
    std::ifstream inStream;
    inStream.open("input.txt");
    // print the error message if the file is wrong
    if (inStream.fail())
    {
        std::cerr << "Input file opening failed.\n"
                  << std::endl;
    }
    // store the test cases
    int numTestCases;
    inStream >> numTestCases;

    for (int i = 0; i < numTestCases; i++)
    {
        ProblemSolving(inStream);
    }
}

void ProblemSolving(std::ifstream &inStream)
{
    int inputNum;
    inStream >> inputNum;

    int scoreArr[inputNum], input;
    
    for (int i = 0; i < inputNum; i++) 
    {
        inStream >> input;
        scoreArr[i] = input;                
    }

    std::sort(scoreArr, scoreArr + inputNum);
    
    int cnt = 1;
    for (int i = 0; i < inputNum; i++)
    {
        if (scoreArr[i] == scoreArr[i + 1]) ++cnt;
        else 
        {
            std::cout << scoreArr[i] << " " << cnt << " ";
            cnt = 1;
        }
    }

    std::cout << std::endl;
}