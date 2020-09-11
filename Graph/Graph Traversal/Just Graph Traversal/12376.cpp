#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (size_t t = 0; t < T; t++) {
		int n, m;
		cin >> n >> m;
		vector<int> value(n);
		vector<set<pair<int,int>>> graph(n);
		for (size_t i = 0; i < n; i++) {
			cin >> value[i];
		}
		for (size_t i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			graph[a].insert({value[b], b});
		}
		// node zero can reach every node
		// for (size_t i = 1; i < n; i++) {
		// 	graph[0].insert({value[i], i});
		// }
		int node = 0;
		int learning = 0;
		while (not graph[node].empty()) {
			auto p = *graph[node].rbegin();
			learning += p.first;
			node = p.second;
		}
		cout << "Case " << t+1 << ": " << learning << " " << node << endl;
	}
	return 0;
}
