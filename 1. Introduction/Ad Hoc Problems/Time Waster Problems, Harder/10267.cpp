#include <iostream>
#include <vector>

using namespace std;

std::vector<std::vector<char>> M(1);

bool check(int x, int y) {
	return 0 <= (y - 1) and (y - 1) < M.size() and 0 <= (x - 1) and (x - 1) < M[0].size();
}

void setval(int x, int y, char c) {
	if (check(x, y)) {
		M[y-1][x-1] = c;
	}
}

void fill(int x, int y, char c, char old) {
	// cout << x << " " << y << endl;
	if ((not check(x, y)) or M[y-1][x-1] != old or M[y-1][x-1] == c) {
		return;
	}
	M[y-1][x-1] = c;
	fill(x - 1, y, c, old);
	fill(x + 1, y, c, old);
	fill(x, y - 1, c, old);
	fill(x, y + 1, c, old);
}

int main(int argc, char const *argv[]) {
	char cmd;
	while (cin >> cmd) {
		// cout << cmd << endl;
		if (cmd == 'I') {
			int m, n;
			cin >> m >> n;
			M = std::vector<std::vector<char>>(n, vector<char>(m, 'O'));
		}
		else if (cmd == 'C') {
			for (size_t i = 0; i < M.size(); i++) {
				for (size_t j = 0; j < M[i].size(); j++) {
					M[i][j] = 'O';
				}
			}
		}
		else if (cmd == 'L') {
			int x, y;
			char c;
			cin >> x >> y >> c;
			setval(x, y, c);
		}
		else if (cmd == 'V') {
			int x, y1, y2;
			char c;
			cin >> x >> y1 >> y2 >> c;
			for (int j = min(y1, y2); j <= max(y1, y2); j++) {
				setval(x, j, c);
			}
		}
		else if (cmd == 'H') {
			int x1, x2, y;
			char c;
			cin >> x1 >> x2 >> y >> c;
			for (int i = min(x1, x2); i <= max(x1, x2); i++) {
				setval(i, y, c);
			}
		}
		else if (cmd == 'K') {
			int x1, x2, y1, y2;
			char c;
			cin >> x1 >> y1 >> x2 >> y2 >> c;
			for (int i = min(x1, x2); i <= max(x1, x2); i++) {
				for (int j = min(y1, y2); j <= max(y1, y2); j++) {
					setval(i, j, c);
				}
			}
		}
		else if (cmd == 'F') {
			int x, y;
			char c;
			cin >> x >> y >> c;
			if (check(x, y)) {
				fill(x, y, c, M[y-1][x-1]);
			}
		}
		else if (cmd == 'S') {
			string file;
			getline(cin, file);
			file = file.substr(1, file.size() - 1);
			cout << file << "\n";
			for (int i = 0; i < M.size(); i++) {
				for (int j = 0; j < M[i].size(); j++) {
					cout << M[i][j];
				}
				cout << endl;
			}
		}
		else if (cmd == 'X') {
			break;
		}
	}
	return 0;
}
