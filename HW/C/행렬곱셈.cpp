#include <iostream>
#include <fstream>

void solving(std::ifstream &inStream);

int main(void)
{
    std::ifstream inStream;
    inStream.open("input.txt");

    if (inStream.fail())
    {
        std::cerr << "opening file is failed.\n";
        return -1;
    }

    int numTestCases;
    inStream >> numTestCases;

    for (int i = 0; i < numTestCases; i++)
    {
        solving(inStream);
    }
}

void solving(std::ifstream &inStream)
{
    int r, s, t, element, sum;
    inStream >> r >> s >> t;

    /* setting the matrix */
    int matrixA[r][s];
    int matrixB[s][t];
    int matrixC[r][t];

    for (int row = 0; row < r; row++)
    {
        for (int col = 0; col < s; col++)
        {
            inStream >> element;
            matrixA[row][col] = element;
        }
    }


    for (int row = 0; row < s; row++)
    {
        for (int col = 0; col < t; col++)
        {
            inStream >> element;
            matrixB[row][col] = element;
        }
    }

    for (int row = 0; row < r; row++)
    {
        for (int col = 0; col < t; col++)
        {
            sum = 0;
            for (int k = 0; k < s; k++)
            {
                sum += matrixA[row][k] * matrixB[k][col]; 
            }
            matrixC[row][col] = sum;
            std::cout << matrixC[row][col] << " ";                                    
        }
        std::cout << std::endl;
    }
}