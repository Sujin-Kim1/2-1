#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void ProblemSolving(std::ifstream &inStream);

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
        ProblemSolving(inStream);
    }

    return 0;
}

void ProblemSolving(std::ifstream &inStream)
{
    int k, n;
    int p1 = 0, p2 = 0, p4 = 0, p8 = 0, p16 = 0, errorPosition = 0;
    unsigned int hammingCode = 0;
    inStream >> k >> n;

    if (k == 0)
    {
        for (int i = 0; i < 31; i++)
        {
            if (i == 0 || i == 1 || i == 3 || i == 7 || i == 15)
                continue;
            hammingCode += (n % 2 == 1) ? pow(2, i) : 0;
            if (n % 2 == 1)
            {
                if ((i + 1) % 2 == 1)
                    p1++;
                if ((i + 1) % 4 >= 2)
                    p2++;
                if ((i + 1) % 8 >= 4)
                    p4++;
                if ((i + 1) % 16 >= 8)
                    p8++;
                if ((i + 1) % 32 >= 16)
                    p16++;
            }
            n /= 2;
        }

        if (p1 % 2 == 1)
            hammingCode += pow(2, 0);
        if (p2 % 2 == 1)
            hammingCode += pow(2, 1);
        if (p4 % 2 == 1)
            hammingCode += pow(2, 3);
        if (p8 % 2 == 1)
            hammingCode += pow(2, 7);
        if (p16 % 2 == 1)
            hammingCode += pow(2, 15);

        cout << hammingCode << endl;
    }
    if (k == 1)
    {
        int hammingArray[31];
        for (int i = 0; i < 31; i++)
        {
            hammingArray[i] = n % 2;
            n /= 2;
        }
        for (int i = 0; i < 31; i++)
        {

            if ((i + 1) % 2 == 1)
            {
                if (hammingArray[i] == 1)
                    p1++;
            }
            if ((i + 1) % 4 >= 2)
            {
                if (hammingArray[i] == 1)
                    p2++;
            }
            if ((i + 1) % 8 >= 4)
            {
                if (hammingArray[i] == 1)
                    p4++;
            }
            if ((i + 1) % 16 >= 8)
            {
                if (hammingArray[i] == 1)
                    p8++;
            }
            if ((i + 1) % 32 >= 16)
            {
                if (hammingArray[i] == 1)
                    p16++;
            }
        }
        if (p1 % 2 == 1)
            errorPosition++;
        if  (p2 % 2 == 1)
            errorPosition += 2;
        if  (p4 % 2 == 1)
            errorPosition += 4;
        if  (p8 % 2 == 1)
            errorPosition += 8;
        if  (p16 % 2 == 1)
            errorPosition += 16;
        
        hammingArray[errorPosition - 1] = (hammingArray[errorPosition] == 1) ? 0 : 1;

        int cursor = 0;
        for (int i = 0; i <= 31; i++) 
        {
            if (i == 0 || i == 1 || i == 3 || i == 7 || i == 15) 
            {
                continue;
            }
            if (hammingArray[i] == 1)
            {
                hammingCode += pow(2, cursor);
            }
            cursor++;
        }
        
        cout << hammingCode << endl;
    }
}
