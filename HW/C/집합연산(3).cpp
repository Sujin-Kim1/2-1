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
    unsigned int A[132] = {0}, B[132] = {0}, intersectionArr[132] = {0},
                 unionArr[132] = {0}, differenceArr[132] = {0};
    int inputA, inputB, data, Icnt = 0, Ucnt = 0, Dcnt = 0;
    // Icnt : count intersection     Ucnt : count union    Dcnt : count different set

    inStream >> inputA;

    for (int i = 0; i < inputA; i++)
    {
        inStream >> data;
        A[data] = 1;
    }

    inStream >> inputB;

    for (int i = 0; i < inputB; i++)
    {
        inStream >> data;
        B[data] = 1;
    }

    for (int i = 0; i < 132; i++)
    {
        intersectionArr[i] = A[i] && B[i];
        if (intersectionArr[i] == 1) ++Icnt;

        unionArr[i] = A[i] || B[i];
        if (unionArr[i] == 1) ++Ucnt;

        if (A[i] && B[i] == 1) differenceArr[i] = 0;
        else 
        {
            differenceArr[i] = A[i];
            if (A[i] == 1) ++Dcnt;
        }
    }

    std::cout << Icnt << " ";
    for (int i = 0; i < 132; i++)
    {
        if (intersectionArr[i] == 1) std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << Ucnt << " ";
    for (int i = 0; i < 132; i++)
    {
        if (unionArr[i] == 1) std::cout << i << " ";
    }
    std::cout << std::endl;

        std::cout << Dcnt << " ";
    for (int i = 0; i < 132; i++)
    {
        if (differenceArr[i] == 1) std::cout << i << " ";
    }
    std::cout << std::endl;
}