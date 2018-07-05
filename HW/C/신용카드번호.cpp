#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

bool checkLength(int, int);
bool ProblemSolving(std::ifstream &inStream);

int main(void)
{
    std::ifstream inStream;
    inStream.open("input.txt");

    if (inStream.fail())
    {
        std::cerr << "Input file opening failed.\n";
        return -1;
    }
    int numTestCases;
    inStream >> numTestCases;
    for (int i = 0; i < numTestCases; i++)
    {
        cout << ProblemSolving(inStream) << endl;
    }

    return 0;
}

bool checkLength(int firstNum, int length)
{
    switch (firstNum)
    {
    case 3:
        return length == 14 || length == 15;
    case 6:
        return length == 16;
    case 5:
        return length == 16;
    case 4:
        return length == 13 || length == 16;
    default:
        return false;
    }
}

bool ProblemSolving(std::ifstream &inStream)
{
    string test;
    int firstNum, length, total = 0, checkCardNum, cursor = 0;

    inStream >> test;

    firstNum = test[0] - '0';
    length = test.length();

    for (int i = length - 1; i >= 0; i--)
    {
        if (cursor % 2 == 1)
        {
            checkCardNum = (test[i] - '0') % 10 * 2;
            if (checkCardNum > 9)
                checkCardNum -= 9;
        }
        else 
            checkCardNum = (test[i] - '0') % 10;
        cursor++;
        total += checkCardNum;
    }
    return (total % 10 == 0 && checkLength(firstNum, length));
}