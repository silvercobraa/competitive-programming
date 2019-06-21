#include <iostream>
#include <vector>
#include <string>

using namespace std;

int L, C;

vector<string> grid;
vector<vector<bool>> vis;

bool valid(int i, int j) {
	return 0 <= i and i < L and 0 <= j and j < C;
}

struct Bounds {
	int u;
	int d;
	int l;
	int r;
};

vector<pair<int, int>> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

Bounds dfs(int i, int j, char c) {
	if (vis[i][j] or grid[i][j] != c) {
		return {64, -1, 64, -1};
	}
	Bounds b;
	b.u = i;
	b.d = i;
	b.l = j;
	b.r = j;
	vis[i][j] = true;
	for (auto p: dir) {
		int x = i + p.first;
		int y = j + p.second;
		if (valid(x, y)) {
			Bounds tmp = dfs(x, y, c);
			b.u = min(b.u, tmp.u);
			b.d = max(b.d, tmp.d);
			b.l = min(b.l, tmp.l);
			b.r = max(b.r, tmp.r);
		}
	}
	return b;
}


int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		if (t != 0) {
			cout << endl;
		}
		cin >> L >> C;
		grid = vector<string>(L);
		vis = vector<vector<bool>>(L, vector<bool>(C, false));
		for (int i = 0; i < L; i++) {
			cin >> grid[i];
		}
		int sardines = 0;
		int mackerels = 0;
		int salmons = 0;
		int turtles = 0;
		int groupers = 0;
		int dolphins = 0;
		int sharks = 0;
		int whales = 0;
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < C; j++) {
				if (not vis[i][j] and grid[i][j] != '.') {
					Bounds ans = dfs(i, j, grid[i][j]);
					// printf("u:%d d:%d l:%d r:%d\n", ans.u, ans.d, ans.l, ans.r);
					int width = ans.r - ans.l + 1;
					int height = ans.d - ans.u + 1;
					// printf("i:%d, j:%d  w:%d h:%d\n", i, j, width, height);
					if (width == 1 and height == 1) {
						sardines++;
						// cout << "sardine" << endl;
					}
					else if ((width == 1 and height == 2) or (width == 2 and height == 1)) {
						mackerels++;
						// cout << "mackerel" << endl;
					}
					else if (width == 1 or height == 1) {
						salmons++;
						// cout << "salmon" << endl;
					}
					else if (width == height) {
						turtles++;
						// cout << "turtle" << endl;
					}
					else if ((width == 2 and height > 2) or (width > 2 and height == 2)) {
						groupers++;
						// cout << "grouper" << endl;
					}
					else if ((width == 3 and height > 3) or (width > 3 and height == 3)) {
						if (grid[i][j] == grid[ans.u][ans.l] and grid[i][j] == grid[ans.u][ans.r] and grid[i][j] == grid[ans.d][ans.l] and grid[i][j] == grid[ans.d][ans.r]) {
							dolphins++;
							// cout << "dolphin" << endl;
						}
						else {
							sharks++;
							// cout << "shark" << endl;
						}
					}
					else if ((width == 4 and height > 4) or (width > 4 and height == 4)) {
						whales++;
						// cout << "whale" << endl;
					}
				}
			}
		}
		printf("%d %d %d %d %d %d %d %d\n", sardines, mackerels, salmons, groupers, turtles, dolphins, whales, sharks);
	}
	return 0;
}
