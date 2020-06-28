#include <iostream>
#include <vector>
#include <string>

using namespace std;

void dfs(vector<string>& grid, int row, int col) {
	if (0 <= row and row < grid.size() and 0 <= col and col < grid[row].size() and grid[row][col] == ' ') {
		grid[row][col] = '#';
		dfs(grid, row - 1, col);
		dfs(grid, row + 1, col);
		dfs(grid, row, col - 1);
		dfs(grid, row, col + 1);
	}
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	string s;
	getline(cin, s);
	for (size_t t = 0; t < n; t++) {
		vector<string> grid;
		int row = 0;
		int col = 0;
		int i = 0;
		for (getline(cin, s); s[0] != '_'; getline(cin, s)) {
			grid.push_back(s);
			for (size_t j = 0; j < s.size(); j++) {
				if (s[j] == '*') {
					row = i;
					col = j;
				}
			}
			i++;
		}
		grid[row][col] = ' ';
		dfs(grid, row, col);
		for (auto s: grid) {
			cout << s << endl;
		}
		cout << s << endl;
	}
	return 0;
}
