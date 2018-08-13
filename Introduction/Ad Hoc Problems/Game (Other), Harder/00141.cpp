#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

vector<vector<bool>> rot90(vector<vector<bool>> state) {
	vector<vector<bool>> ret(state.size(), vector<bool>(state.size(), false));
	for (int i = 0; i < state.size(); i++) {
		for (int j = 0; j < state.size(); j++) {
			ret[i][j] = state[state.size() - j - 1][i];
		}
	}
	return ret;
}

void print(vector<vector<bool>>& v) {
	for (auto row:v) {
		for (auto col: row) {
			cout << col;
		}
		cout << endl;
	}
	cout << endl;
}
int main(int argc, char const *argv[]) {
	int n;
	for (cin >> n; n != 0; cin >> n) {
		set<vector<vector<bool>>> vis;
		vector<vector<bool>> state(n, vector<bool>(n, false));
		int move = -1;
		for (size_t i = 0; i < 2*n; i++) {
			int x, y;
			char c;
			cin >> x >> y >> c;
			// hay que leer de todas maneras, asi que no hacer break
			if (move != -1) {
				continue;
			}
			x--;
			y--;
			for (size_t k = 0; k < 4; k++) {
				vis.insert(state);
				// print(state);
				state = rot90(state);
			}
			if (c == '+') {
				state[x][y] = true;
			}
			else if (c == '-') {
				state[x][y] = false;
			}
			if (vis.find(state) != vis.end()) {
				move = i;
			}
		}
		if (move == -1) {
			cout << "Draw" << endl;
		}
		else {
			// 2 si move es par, 1 si es impar
			int winner = 2 - (move % 2);
			cout << "Player " << winner << " wins on move " << move + 1 << endl;
		}
	}
	return 0;
}
