#include <iostream>
#include <fstream>
#include <cstdlib>

void problemSolving(std::ifstream &inStream);


int main(void)
{
    std::ifstream inStream("input.txt");
    if (inStream.fail())
    {
        std::cerr << "opening file is failed\n";
        return -1;
    }

    int numTestCases;
    inStream >> numTestCases;

    for (int i = 0; i < numTestCases; i++)
    {
        problemSolving(inStream);
    }
}

void problemSolving(std::ifstream &inStream)
{
    int num, col, i, count, answer = 0;
    inStream >> num;
    int A[6][7] = {0}, B[6][7] = {0}, C[6][7] = {0};

    for (i = 0; i < num; i++)
    {
        inStream >> col;
        --col;

        if (i % 2 == 0)
        {
            int row = 0;
            if (C[row][col] != 0)
            {
                while (C[row][col] != 0)
                    row++;
            }
            A[row][col] = 1;
            C[row][col] = 1;

            // 가로
            count = 0;
            for (int j = 0; j < 7; j++)
            {
                if (A[row][j] == 1)
                {
                    count++;
                }
                else
                {
                    count = 0;
                }
                if (count == 4)
                {
                    answer = 1;
                    break;
                }
            }

            // 세로
            count = 0;
            for (int j = 0; j < 6; j++)
            {
                if (A[j][col] == 1)
                {
                    count++;
                }
                else
                {
                    count = 0;
                }
                if (count == 4)
                {
                    answer = 1;
                    break;
                }
            }

              // 오른쪽 대각선
            if (B[row - 1][col - 1] == 1 && col >= 3 && row >= 3)
            {
                count = 0;
                for (int j = row - 3, k = col - 3; j <= row; j++, k++)
                {
                    if (B[j][k] == 1)
                        count++;
                }
                if (count == 4)
                {
                    answer = 1;
                    break;
                }
            }

            // 왼쪽 대각선
            if (B[row - 1][col + 1] == 1 && col >= 3 && row >= 3)
            {
                count = 0;
                for (int j = row - 3, k = col + 1; j <= row; j++, k--)
                {
                    if (B[j][k] == 1)
                        count++;
                }
                if (count == 4)
                {
                    answer = 1;
                    break;
                }
            }
        }

        else
        {
            int row = 0;
            if (C[row][col] != 0)
            {
                while (C[row][col] != 0)
                    row++;
            }
            B[row][col] = 2;
            C[row][col] = 2;

            // 가로
            count = 0;
            for (int j = 0; j < 7; j++)
            {
                if (B[row][j] == 2)
                {
                    count++;
                }
                else
                {
                    count = 0;
                }
                if (count == 4)
                {
                    answer = 2;
                    break;
                }
            }

            // 세로
            count = 0;
            for (int j = 0; j < 6; j++)
            {
                if (B[j][col] == 2)
                {
                    count++;
                }
                else
                {
                    count = 0;
                }
                if (count == 4)
                {
                    answer = 2;
                    break;
                }
            }

            // 오른쪽 대각선
            if (B[row - 1][col - 1] == 1 && col >= 3 && row >= 3)
            {
                count = 0;
                for (int j = row - 3, k = col - 3; j <= row; j++, k++)
                {
                    if (B[j][k] == 2)
                        count++;
                }
                if (count == 4)
                {
                    answer = 2;
                    break;
                }
            }

            // 왼쪽 대각선
            if (B[row - 1][col + 1] == 1 && col >= 3 && row >= 3)
            {
                count = 0;
                for (int j = row - 3, k = col + 1; j <= row; j++, k--)
                {
                    if (B[j][k] == 2)
                        count++;
                }
                if (count == 4)
                {
                    answer = 2;
                    break;
                }
            }
        }
    }
    std::cout << answer << std::endl;

    for (; i < num - 1; i++)
    {
        inStream >> col;
        std::cout << col << " ";
        i++;
    }

    
    for (int j = 0; j < 6; j++)
    {
        for (int k = 0; k < 7; k++)
        {
            std::cout << C[j][k] << " ";
        }
        std::cout << std::endl;
    }
}