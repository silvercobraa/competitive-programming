#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Sudoku {
    public:
    int n;
    int n2;
    vector<int> board;
    vector<vector<bool>> rows;
    vector<vector<bool>> cols;
    vector<vector<bool>> boxes;

    Sudoku(int n) {
        this->n = n;
        this->n2 = n * n;
        rows = vector<vector<bool>>(n2, vector<bool>(n2+1, false));
        cols = vector<vector<bool>>(n2, vector<bool>(n2+1, false));
        boxes = vector<vector<bool>>(n2, vector<bool>(n2+1, false));
        board = vector<int>(n2 * n2, 0);
        for (int i = 0; i < n2; ++i) {
            for (int j = 0; j < n2; ++j) {
                int value;
                cin >> value;
                board[n2*i + j] = value;
                rows[i][value] = true;
                cols[j][value] = true;
                boxes[n*(i/n) + (j/n)][value] = true;
            }
        }
    }
    void print() {
        for (int i = 0; i < n2; ++i) {
            for (int j = 0; j < n2; ++j) {
                if (j != 0) {
                    cout << " ";
                }
                cout << this->board[n2*i + j];
            }
            cout << "\n";
        }
        // cout << "\n"; // todo: descomentar
    }
    
    bool backtrack() {
        return backtrack(n2*n2, 0);
    }
    bool backtrack(int n4, int k) {
        // print();
        // cout << k << " " << n4 << endl;
        if (k == n4) {
            return true;
        }
        if (board[n2*(k/n2) + (k%n2)] != 0) {
            return backtrack(n4, k + 1);
        }
        for (int value = 1; value <= n2; ++value) {
            int row = k / n2;
            int col = k % n2;
            int box = n * (row / n) + (col / n);
            // cout << row << " " << col << " " << box << endl;
            if (not (rows[row][value] or cols[col][value] or boxes[box][value])) {
                rows[row][value] = true;
                cols[col][value] = true;
                boxes[box][value] = true;
                board[n2*row + col] = value;
                // print();
                if (backtrack(n4, k + 1)) {
                    return true;
                }
                rows[row][value] = false;
                cols[col][value] = false;
                boxes[box][value] = false;
                board[n2*row + col] = 0;
            }
        }
        return false;
    }
};

int main() {
    int n;
    bool first = true;
    while (cin >> n) {
        if (first) {
            first = false;
        }
        else {
            cout << "\n";
        }
        auto sudoku = Sudoku(n);
        bool solution = sudoku.backtrack();
        if (solution) {
            sudoku.print();
        }
        else {
            cout << "NO SOLUTION\n";
        }
    }
}
