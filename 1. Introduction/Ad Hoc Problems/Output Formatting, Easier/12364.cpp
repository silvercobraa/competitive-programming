#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    vector<vector<string>> braille {
        {
            ".*",
            "**",
            "..",
        },
        {
            "*.",
            "..",
            "..",
        },
        {
            "*.",
            "*.",
            "..",
        },
        {
            "**",
            "..",
            "..",
        },
        {
            "**",
            ".*",
            "..",
        },
        {
            "*.",
            ".*",
            "..",
        },
        {
            "**",
            "*.",
            "..",
        },
        {
            "**",
            "**",
            "..",
        },
        {
            "*.",
            "**",
            "..",
        },
        {
            ".*",
            "*.",
            "..",
        },
    };
    map<string, int> decimal {
        {".***", 0},
        {"*...", 1},
        {"*.*.", 2},
        {"**..", 3},
        {"**.*", 4},
        {"*..*", 5},
        {"***.", 6},
        {"****", 7},
        {"*.**", 8},
        {".**.", 9},
    };
    for (cin >> n; n != 0; cin >> n) {
        char c;
        cin >> c;
        if (c == 'S') {
            string digits; 
            cin >> digits;
            vector<string> output(3, string(3*n - 1, ' '));
            for (int digit_pos = 0; digit_pos < digits.size(); digit_pos++) {
                int digit = digits[digit_pos] - '0';
                for (int row = 0; row < 3; row++) {
                    for (int col = 0; col < 2; col++) {
                        output[row][3*digit_pos + col] = braille[digit][row][col];
                    }
                }
            }
            for (auto& s: output) {
                cout << s << endl;
            }
        }
        else if  (c == 'B') {
            vector<string> input(3);
            string line;
            getline(cin, line);
            for (int k = 0; k  < 3; k++) {
                getline(cin, input[k]);
            }
            for (int k = 0; k < n; k++) {
                string first_row = input[0].substr(3*k, 2);
                string second_row = input[1].substr(3*k, 2);
                // cout << first_row + second_row << endl;
                cout << decimal[first_row + second_row];
            }
            cout << endl;
        }
    }
}