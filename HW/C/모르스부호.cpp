#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

std::string morse[26] = {".-", "-...", "-.-.", "-..", ".", "..-.",
                         "--.", "....", "..", ".---", "-.-", ".-..",
                         "--", "-.", "---", ".--.", "--.-", ".-.",
                         "...", "-", "..-", "...-", ".--", "-..-",
                         "-.--", "--.."};

void ProblemSolving(std::ifstream &inStream);

int main(void)
{
    std::ifstream inStream;
    inStream.open("input.txt");

    if (inStream.fail())
    {
        std::cerr << "Input file opening failed.\n";
        return -1;
    }

    int numTestCases;
    inStream >> numTestCases;

    for (int i = 0; i < numTestCases; i++)
    {
        ProblemSolving(inStream);
    }

    return 0;
}

void ProblemSolving(std::ifstream &inStream)
{
    std::string input;
    std::string character = "";
    std::vector<char> answer;

    inStream >> input;

    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] != '|' && input[i] != '#')
        {
            character += input[i];
        }
        else
        {
            for (int j = 0; j < 26; j++)
            {
                if (character == morse[j])
                {
                    answer.push_back(char('A' + j));
                    break;
                }
            }
            character = "";
            if (input[i] == '#')
            {
                answer.push_back('_');
            }
        }
    }
    for (int j = 0; j < 26; j++)
    {
        if (character == morse[j])
        {
            answer.push_back(char('A' + j));
            break;
        }
    }

    for (int i = 0; i < answer.size(); i++)
    {
        std::cout << answer[i];
    }
    std::cout << std::endl;
}