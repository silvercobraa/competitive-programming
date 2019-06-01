#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> grid;

bool valid(int row, int col) {
	return 0 <= row and row < 8 and 0 <= col and col < 8;
}

void print_grid() {
	for (size_t i = 0; i < grid.size(); i++) {
		cout << grid[i] << endl;
	}
}

char other(char p) {
	if (p == 'W') {
		return 'B';
	}
	else if (p == 'B') {
		return 'W';
	}
	return 'x';
}

bool check(char p, int x, int y, int dx, int dy) {
	// printf("player %c, casilla (%d,%d), direccion (%d,%d)\n", p, x, y, dx, dy);
	int count = 0;
	int x2 = x+dx;
	int y2 = y+dy;
	while (valid(x2, y2)) {
		// printf("casilla (%d,%d), valor %c\n", x2, y2, grid[x2][y2]);
		if (grid[x2][y2] == other(p)) {
			count++;
		}
		else {
			break;
		}
		x2+=dx, y2+=dy;
	}
	// cout << "count: " << count << endl;
	// cout << "valid: " << valid(x2, y2) << endl;
	// cout << "valid: " << x2 << " " << y2 << endl;
	// cout << "valid: " << grid[x2][y2] << endl;
	return count > 0 and valid(x2, y2) and grid[x2][y2] == p;
}

bool check_any(char p, int x, int y) {
	if (grid[x][y] == 'W' or grid[x][y] == 'B') {
		return false;
	}
	for (int dx = -1; dx <= 1; dx++) {
		for (int dy = -1; dy <= 1; dy++) {
			if (dx == 0 and dy == 0) {
				continue;
			}
			if (check(p, x, y, dx, dy)) {
				return true;
			}
		}
	}
	return false;
}

void print_count() {
	int b = 0;
	int w = 0;
	for (size_t i = 0; i < 8; i++) {
		for (size_t j = 0; j < 8; j++) {
			if (grid[i][j] == 'B') {
				b++;
			}
			else if (grid[i][j] == 'W') {
				w++;
			}
		}
	}
	printf("Black - %2d White - %2d\n", b, w);
}

char play(char p, int x, int y) {
	if (not check_any(p, x, y)) {
		p = other(p);
	}
	grid[x][y] = p;
	for (int dx = -1; dx <= 1; dx++) {
		for (int dy = -1; dy <= 1; dy++) {
			if (dx == 0 and dy == 0) {
				continue;
			}
			if (check(p, x, y, dx, dy)) {
				for (int i = x + dx, j = y + dy; grid[i][j] == other(p); i+=dx, j+=dy) {
					grid[i][j] = p;
				}
			}
		}
	}
	print_count();
	return other(p);
}

void list_moves(char p) {
	int count = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			// cout << "casilla " << i << " " << j << endl;
			bool can_move = check_any(p, i, j);
			if (can_move) {
				if (count != 0) {
					cout << " ";
				}
				printf("(%d,%d)", i + 1, j + 1);
				count++;
			}
		}
	}
	if (count == 0) {
		printf("No legal move.");
	}
	printf("\n");
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	for (size_t t = 0; t < n; t++) {
		if (t > 0) {
			cout << endl;
		}
		grid = vector<string>(8);
		for (size_t i = 0; i < 8; i++) {
			cin >> grid[i];
			while (grid[i].size() < 8) {
				cin >> grid[i];
			}
		}
		char player;
		cin >> player;
		string cmd;
		for (cin >> cmd; cmd != "Q"; cin >> cmd) {
			// cout << cmd << endl;
			if (cmd == "L") {
				list_moves(player);
			}
			else if(cmd[0] == 'M') {
				int x = cmd[1] - '1';
				int y = cmd[2] - '1';
				if (valid(x, y)) {
					player = play(player, x, y);
				}
				// print_grid();
			}
		}
		print_grid();
	}
	return 0;
}
