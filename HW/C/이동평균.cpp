#include <iostream>
#include <fstream>

void solving(std::ifstream &inStream);

int main(void)
{
    std::ifstream inStream;
    inStream.open("input.txt");
    
    if (inStream.fail())
    {
        std::cerr << "opening file is failed" << std::endl;
        return -1;
    }

    int numTestCases;
    inStream >> numTestCases;

    for (int i = 0 ; i < numTestCases; i++)
    {
        solving(inStream);
    }
}

void solving(std::ifstream &inStream)
{
    int numTests, cursor = 0, element, cycle, num, sum = 0, average;
    inStream >> numTests;

    int arr[numTests];

    for (int i = 0; i < numTests; i++)
    {
        inStream >> element;
        arr[i] = element;
    }

    inStream >> cycle;
    num = numTests - cycle + 1;
    std::cout << num << " ";

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < cycle; j++)
        {
            sum += arr[cursor + j];
        }
        average = sum / cycle;
        cursor++;
        sum = 0;

        std::cout << average << " ";
    }
    std::cout << std::endl;
}