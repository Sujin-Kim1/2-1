#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

string _1_9[9] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
string _10_19[10] = {"Ten",
                    "Eleven",
                    "Twelve",
                    "Thirteen",
                    "Fourteen",
                    "Fifteen",
                    "Sixteen",
                    "Seventeen",
                    "Eighteen",
                    "Nineteen"};
string _20_90[8] = {"Twenty",
                    "Thirty",
                    "Forty",
                    "Fifty",
                    "Sixty",
                    "Seventy",
                    "Eighty",
                    "Ninety"};
string hun = "Hundred";
string tho = "Thousand";
string mil = "Million";
string bil = "Billion";

void ProblemSolving(std::ifstream &inStream);
void readNum(int, vector<string> &);

int main()
{
    // read the file
    std::ifstream inStream;
    inStream.open("input.txt");
    // print the error message if the file is wrong
    if (inStream.fail())
    {
        std::cerr << "Input file opening failed.\n"
                  << std::endl;
    }
    // store the test cases
    int numTestCases;
    inStream >> numTestCases;

    for (int i = 0; i < numTestCases; i++)
    {
        ProblemSolving(inStream);
    }
}

void readNum(int n, vector<string> &answer)
{
    int h, t, o;
    o = n % 10;
    n /= 10;
    t = n % 10;
    n /= 10;
    h = n;

    if (h != 0)
    {
        answer.push_back(_1_9[h - 1]);
        answer.push_back(hun);
    }

    if (t != 0)
    {
        if (t == 1)
        {
            answer.push_back(_10_19[o]);
            return;
        }
        else 
        {
            answer.push_back(_20_90[t - 2]);
        }
    }

    if (o != 0)
    {
        answer.push_back(_1_9[o - 1]);
    }
}

void ProblemSolving(std::ifstream &inStream)
{
    vector<string> answer;
    long n;
    int num[4] = {0};

    inStream >> n;

    for (int i = 0; i < 4; i++)
    {
        num[3 - i] = n % 1000;
        n /= 1000;
    }

    for (int i = 0; i < 4; i++)
    {
        if (num[i] == 0)
        {
            continue;
        }
        readNum(num[i], answer);
        switch (i)
        {
        case 0:
            answer.push_back(bil);
            break;
        case 1:
            answer.push_back(mil);
            break;
        case 2:
            answer.push_back(tho);
            break;
        }
    }
    for (int i = 0; i < answer.size(); i++)
    {
        std::cout << answer[i];
        if (i != answer.size() - 1)
        {
            std::cout << "_";
        }
    }
    std::cout << std::endl;
}