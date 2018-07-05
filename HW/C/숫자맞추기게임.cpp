#include <iostream>
#include <fstream>

int solving(std::ifstream &inStream);

int main()
{
    std::ifstream inStream;
    inStream.open("input.txt");

    int numTestCases;
    inStream >> numTestCases;

    for (int i = 0; i < numTestCases; i++)
    {
        std::cout << solving(inStream) << std::endl;
    }
}

int solving(std::ifstream &inStream)
{
    int S[10000] = {0};
    int numInput;
    inStream >> numInput;

    for (int i = 0; i < numInput; i++)
    {
        int testCase, s, b;
        inStream >> testCase >> s >> b;

        // array of testCase
        int testArr[4];

        for (int j = 0; j < 4; j++)
        {
            testArr[j] = testCase % 10;
            testCase /= 10;
        }

        // array of temp
        for (int j = 0; j < 10000; j++)
        {
            if (S[j] != 0)
            {
                continue;
            }
            int tempArr[4] = {0};
            int copyJ = j;

            for (int k = 0; k < 4; k++)
            {
                tempArr[k] = copyJ % 10;
                copyJ /= 10;
            }

            // find Strike
            int tempS = 0;
            int tempStrike[4] = {0};

            for (int k = 0; k < 4; k++)
            {
                if (testArr[k] == tempArr[k])
                {
                    ++tempS;
                    tempStrike[k] = 1;
                }
            }

            // find Ball
            int tempB = 0;
            int tempBall[4] = {0};
            for (int k = 0; k < 4; k++)
            {
                if (tempStrike[k] == 1)
                    continue;

                for (int l = 0; l < 4; l++)
                {
                    if (tempStrike[l] == 1 || tempBall[l] == 1)
                        continue;

                    if (testArr[k] == tempArr[l] && k != l)
                    {
                        ++tempB;
                        tempBall[l] = 1;
                        break;
                    }
                }
            }

            if (s != tempS || b != tempB)
            {
                S[j] = 1;
            }   
        }
    }

    int countAnswer = 0;
    for (int i = 0; i < 10000; i++)
    {
        if (S[i] == 0)
            ++countAnswer;
    }

    if (countAnswer > 1)
        return -1;
    else if (countAnswer == 0)
        return -2;
    else
    {
        for (int i = 0; i < 10000; i++)
        {
            if (S[i] == 0)
            {
                return i;
            }
        }
    }
}