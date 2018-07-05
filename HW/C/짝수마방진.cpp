#include <iostream>
#include <fstream>
#include <cstdlib>

void _4kMagicSqure(int);
void ConwayMagicSquare(int);

int main(void)
{
    std::ifstream inStream("input.txt");
    if (inStream.fail())
    {
        std::cerr << "opening file is failed" << std::endl;
        std::exit(1);
    }

    int numTestCases;
    for (int i = 0; i < numTestCases; i++)
    {
        int test;
        inStream >> test;
        if (test % 4 == 0)
        {
            evenMagicSqure(test);
        }
        else
        {
            Conway
                MagicSquare(test);
        }
    }
}

void evenMagicSqure(int n)
{
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i % 4 == 0 || i % 4 == 3)
            {
                if (j % 4 == 0 || j % 4 == 3)
                    std::cout << n * n + 1 - count << " ";
                else
                    std::cout << count << " ";
            }
            else
            {
                if (j % 4 == 1 || j % 4 == 2)
                    std::cout << n * n + 1 - count << " ";
                else
                    std::cout << count << " ";
            }
            count++;
        }
        std::cout << std::endl;
    }
}

void ConwayMagicSquare(int n)
{
    int magicSqure[n][n];
    char LUX = 'L';
    int caseL[4][2] = {{0, 1}, {1, 0}, {1, 1}, {0, 0}};
    int caseU[4][2] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
    int caseX[4][2] = {{0, 0}, {1, 1}, {1, 0}, {0, 1}};

    for (int i = 0, j = n / 2, count = 1; count <= n * n; count++)
    {
        magicSqure[i][j] = count;
        if (count % n == 0)
        {
            i++;
        }
        else 
        {
            i--, j++;
            if (i < 0) i = n - 1;
            if (j > n - 1) j = 0;
        }
    }
}