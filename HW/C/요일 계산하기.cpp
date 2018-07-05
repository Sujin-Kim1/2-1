#include <iostream>
#include <fstream>

bool isYoon(int days);
int plusMonth(int month);
int solving(std::ifstream &inStream);

int main(void) 
{
    std::ifstream inStream;
    inStream.open("input.txt");

    int numTestCases;
    inStream >> numTestCases;

    for (int i = 0; i < numTestCases; ++i)
    {
        std::cout << solving(inStream) << std::endl;
    }

    return 0;

}

bool isYoon(int days)
{
    return ((days % 4 == 0 && days % 100 != 0) || days % 400 == 0);
}

int plusMonth(int month)
{
    switch(month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 2:
            return 28;
        default:
            return 30;
    }
}

int solving(std::ifstream &inStream)
{
    int Y, M, D, days = 0;
    inStream >> Y >> M >> D;
    
    for (int i = 1582; i < Y; ++i)
    {
        if (!isYoon(i))
            days += 365;
        else days+= 366;
    }

    for (int i = 1; i < M; ++i)
    {
        if(isYoon(Y) && i == 2)
            days += 29;
        else
            days += plusMonth(i);
    }

    days += D + 4;
    
    return days % 7;

}