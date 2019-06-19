// César Bolívar Severino
// resuelto propio
#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<char, map<char, char>> m = {
	{'N', {{'E', 'O'}, {'D', 'L'}}},
	{'S', {{'E', 'L'}, {'D', 'O'}}},
	{'L', {{'E', 'N'}, {'D', 'S'}}},
	{'O', {{'E', 'S'}, {'D', 'N'}}}
};

char find_pos(vector<string>& g, int& x, int& y) {
	for (int i = 0; i < g.size(); i++) {
		for (int j = 0; j < g[i].size(); j++) {
			char c = g[i][j];
			if (c != '.' && c != '*' && c != '#') {
				x = i;
				y = j;
				g[i][j] = '.';
				return c;
			}
		}
	}
}

int main(int argc, char const* argv[])
{
	int N, M, S;
	cin >> N >> M >> S;
	while (N != 0 || M != 0 || S != 0) {
		vector<string> g(N);
		string instr;
		int x, y;
		char dir;
		int result = 0;
		for (int i = 0; i < N; i++) {
			cin >> g[i];
		}
		dir = find_pos(g, x, y);
		// cout << x << ' ' << y << endl;
		cin >> instr;
		// for (int i = 0; i < g.size(); i++) {
		// 	cout << g[i] << endl;
		// }
		for (auto c: instr) {
			if (c != 'F') {
				dir = m[dir][c];
			}
			else {
				if (dir == 'N') {
					if (x != 0) {
						x--;
						if (g[x][y] == '#') { x++; }
					}
				}
				else if (dir == 'S') {
					if (x != N - 1) {
						x++;
						if (g[x][y] == '#') { x--; }
					}
				}
				else if (dir == 'L') {
					if (y != M - 1) {
						y++;
						if (g[x][y] == '#') { y--; }
					}
				}
				else if (dir == 'O') {
					if (y != 0) {
						y--;
						if (g[x][y] == '#') { y++; }
					}
				}
			}
			if (g[x][y] == '*') {
				result++;
				g[x][y] = '.';
			}
			// cout << "xy: " << x << ' ' << y << endl;
		}
		// cout << "dir: " << dir << endl;
		// cout << "result: " << result << endl;
		// cout << instr << endl;
		cout << result << endl;
		cin >> N >> M >> S;
	}
	return 0;
}
