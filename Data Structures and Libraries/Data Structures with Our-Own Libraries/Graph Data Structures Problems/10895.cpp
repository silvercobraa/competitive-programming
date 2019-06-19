#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	int m, n;
	while (cin >> m >> n) {
		vector<vector<pair<int, int>>> transpose(n);
		for (int i = 0; i < m; i++) {
			int k;
			cin >> k;
			vector<pair<int,int>> row(k);
			for (int j = 0; j < k; j++) {
				cin >> row[j].first;
			}
			for (int j = 0; j < k; j++) {
				cin >> row[j].second;
			}
			for (auto p: row) {
				transpose[p.first-1].push_back({i, p.second});
			}
		}
		cout << n << " " << m << endl;
		for (auto v: transpose) {
			cout << v.size();
			for (auto p: v) {
				cout <<  " " << p.first+1;
			}
			cout << endl;
			for (int j = 0; j < v.size(); j++) {
				if (j != 0) {
					cout << " ";
				}
				cout << v[j].second;
			}
			cout << endl;
		}
	}
	return 0;
}
