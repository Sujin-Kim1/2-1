#include <iostream>
#include <fstream>
#include <algorithm>
#define MAX 1000000000

int main(void)
{
    std::ifstream inStream;
    inStream.open("input.txt");

    // setting the hamming array
    int hammingArr[1350];
    hammingArr[0] = 1;
    int cnt = 1;

    while (cnt < 1350)
    {
        int arr[1350];
        int arrCnt = 0;

        for (int i = 0; i < cnt; i++)
        {
            if (hammingArr[cnt - 1] < hammingArr[i] * 2 && hammingArr[i] * 2 < MAX)
            {
                arr[arrCnt++] = hammingArr[i] * 2;
            }

            if (hammingArr[cnt - 1] < hammingArr[i] * 3 && hammingArr[i] * 3 < MAX)
            {
                arr[arrCnt++] = hammingArr[i] * 3;
            }

            if (hammingArr[cnt - 1] < hammingArr[i] * 5 && hammingArr[i] * 5 < MAX)
            {
                arr[arrCnt++] = hammingArr[i] * 5;
            }
        }
        std::sort(arr, arr + arrCnt);

        hammingArr[cnt++] = arr[0];
    }

    int numTestCases;
    inStream >> numTestCases;

    for (int i = 0; i < numTestCases; i++)
    {
        int testCase;
        inStream >> testCase;

        std::cout << hammingArr[testCase - 1] << std::endl;
    }
}