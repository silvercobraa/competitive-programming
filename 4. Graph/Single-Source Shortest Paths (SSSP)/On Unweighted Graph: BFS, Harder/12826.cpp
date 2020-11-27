#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

bool valid(pair<int, int>& pos, pair<int, int>& bad) {
	return pos != bad and 0 <= pos.first and pos.first < 8 and 0 <= pos.second and pos.second < 8;
}

int bfs(pair<int, int> start, pair<int, int> goal, pair<int, int> bad) {
	queue<pair<int, pair<int, int>>> q;
	vector<vector<bool>> visited(8, vector<bool>(8, false));
	q.push({0, start});
	visited[start.first][start.second] = true;
	while (not q.empty()) {
		auto top = q.front();
		int dist = top.first;
		pair<int, int> current = top.second;
		q.pop();
		if (current == goal) {
			return dist;
		}
		visited[current.first][current.second] = true;
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (i == 0 and j == 0) {
					continue;
				}
				pair<int, int> neigh = {current.first+i, current.second+j};
				if (valid(neigh, bad) and not visited[neigh.first][neigh.second]) {
					q.push({dist+1, neigh});
				}
			}
		}
	}
	return -1;
}

int main(int argc, char const *argv[]) {
	int r1, c1, r2, c2, r3, c3;
	for (int case_ = 1; cin >> r1 >> c1 >> r2 >> c2 >> r3 >> c3; case_++) {
		printf("Case %d: %d\n", case_, bfs({r1-1, c1-1}, {r2-1, c2-1}, {r3-1, c3-1}));
	}
	return 0;
}
