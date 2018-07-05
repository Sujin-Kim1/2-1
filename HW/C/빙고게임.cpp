#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void bingo(std::ifstream &);

int main()
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
        bingo(inStream);
    }
}

void bingo(std::ifstream &inStream)
{
    int gameBoard[5][5], used[5][5] = {0}, input, answer = 0;
    int r, c, d, rd, e;
    // row, col, diagonal, reverse diagonal, edge
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            inStream >> input;
            gameBoard[i][j] = input;
        }
    }
    used[2][2] = 1; // 가장 중앙은 항상 표시    

    for (int pickedNum = 0; pickedNum < 75; pickedNum++)
    {
        inStream >> input;
        if (answer)
            continue;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (gameBoard[i][j] == input)
                {
                    used[i][j] = 1;
                    r = 0;
                    c = 0;
                    d = 0;
                    rd = 0;
                    e = 0;
                    for (int k = 0; k < 5; k++)
                    {
                        r += used[i][k];
                        c += used[k][j];
                        d += used[k][k];
                        rd += used[4 - k][k];
                    }
                    e += used[0][0] + used[0][4] + used[4][0] + used[4][4];
                    if (r == 5 || c == 5 || d == 5 || rd == 5 || e == 4)
                        answer = pickedNum + 1;
                }
            }
        }
    }
    std::cout << answer << std::endl;
}