#include <iostream>
#include <fstream>

bool isDecimal(int);
void solving(std::ifstream &inStream);

int main(void) 
{
    std::ifstream inStream;
    inStream.open("input.txt");

    if (inStream.fail())
    {
        std::cerr << "input file opening failed.\n";
        return -1;
    }
    
    int numTestCases;
    inStream >> numTestCases;

    for (int i = 0; i < numTestCases; ++i)
    {
        solving(inStream);
    }
}

/* 소인수분해하였을 때, 다음과 같은 순서로 2k+1 개의 정수를 순서대로 출력한다.
k p1 d1 p2 d2 ... pk dk
여기서, k 는 소인수분해에 사용된 소수의 개수를 나타내며, 각 소인수들은 점점 증가하는 순서대로
(즉, p1 < p2 < … < pk) 출력한다. 각 정수들 사이에는 한 개의 공백을 둔다. */ 

void solving(std::ifstream &inStream)
{
    unsigned int k = 0, test, copytest;
    int arr[9999] = {0};
    inStream >> test;
    copytest = test;


    // while (copytest != 1)
    // {
    //     for (int i = 2; i < 10000; i++)
    //     {
    //         if (copytest % i == 0)
    //         {   
    //             arr[i - 2] += 1;
    //             if (arr[i - 2] == 1)
    //                 k++;
    //             copytest /= i;
    //             break;
    //         }
    //     }
    // }

    for (int i = 2; copytest != 1; i++) {
        if (copytest % i == 0) {
            arr[i - 2]++;
            if (arr[i - 2] == 1)
                k++;
            copytest /= i--;
        }
    }

    std::cout << k << " ";

    for (int i = 0; i < 9999; i++)
    {
        if (arr[i] != 0)
            std::cout << i + 2 << " " << arr[i] << " ";
    }
    
    std::cout << std::endl;

}