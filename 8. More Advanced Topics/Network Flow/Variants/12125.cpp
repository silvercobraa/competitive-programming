#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

constexpr int INF = 1000000000;
typedef long long ll;
typedef tuple<int, ll, ll> edge;
typedef vector<int> vi;
typedef pair<int, int> ii;


class max_flow
{
	public:
	int V;
	vector<edge> EL;
	vector<vi> AL;
	vi d, last;
	vector<ii> p;

	bool BFS(int s, int t) { // find augmenting path
		d.assign(V, -1);
		d[s] = 0;
		queue<int> q({s});
		p.assign(V, {-1, -1}); // record BFS sp tree
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (u == t)
				break; // stop as sink t reached
			for (auto& idx : AL[u]) { // explore neighbors of u
				auto& [v, cap, flow] = EL[idx];
				if ((cap - flow > 0) &&
					(d[v] == -1)) // positive residual edge
					d[v] = d[u] + 1, q.push(v),
					p[v] = {u, idx}; // 3 lines in one!
			}
		}
		return d[t] != -1; // has an augmenting path
	}

	ll DFS(int u, int t, ll f = INF) { // traverse from s->t
		if ((u == t) || (f == 0))
			return f;
		for (int& i = last[u]; i < (int)AL[u].size(); ++i) { // from last edge
			auto& [v, cap, flow] = EL[AL[u][i]];
			if (d[v] != d[u] + 1)
				continue; // not part of layer graph
			if (ll pushed = DFS(v, t, min(f, cap - flow))) {
				flow += pushed;
				auto& rflow = get<2>(EL[AL[u][i] ^ 1]); // back edge
				rflow -= pushed;
				return pushed;
			}
		}
		return 0;
	}

	max_flow(int initialV) : V(initialV) {
		EL.clear();
		AL.assign(V, vi());
	}

	// if you are adding a bidirectional edge u<->v with weight w into your
	// flow graph, set directed = false (default value is directed = true)
	void add_edge(int u, int v, ll w, bool directed = true) {
		if (u == v)
			return; // safeguard: no self loop
		EL.emplace_back(v, w, 0); // u->v, cap w, flow 0
		AL[u].push_back(EL.size() - 1); // remember this index
		EL.emplace_back(u, directed ? 0 : w, 0); // back edge
		AL[v].push_back(EL.size() - 1); // remember this index
	}

	ll dinic(int s, int t) {
		ll mf = 0; // mf stands for max_flow
		while (BFS(s, t)) { // an O(V^2*E) algorithm
			last.assign(V, 0); // important speedup
			while (ll f = DFS(s, t)) // exhaust blocking flow
				mf += f;
		}
		return mf;
	}
};

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (size_t t = 0; t < T; t++) {
		int n;
		double m;
		cin >> n >> m;
		vector<ii> coord(n);
		vector<ii> possible_steps;
		vi initial(n, -1);
		vi maximum(n, -1);
		int total = 0;
		for (size_t i = 0; i < n; i++) {
			int xi, yi, ni, mi;
			cin >> xi >> yi >> ni >> mi;
			coord[i] = {xi, yi};
			initial[i] = ni;
			maximum[i] = mi;
			total += ni;
		}
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				auto& [xi, yi] = coord[i];
				auto& [xj, yj] = coord[j];
				if ((xi-xj)*(xi-xj) + (yi-yj)*(yi-yj) <= m*m) {
					possible_steps.push_back({i, j});
				}
			}
		}
		// for (auto p: possible_steps) {
		// 	cout << p.first << " " << p.second << endl;
		// }
		vi solution;
		for (int dest = 0; dest < n; dest++) {
			max_flow flow(2*n + 1); // node splitting + source
			for (int i = 0; i < n; i++) {
				flow.add_edge(2*n, i, initial[i]); // arcos de source a primer nodo por cada id
				flow.add_edge(i, i+n, maximum[i]); // arcos de primer a segundo nodo por cada id
				// cout << 2*n << " " <<  i << " " << initial[i] << endl;
				// cout << i << " " <<  i+n << " " << maximum[i] << endl;
			}
			for (auto p: possible_steps) {
				flow.add_edge(p.first+n, p.second, INF); // arcos entre nodos con ids distintos
				flow.add_edge(p.second+n, p.first, INF);
				// cout << p.first+n << " " <<  p.second << " " << INF << endl;
				// cout << p.second+n << " " <<  p.first << " " << INF << endl;
			}
			int mf = flow.dinic(2*n, dest);
			// cout << " max flow: " << mf << endl;
			if (mf == total) {
				solution.push_back(dest);
			}
		}
		if (solution.empty()) {
			puts("-1");
		}
		else {
			for (int i = 0; i < solution.size(); i++) {
				if (i != 0) cout << " ";
				cout << solution[i];
			}
			cout << endl;
		}
	}
	return 0;
}
