#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct UF {
	vector<int> P,rank;
	UF(int N) {
		P.resize(N); for(int i = 0; i < N; ++i) P[i] = i;
		rank.assign(N,0);
	}
	int findSet(int u) {
		return u == P[u] ? u : P[u] = findSet(P[u]);
	}
	bool isSameSet(int u, int v) {
		return findSet(u) == findSet(v);
	}
	void joinSets(int u, int v) {
		if(isSameSet(u,v)) return;
		u = findSet(u); v = findSet(v);
		if(rank[u] < rank[v]) P[u] = v;
		else {
			P[v] = u;
			if(rank[u] == rank[v]) ++rank[u];
		}
	}
};

int main(int argc, char const *argv[]) {
	int n;
	bool first_case = true;
	while (cin >> n) {
		if (first_case) {
			first_case = false;
		}
		else {
			puts("");
		}
		int sum = 0;
		vector<pair<int, pair<int,int>>> edges;
		for (int i = 0; i+1 < n; i++) {
			int a, b, w;
			cin >> a >> b >> w;
			sum += w;
		}
		int k;
		cin >> k;
		for (size_t i = 0; i < k; i++) {
			int a, b, w;
			cin >> a >> b >> w;
			edges.push_back({w, {a, b}});
		}
		int m;
		cin >> m;
		for (size_t i = 0; i < m; i++) {
			int a, b, w;
			cin >> a >> b >> w;
			edges.push_back({w, {a, b}});
		}
		sort(edges.begin(), edges.end());
		cout << sum << endl;
		sum = 0;
		UF uf(n);
		for (auto edge: edges) {
			int w = edge.first;
			int a = edge.second.first-1;
			int b = edge.second.second-1;
			if (not uf.isSameSet(a, b)) {
				uf.joinSets(a, b);
				sum += w;
			}
		}
		cout << sum << endl;
	}
	return 0;
}
