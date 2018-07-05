#include <iostream>
#include <fstream>
#include <cstdlib>

struct Player {
    bool Play(const int& col, int myGameBoard[6][7], int yourGameBoard[6][7]) {
        int row;
        for (int i = 5; i >= 0; i--) {
            if (myGameBoard[i][col] == 0 && yourGameBoard[i][col] == 0) {
                myGameBoard[i][col] = 1;
                row = i;
                break;
            }
        }
        int count = 0;
        for (int i = 0; i < 7; i++) {
            if (myGameBoard[row][i] == 1) {
                count++;
            }
            else {
                count = 0;
            }
            if (count >= 4) {
                return true;
            }
        }
        count = 0;
        for (int i = 0; i < 6; i++) {
            if (myGameBoard[i][col] == 1) {
                count++;
            }
            else {
                count = 0;
            }
            if (count >= 4) {
                return true;
            }
        }
        count = 0;
        int temprow = row;
        int tempcol = col;
        while (temprow != 0 && tempcol != 0) {
            temprow--;
            tempcol--;
        }
        while (temprow <= 5 && tempcol <= 6) {
            if (myGameBoard[temprow][tempcol] == 1) {
                count++;
            }
            else {
                count = 0;
            }
            temprow++;
            tempcol++;
            if (count >= 4) {
                return true;
            }
        }
        count = 0;
        temprow = row, tempcol = col;
        while (temprow != 5 && tempcol != 0) {
            temprow++;
            tempcol--;
        }
        while (temprow >= 0 && tempcol <= 6) {
            if (myGameBoard[temprow][tempcol] == 1) {
                count++;
            }
            else {
                count = 0;
            }
            temprow--;
            tempcol++;
            if (count >= 4) {
                return true;
            }
        }
        return false;
    }
};

using namespace std;

int main() {
    ifstream infile("input.txt");
    if (infile.fail()) {
        cerr << "input file opening failed\n";
        exit(1);
    }
    int numTestCases;
    infile >> numTestCases;
    for (int i = 0; i < numTestCases; i++) {
        int gameboard1[6][7] = {0};
        int gameboard2[6][7] = {0};
        Player p1, p2;
        int num;
        infile >> num;
        int j, col, winner = 0;
        for (j = 0; j < num; j++) {
            infile >> col;
            col--;
            if (j % 2 == 0) {
                if (p1.Play(col, gameboard1, gameboard2)) {
                    winner = 1;
                    break;
                }
            }
            else {
                if (p2.Play(col, gameboard2, gameboard1)) {
                    winner = 2;
                    break;
                }
            }
        }
        cout << winner << endl;
        j++;
        for (;j < num; j++) {
            infile >> col;
        }
    }
    return 0;
}


