#include <iostream>
#include <fstream>
#include <cstdlib>

void solving(std::ifstream &inStream);

int main(void)
{
    std::ifstream inStream("input.txt");
    if (inStream.fail())
    {
        std::cerr << "opening file is failed" << std::endl;
        std::exit(1);
    }

    int numTestCases;
    inStream >> numTestCases;

    for (int i = 0; i < numTestCases; i++)
    {
        solving(inStream);
    }

    inStream.close();

    return 0;
}

void solving(std::ifstream &inStream)
{
    int m, n, g, numAlive = 0;
    inStream >> m >> n >> g;

    char generation[m][n];
    int tempGeneration[m][n];
    char c;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            inStream >> c;
            generation[i][j] = c;
            if (c == 'O')
            {
                tempGeneration[i][j] = 1;
            }
            else
            {
                tempGeneration[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < g; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                int count = 0;
                if (j > 0)
                    count += tempGeneration[j - 1][k] ? 1 : 0;
                if (j < m - 1)
                    count += tempGeneration[j + 1][k] ? 1 : 0;
                if (k < n - 1)
                    count += tempGeneration[j][k + 1] ? 1 : 0;
                if (k > 0)
                    count += tempGeneration[j][k - 1] ? 1 : 0;
                if (j > 0 && k < n - 1)
                    count += tempGeneration[j - 1][k + 1] ? 1 : 0;
                if (j < m - 1 && k < n - 1)
                    count += tempGeneration[j + 1][k + 1] ? 1 : 0;
                if (j > 0 && k > 0)
                    count += tempGeneration[j - 1][k - 1] ? 1 : 0;
                if (j < m - 1 && k > 0)
                    count += tempGeneration[j + 1][k - 1] ? 1 : 0;
                if (tempGeneration[j][k])
                {
                    if (count == 2 || count == 3)
                    {
                        generation[j][k] = 'O';
                    }
                    else
                    {
                        generation[j][k] = 'X';
                    }
                }
                else
                {
                    if (count == 3)
                    {
                        generation[j][k] = 'O';
                    }
                    else
                    {
                        generation[j][k] = 'X';
                    }
                }
            }
        }
        numAlive = 0;
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (generation[j][k] == 'O')
                {
                    tempGeneration[j][k] = 1;
                    numAlive++;
                }
                else
                {
                    tempGeneration[j][k] = 0;
                }
            }
        }
    }

    std::cout << numAlive << std::endl;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << generation[i][j];
        }
        std::cout << std::endl;
    }
}