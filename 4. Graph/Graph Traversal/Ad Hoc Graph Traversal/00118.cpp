// César Bolívar Severino
// resuelto propio
#include <iostream>
#include <map>

using namespace std;

// esto pude haberlo echo con un arreglo circular, o con puros ifs, pero
// quería ver si podía inicializar un map de esta manera
map<char, map<char, char>> m = {
	{'N', {{'L', 'W'}, {'R', 'E'}}},
	{'S', {{'L', 'E'}, {'R', 'W'}}},
	{'E', {{'L', 'N'}, {'R', 'S'}}},
	{'W', {{'L', 'S'}, {'R', 'N'}}}
};

int main(int argc, char const* argv[])
{
	int xn, yn;
	cin >> xn >> yn;
	int x, y;
	bool grid[xn + 1][yn + 1];
	char dir;
	while (cin >> x >> y >> dir) {
		bool lost = false;
		// cout << x << ' ' << y << ' ' << dir << endl;
		string s;
		cin >> s;
		// cout << s << endl;
		// muchos ifs aca abajo
		for (auto c: s) {
			if (c != 'F') { dir = m[dir][c]; }
			else {
				if (dir == 'N') {
					if (y == yn) { lost = !grid[x][y]; }
					else { y++; }
				}
				else if (dir == 'S') {
					if (y == 0) { lost = !grid[x][y]; }
					else { y--; }
				}
				else if (dir == 'E') {
					if (x == xn) { lost = !grid[x][y]; }
					else { x++; }
				}
				else if (dir == 'W') {
					if (x == 0) { lost = !grid[x][y]; }
					else { x--; }
				}
			}
			if (lost) {grid[x][y] = true; break; }
		}
		cout << x << ' ' << y << ' ' << dir;
		if (lost) {
			cout << " LOST";
		}
		cout << endl;
	}
	return 0;
}
