#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m;

vector<string> grid;
vector<pair<int, int>> direction = {
	{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1},
};

bool valid(int x, int y) {
	return 0 <= x and x < n and 0 <= y and y < m;
}

bool search_dir(string& word, int x, int y, int dx, int dy) {
	for (int k = 0; k < word.size(); k++) {
		if (not valid(x+k*dx, y+k*dy) or word[k] != grid[x+k*dx][y+k*dy]) {
			return false;
		}
	}
	return true;
}

void search(string& word) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (auto dir: direction) {
				if (search_dir(word, i, j, dir.first, dir.second)) {
					cout << i+1 << " " << j+1 << endl;
					return;
				}
			}
		}
	}
}

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (size_t t = 0; t < T; t++) {
		if (t != 0) {
			cout << endl;
		}
		cin >> n >> m;
		grid = vector<string>(n);
		for (size_t i = 0; i < n; i++) {
			cin >> grid[i];
			for (int j = 0; j < m; j++) {
				if ('A' <= grid[i][j] and grid[i][j] <= 'Z') {
					grid[i][j] = grid[i][j] - 'A' + 'a';
				}
			}
		}
		int words;
		cin >> words;
		for (size_t i = 0; i < words; i++) {
			string word;
			cin >> word;
			for (int j = 0; j < word.size(); j++) {
				if ('A' <= word[j] and word[j] <= 'Z') {
					word[j] = word[j] - 'A' + 'a';
				}
			}
			search(word);
		}
	}
	return 0;
}
