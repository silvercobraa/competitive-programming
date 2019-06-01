#include <iostream>
#include <vector>

#define EMPTY (-1)

using namespace std;

int m, n;
int nonempty;

bool valid(int row, int col) {
	return 0 <= row and row < m and 0 <= col and col < n;
}

void remove(vector<vector<int>>& grid, int val, int row, int col) {
	if (not valid(row, col) or grid[row][col] == EMPTY) {
		return;
	}
	if (grid[row][col] == val) {
		// printf("(%d, %d) ", row, col);
		grid[row][col] = EMPTY;
		nonempty--;
		remove(grid, val, row - 1, col);
		remove(grid, val, row + 1, col);
		remove(grid, val, row, col - 1);
		remove(grid, val, row, col + 1);
	}
}

void drop(vector<vector<int>>& grid) {
	for (size_t j = 0; j < n; j++) {
		for (int i = 0; i < m; i++) {
			if (grid[i][j] != EMPTY) {
				continue;
			}
			int k = i + 1;
			for ( ; k < m and grid[k][j] == EMPTY; k++) {
			}
			if (k < m) {
				grid[i][j] = grid[k][j];
				grid[k][j] = EMPTY;
			}
		}
	}
}


void shift(vector<vector<int>>& grid) {
	for (size_t j = 0; j < n; j++) {
		if (grid[0][j] != EMPTY) {
			continue;
		}
		int k = j + 1;
		for ( ; k < n and grid[0][k] == EMPTY; k++) {
		}
		if (k < n) {
			for (size_t i = 0; i < m; i++) {
				grid[i][j] = grid[i][k];
				grid[i][k] = EMPTY;
			}
		}
	}
}

void print_grid(vector<vector<int>>& grid) {
	cout << endl;
	for (size_t i = 0; i < m; i++) {
		for (size_t j = 0; j < n; j++) {
			cout << grid[m - i - 1][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main(int argc, char const *argv[]) {
	int count = 1;
	for (cin >> m >> n; m != 0 and n != 0; cin >> m >> n) {
		if (count != 1) {
			cout << endl;
		}
		vector<vector<int>> grid(m, vector<int>(n, EMPTY));
		vector<pair<int, int>> sel;

		for (size_t i = 0; i < m; i++) {
			for (size_t j = 0; j < n; j++) {
				cin >> grid[i][j];
			}
		}
		// print_grid(grid);
		int row, col = 0;
		nonempty = n * m;
		for (cin >> row >> col; row != 0 or col != 0; cin >> row >> col) {
			sel.push_back({row, col});
		}
		for (auto p: sel) {
			if (nonempty == 0) {
				break;
			}
			row = p.first - 1;
			col = p.second - 1;
			// cout << "row col: " << row << " " << col << endl;
			if (row >= m or col >= n) {
				continue;
			}
			if ((valid(row + 1, col) and grid[row][col] == grid[row + 1][col]) or (valid(row - 1, col) and grid[row][col] == grid[row - 1][col]) or (valid(row, col + 1) and grid[row][col] == grid[row][col + 1]) or (valid(row, col - 1) and grid[row][col] == grid[row][col - 1])) {
				remove(grid, grid[row][col], row, col);
			}
			// cout << "\nremove";
			// print_grid(grid);
			drop(grid);
			// cout << "drop";
			// print_grid(grid);
			shift(grid);
			// cout << "shift";
			// print_grid(grid);
		}
		cout << "Grid " << count << "." << endl;
		if (nonempty == 0) {
			cout << "    Game Won" << endl;
		}
		else {
			for (int i = 0; i < m; i++) {
				cout << "   ";
				for (int j = 0; j < n; j++) {
					if (grid[m - i - 1][j] != -1) {
						cout << " " << grid[m - i - 1][j];
					}
					else {
						cout << "  ";
					}
				}
				cout << endl;
			}
		}
		count++;
	}
	return 0;
}
