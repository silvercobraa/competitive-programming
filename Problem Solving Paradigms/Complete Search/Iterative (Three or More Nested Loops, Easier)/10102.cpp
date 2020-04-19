#include <iostream>
#include <vector>

constexpr int INF = 99999999;

using namespace std;

int main(int argc, char const *argv[]) {
	int M;
	while (cin >> M) {
		vector<string> grid(M);
		vector<pair<int, int>> ones;
		vector<pair<int, int>> threes;
		for (int i = 0; i < M; i++) {
			cin >> grid[i];
			for (int j = 0; j < grid[i].size(); j++) {
				if (grid[i][j] == '1') {
					ones.push_back({i, j});
				}
				else if (grid[i][j] == '3') {
					threes.push_back({i, j});
				}
			}
		}
		// for (auto p: ones) {
		// 	cout << p.first << " " << p.second << endl;
		// }
		int maxmin = 0;
		for (auto one: ones) {
			int minimum = INF;
			for (auto three: threes) {
				int dist = abs(one.first - three.first) + abs(one.second - three.second);
				minimum = min(minimum, dist);
			}
			maxmin = max(maxmin, minimum);
		}
		cout << maxmin << endl;
	}
	return 0;
}
