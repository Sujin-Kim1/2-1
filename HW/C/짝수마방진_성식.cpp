#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void _4n(int n) {
    int count = 1;
    int num;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i % 4 == 0 || i % 4 == 3) {
                if (j % 4 == 0 || j % 4 == 3) {
                    num = n * n + 1 - count;
                }
                else {
                    num = count;
                }
            }
            else {
                if (j % 4 == 1 || j % 4 == 2) {
                    num = n * n + 1 - count;
                }
                else {
                    num = count;
                }
            }
            count++;
            cout << num << ' ';
        }
        cout << endl;
    }
}

void _4nplus2(int n) {
    int k = n / 4;
    int square[n][n];
    int visited[n / 2][n / 2];
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            visited[i][j] = 0;
        }
    }
    int row = 0;
    int col = k;
    char LUX = 'L';
    int caseL[4][2] = {{0, 1}, {1, 0}, {1, 1}, {0, 0}};
    int caseU[4][2] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
    int caseX[4][2] = {{0, 0}, {1, 1}, {1, 0}, {0, 1}};
    int count = 1;
    visited[0][k] = 1;
    for (int i = 0; i < (n / 2) * (n / 2); i++) {
        for (int j = 0; j < 4; j++) {
            switch(LUX) {
                case 'L':
                    square[2 * row + caseL[j][0]][2 * col + caseL[j][1]] = count;
                    break;
                case 'U':
                    square[2 * row + caseU[j][0]][2 * col + caseU[j][1]] = count;
                    break;
                case 'X':
                    square[2 * row + caseX[j][0]][2 * col + caseX[j][1]] = count;
                    break;
            }
            count++;
        }
        int temprow = (row - 1 >= 0) ? row - 1 : row + n / 2 - 1;
        int tempcol = (col + 1 < n / 2) ? col + 1 : col - n / 2 + 1;
        if (visited[temprow][tempcol]) {
            row += 1;
        }
        else {
            row = temprow;
            col = tempcol;
        }
        visited[row][col] = 1;
        if (row <= k) {
            if (row == k && col == k) {
                LUX = 'U';
            }
            else {
                LUX = 'L';
            }
        }
        else if (row == k + 1) {
            if (col == k) {
                LUX = 'L';
            }
            else {
                LUX = 'U';
            }
        }
        else {
            LUX = 'X';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << square[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    ifstream infile;
    infile.open("input.txt");
    if (infile.fail()) {
        cerr << "input file opening failed\n";
        exit(1);
    }
    int numTestCases;
    infile >> numTestCases;
    for (int i = 0; i < numTestCases; i++) {
        int n;
        infile >> n;
        switch(n % 4) {
            case 0:
                _4n(n);
                break;
            case 2:
                _4nplus2(n);
                break;
        }

    }
    return 0;
}