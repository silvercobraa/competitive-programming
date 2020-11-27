#include <iostream>
#include <string>
#include <vector>

using namespace std;

void dfs(vector<string>& v, vector<vector<bool>>& vis, int i, int j) {
	// cout << i << " " << j << endl;
	int n = v.size();
	if (0 <= i and i < n and 0 <= j and j < n and not vis[i][j] and v[i][j] == '1') {
		vis[i][j] = true;
		for (int di = -1; di <= 1; di++) {
			for (int dj = -1; dj <= 1; dj++) {
				if (di == 0 and dj == 0) {
					continue;
				}
				dfs(v, vis, i+di, j+dj);
			}
		}
	}
}

int main(int argc, char const *argv[]) {
	int n;
	int image = 1;
	for (; cin >> n; image++) {
		vector<string> v(n);
		vector<vector<bool>> vis(n, vector<bool>(n, false));
		for (size_t i = 0; i < n; i++) {
			cin >> v[i];
		}
		int eagles = 0;
		for (size_t i = 0; i < n; i++) {
			for (size_t j = 0; j < n; j++) {
				if (v[i][j] == '1' and not vis[i][j]) {
					dfs(v, vis, i, j);
					eagles++;
				}
			}
		}
		printf("Image number %d contains %d war eagles.\n", image, eagles);
	}
	return 0;
}
