#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool find_word(vector<vector<char> > &vec, string &str) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            for (int direction = 0; direction < 8; direction++) {
                int k;
                for (k = 0; k < str.size(); k++) {
                    if (direction == 0 && i - k >= 0 && vec[i - k][j] == str[k]) {
                        continue;
                    } else if (direction == 1 && i - k >= 0 && j + k < vec[i].size() && vec[i - k][j + k] == str[k]) {
                        continue;
                    } else if (direction == 2 && j + k < vec[i].size() && vec[i][j + k] == str[k]) {
                        continue;
                    } else if (direction == 3 && i + k < vec.size() && j + k < vec[i].size() &&
                               vec[i + k][j + k] == str[k]) {
                        continue;
                    } else if (direction == 4 && i + k < vec.size() && vec[i + k][j] == str[k]) {
                        continue;
                    } else if (direction == 5 && i + k < vec.size() && j - k >= 0 && vec[i + k][j - k] == str[k]) {
                        continue;
                    } else if (direction == 6 && j - k >= 0 && vec[i][j - k] == str[k]) {
                        continue;
                    } else if (direction == 7 && i - k >= 0 && j - k >= 0 && vec[i - k][j - k] == str[k]) {
                        continue;
                    } else {
                        break;
                    }
                }
                if (str.size() == k) {
                    cout << i + 1 << " " << j + 1 << " " << direction << endl;
                    return true;
                }
            }
        }
    }
    // not found
    return false;
}

int main() {
    ifstream infile("input.txt");
    int numTestCases;
    infile >> numTestCases;
    for (int n = 0; n < numTestCases; n++) {
        vector<vector<char> > vec;
        unsigned row_size, col_size;
        infile>> row_size >> col_size;
        vec.resize(row_size);
        for (int i = 0; i < row_size; i++) {
            vec[i].resize(col_size);
            string str;
            infile >> str;
            for (int j = 0; j < col_size; j++) {
                vec[i][j] = str[j];
            }
        }

        int word_num;
        infile>> word_num;
        for (int i = 0; i < word_num; i++) {
            string str;
            infile >> str;
            if (!find_word(vec, str)) {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}