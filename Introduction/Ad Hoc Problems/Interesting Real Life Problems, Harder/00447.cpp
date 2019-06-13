#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<vector<vector<char>>> v(2, vector<vector<char>>(20, vector<char>(20, ' ')));

void print(int k) {
	for (auto vv: v[k]) {
		for (auto x: vv) {
			cout << x;
		}
		cout << endl;
	}
	cout << "********************" << endl;
}

bool valid(int i, int j) {
	return 0 <= i and i < 20 and 0 <= j and j < 20;
}

int neighs(int k, int x, int y) {
	int ret = 0;
	for (int i = x-1; i <= x+1; i++) {
		for (int j = y-1; j <= y+1; j++) {
			if (i == x and j == y) {
				continue;
			}
			if (valid(i, j) and v[k][i][j] == 'O') {
				ret++;
			}
		}
	}
	return ret;
}

void next_year(int source, int dest) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			int count = neighs(source, i, j);
			// cout << count;
			if (v[source][i][j] == 'O') {
				if (count == 2 or count  == 3) {
					v[dest][i][j] = 'O';
				}
				else {
					v[dest][i][j] = ' ';
				}
			}
			else {
				if (count == 3) {
					v[dest][i][j] = 'O';
				}
				else {
					v[dest][i][j] = ' ';
				}
			}
		}
		// cout << endl;
	}
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	for (int t = 0; t < n; t++) {
		if (t != 0) {
			cout << endl;
		}
		cout << "********************" << endl;
		v = vector<vector<vector<char>>>(2, vector<vector<char>>(20, vector<char>(20, ' ')));
		int y;
		cin >> y;
		string s;
		getline(cin, s);
		for (getline(cin, s); s != ""; getline(cin, s)) {
			int x, y;
			stringstream ss(s);
			ss >> x >> y;
			x--; y--;
			v[0][x][y] = 'O';
		}
		print(0);
		for (int i = 1; i < y; i++) {
			next_year(1 - i%2, i%2);
			print(i%2);
		}
	}
	return 0;
}
