#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int R, C, M, N, W;
vector<vector<bool>> visited;
vector<vector<bool>> water;

bool valid(int row, int col) {
	return 0 <= row and row < R and 0 <= col and col < C and not water[row][col];
}

void bfs() {
	// {even, odd}
	int valid_count[2] = {0, 0};
	queue<pair<int,int>> q;
	q.push({0, 0});
	while (not q.empty()) {
		auto parent = q.front();
		int row = parent.first;
		int col = parent.second;
		q.pop();
		set<pair<int,int>> neighs = {{row-N, col-M}, {row-M, col-N}, {row-N, col+M}, {row-M, col+N}, {row+N, col-M}, {row+M, col-N}, {row+N, col+M}, {row+M, col+N}};
		int count = 0;
		if (not visited[row][col]) {
			visited[row][col] = true;
			for (auto n: neighs) {
				// cout << row << " " << col << " " << n.first << " " << n.second << endl;
				if (valid(n.first, n.second)) {
					count++;
					if (not visited[n.first][n.second]) {
						// cout << "pusheando " << n.first << " " << n.second << endl;
						q.push(n);
					}
				}
			}
			valid_count[count % 2]++;
		}
	}
	cout << valid_count[0] << " " << valid_count[1] << endl;
}

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (size_t t = 0; t < T; t++) {
		cin >> R >> C >> M >> N >> W;
		visited = vector<vector<bool>>(R, vector<bool>(C, false));
		water = vector<vector<bool>>(R, vector<bool>(C, false));
		for (int i = 0; i < W; i++) {
			int row, col;
			cin >> row >> col;
			water[row][col] = true;
		}
		cout << "Case " << t+1 << ": ";
		bfs();
	}
	return 0;
}
