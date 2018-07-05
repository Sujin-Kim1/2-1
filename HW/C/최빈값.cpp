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
    // solving
    for (int i = 0; i < numTestCases; i++)
    {
        ProblemSolving(inStream);
    }
}

void ProblemSolving(std::ifstream &inStream)
{
    int testNum;
    inStream >> testNum;
    int inputArr[testNum], countArr[testNum], valArr[testNum];
    int inputNum;

    for (int i = 0; i < testNum; i++)
    {
        inStream >> inputNum;
        inputArr[i] = inputNum;
    }

    std::sort(inputArr, inputArr + testNum);

    valArr[0] = inputArr[0];
    int valNum = 1;
    int countNum = 0;
    int count = 1;
    for (int i = 1; i < testNum; i++)
    {
        if (inputArr[i - 1] != inputArr[i])
        {
            valArr[valNum++] = inputArr[i];
            countArr[countNum++] = count;
            count = 1;
        }
        else
        {
            count++;
        }
    }
    countArr[countNum++] = count;

    int max = *std::max_element(countArr, countArr + countNum);
    int maxCount = 0;
    for (int i = 0; i < countNum; i++)
    {
        if (countArr[i] == max)
        {
            ++maxCount;
        }
    }
    std::cout << maxCount << " " << max << " ";

    for (int i = 0; i < countNum; i++)
    {
        if (countArr[i] == max)
        {
            std::cout << valArr[i] << " ";
        }
    }
    std::cout << std::endl;
}