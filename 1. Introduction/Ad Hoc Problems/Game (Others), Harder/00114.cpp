#include <iostream>
#include <vector>

#define EMPTY (-1)
#define WALL (-2)

enum Dir {RIGHT, UP, LEFT, DOWN};

using namespace std;


int main(int argc, char const *argv[]) {
	int m, n;
	int wall_cost;
	int bumpers;
	int total_points = 0;
	cin >> m >> n >> wall_cost >> bumpers;

	vector<vector<int>> grid(m, vector<int>(n, WALL));
	// me da meno paja rellenar el cuadrado interno que iterar las murallas
	// Esto es cuadratico pero el input es chico asi que da lo mismo
	for (int i = 1; i + 1 < m; i++) {
		for (int j = 1; j + 1 < n; j++) {
			grid[i][j] = EMPTY;
		}
	}
	vector<int> value(bumpers);
	vector<int> cost(bumpers);
	vector<int> rot = {DOWN, RIGHT, UP, LEFT};
	vector<int> dx = {1, 0, -1, 0};
	vector<int> dy = {0, 1, 0, -1};

	for (size_t i = 0; i < bumpers; i++) {
		int x, y, v, c;
		cin >> x >> y >> v >> c;
		x--; y--;
		grid[x][y] = i;
		value[i] = v;
		cost[i] = c;
	}
	// for (int i = 0; i < m; i++) {
	// 	for (int j = 0; j < n; j++) {
	// 		cout << grid[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	int x, y, d, l;
	while (cin >> x >> y >> d >> l) {
		// cout << " " << x << " " << y << " " << d << " " << l << endl;
		x--; y--;
		int points = 0;
		for (l = l - 1; l > 0; l -= 1) {
			int x2 = x + dx[d];
			int y2 = y + dy[d];
			if (grid[x2][y2] == WALL) {
				d = rot[d];
				l -= wall_cost;
			}
			else if (grid[x2][y2] != EMPTY) {
				int bumper = grid[x2][y2];
				points += value[bumper];
				l -= cost[bumper];
				d = rot[d];
			}
			else {
				x += dx[d];
				y += dy[d];
			}
		}
		cout << points << endl;
		total_points += points;
	}
	cout << total_points << endl;
	return 0;
}
