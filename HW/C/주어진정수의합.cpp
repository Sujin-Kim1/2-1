#include <iostream>
#include <fstream>

void ProblemSolving(std::ifstream& inStream);

int main() {
	std::ifstream inStream;
	
	// open the input file 
	inStream.open("input.txt");

	if (inStream.fail())
	{
		std::cerr << "Input file opening failed.\n";
		return -1;
	}

	// read the number of test cases 
	int numTestCases;
	inStream >> numTestCases;

	for (int i = 0; i < numTestCases; ++i) {
		ProblemSolving(inStream);
	}

	inStream.close();

	return 0;


}

void ProblemSolving(std::ifstream& inStream) {
	int numData, data;
	inStream >> numData;

	int sum = 0;

	for (int i = 0; i < numData; ++i) {
		inStream >> data;
		sum += data;
	}
	// print out the sum
	std::cout << sum << std::endl;

}