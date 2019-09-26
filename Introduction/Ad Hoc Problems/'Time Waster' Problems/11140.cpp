#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<string> grid;
vector<string> piece;

bool valid(int x, int y) {
	return 0 <= x and x < int(grid.size()) and 0 <= y and y < int(grid[0].size());
}

bool check_pos(int dx, int dy) {
	for (int i = 0; i < piece.size(); i++) {
		for (int j = 0; j < piece[0].size(); j++) {
			if (valid(i+dx, j+dy)) {
				if (piece[i][j] == '*' and grid[i+dx][j+dy] == '.') {
					return false;
				}
			}
			else {
				if (piece[i][j] == '*') {
					return false;
				}
			}
		}
	}
	return true;
}

bool check_piece() {
	int minrow = 1 - int(piece.size());
	int mincol = 1 - int(piece[0].size());
	int maxrow = int(grid.size());
	int maxcol = int(grid[0].size());
	// cout << minrow << " " << mincol << " " << maxrow << " " << maxcol << endl;
	for (int i = minrow; i < maxrow; i++) {
		for (int j = mincol; j < maxcol; j++) {
			if (check_pos(i, j)) {
				return true;
			}
		}
	}
	return false;
}

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (size_t t = 0; t < T; t++) {
		int n, m, p;
		cin >> n >> m >> p;
		grid = vector<string>(n);
		for (size_t i = 0; i < n; i++) {
			cin >> grid[i];
		}
		for (int i = 0; i < p; i++) {
			int h, w;
			cin >> h >> w;
			piece = vector<string>(h);
			for (int j = 0; j < h; j++) {
				cin >> piece[j];
			}
			if (check_piece()) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
		cout << endl;
	}
	return 0;
}
