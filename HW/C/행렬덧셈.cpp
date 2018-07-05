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
    int row, col, element;
    inStream >> row >> col;

    /* setting the matrix */
    int matrixA[row][col];
    int matrixB[row][col];

    for (int r = 0; r < row * 2; r++)
    {
        for (int c = 0; c < col; c++)
        {
            inStream >> element;
            if (r < row)
                matrixA[r][c] = element;
            else
                matrixB[r - row][c] = element;
        }
    }

    /* print the output */
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
            std::cout << matrixA[r][c] + matrixB[r][c] << " ";
        std::cout << std::endl;
    }
}