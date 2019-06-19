#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
	int n, m;
	vector<pair<int,int>> dij = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
	for (cin>>n>>m; n!=0 or m!=0; cin>>n>>m) {
		vector<vector<bool>> wall(n+2, vector<bool>(m+2, true));
		vector<vector<int>> count(n+2, vector<int>(m+2, 0));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				char c;
				cin >> c;
				wall[i][j] = c == '1';
			}
		}
		// for (auto v: wall) {
		// 	for (auto x: v) {
		// 		cout << x << " ";
		// 	}
		// 	cout << endl;
		// }
		// cout << endl;
		// for (auto v: count) {
		// 	for (auto x: v) {
		// 		cout << x << " ";
		// 	}
		// 	cout << endl;
		// }
		// cout << endl;
		int i = n;
		int j = 1;
		int dir = 0;
		// count[n][j]++;
		do {
			pair<int, int> front = {dij[dir].first, dij[dir].second};
			pair<int, int> left = {dij[(dir+1)%4].first, dij[(dir+1)%4].second};
			pair<int, int> back = {dij[(dir+2)%4].first, dij[(dir+2)%4].second};
			pair<int, int> right = {dij[(dir+3)%4].first, dij[(dir+3)%4].second};
			if (not wall[i+right.first][j+right.second]) {
				i += right.first;
				j += right.second;
				dir = (dir + 3) % 4;
			}
			else if (not wall[i+front.first][j+front.second]) {
				i += front.first;
				j += front.second;
				dir = (dir + 0) % 4;
			}
			else if (not wall[i+left.first][j+left.second]) {
				i += left.first;
				j += left.second;
				dir = (dir + 1) % 4;
			}
			else if (not wall[i+back.first][j+back.second]) {
				i += back.first;
				j += back.second;
				dir = (dir + 2) % 4;
			}
			// cout << i << " " << j << endl;
			count[i][j]++;
		} while (i != n or j != 1);

		// for (auto v: count) {
		// 	for (auto x: v) {
		// 		cout << x << " ";
		// 	}
		// 	cout << endl;
		// }
		// cout << endl;
		for (int k = 0; k < 5; k++) {
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (not wall[i][j] and count[i][j] == k) {
						ans++;
					}
				}
			}
			printf("%3d", ans);
		}
		cout << endl;
	}
	return 0;
}
