#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

void ProblemSolving(ifstream &inStream);

int main()
{
    // read the file
    ifstream inStream;
    inStream.open("input.txt");
    // print the error message if the file is wrong
    if (inStream.fail())
    {
        cerr << "Input file opening failed." << endl;
        exit(1);
    }
    // store the test cases
    int numTestCases;
    inStream >> numTestCases;
    // solving
    for (int i = 0; i < numTestCases; i++)
    {
        ProblemSolving(inStream);
    }
    return 0;
}

void ProblemSolving(ifstream &inStream)
{
    std::string currentTime;
    int n, h, m; // plus minutes, hour, minutes
    char AM_PM;

    inStream >> currentTime >> n;

    h = (currentTime[0] - '0') * 10 + currentTime[1] - '0';
    m = (currentTime[3] - '0') * 10 + currentTime[4] - '0';
    AM_PM = currentTime[5];

    if (AM_PM == 'P')
    {
        if (h != 12)
            h += 12;
    }
    else
    {
        if (h == 12)
            h = 0;
    }
    h += n / 60;
    m += n % 60;
    if (n >= 0)
    {
        while (m >= 60)
        {
            h++;
            m -= 60;
        }
        while (h >= 24)
        {
            h -= 24;
        }
    }
    else
    {
        while (m < 0)
        {
            h--;
            m += 60;
        }
        while (h < 0)
        {
            h += 24;
        }
    }
    if (h >= 12)
    {
        std::cout << "h : " << h << std::endl;
        h -= 12;
        AM_PM = 'P';
    }
    else
    {
        std::cout << "h : " << h << std::endl;
        AM_PM = 'A';
    }
    if (h == 0)
        h = 12;

    // print output
    if (h < 10 && m < 10)
        cout << "0" << h << ":"
             << "0" << m << AM_PM << "M" << endl;
    else if (h < 10 && m >= 10)
        cout << "0" << h << ":" << m << AM_PM << "M" << endl;
    else if (h >= 10 && m < 10)
        cout << h << ":"
             << "0" << m << AM_PM << "M" << endl;
    else
        cout << h << ":" << m << AM_PM << "M" << endl;
}