#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

void problemSolving(std::ifstream& inStream);

int main() {
    std::ifstream inStream;
    inStream.open("input.txt");

    if (inStream.fail()) {
        std::cerr << "Input file opening failed." << std::endl;
        std::exit(1);
    }

    int numTestCases;
    inStream >> numTestCases;

    for(int i = 0; i < numTestCases; i++) {
        std::cout << problemSolving(inStream) << std::endl;
    }
}

void problemSolving(std::ifstream& inStream)
{
    int m, n, k, len;
    std::string s;
    int xmove[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int ymove[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    inStream >> m >> n;

    char grid[m][n];
    char c;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            inStream >> c;
            grid[i][j] = c;
        }
    }

    inStream >> k;
    for (int i = 0; i < k; i++)
    {
        inStream >> s;
        len = s.length();
        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (s[0] == grid[row][col])
                {
                    
                }
            }
        }
    }

}
