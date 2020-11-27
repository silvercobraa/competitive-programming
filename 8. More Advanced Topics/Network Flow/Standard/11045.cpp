#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <map>

using namespace std;

constexpr int INF = 1000000000;
typedef long long ll;
typedef tuple<int, ll, ll> edge;
typedef vector<int> vi;
typedef pair<int, int> ii;


class max_flow {
public:
  int V;
  vector<edge> EL;
  vector<vi> AL;
  vi d, last;
  vector<ii> p;
  vi parent;

  bool BFS(int s, int t) {                       // find augmenting path
    d.assign(V, -1); d[s] = 0;
    queue<int> q({s});
    p.assign(V, {-1, -1});                       // record BFS sp tree
    while (!q.empty()) {
      int u = q.front(); q.pop();
      if (u == t) break;                         // stop as sink t reached
      for (auto &idx : AL[u]) {                  // explore neighbors of u
        auto &e = EL[idx];          // stored in EL[idx]
        auto v = get<0>(e);
		auto cap = get<1>(e);
		auto flow = get<2>(e);
        if ((cap-flow > 0) && (d[v] == -1))      // positive residual edge
          d[v] = d[u]+1, q.push(v), p[v] = {u, idx}; // 3 lines in one!
      }
    }
    return d[t] != -1;                           // has an augmenting path
  }

  ll DFS(int u, int t, ll f = INF) {             // traverse from s->t
    if ((u == t) || (f == 0)) return f;
    for (int &i = last[u]; i < (int)AL[u].size(); ++i) { // from last edge
      auto &[v, cap, flow] = EL[AL[u][i]];
      if (d[v] != d[u]+1) continue;              // not part of layer graph
      if (ll pushed = DFS(v, t, min(f, cap-flow))) {
        flow += pushed;
		if (pushed > 0) parent[v] = u;
        auto &rflow = get<2>(EL[AL[u][i]^1]);     // back edge
        rflow -= pushed;
        return pushed;
      }
    }
    return 0;
  }

  max_flow(int initialV) : V(initialV) {
    EL.clear();
    AL.assign(V, vi());
	parent.assign(V, -1);
  }

  // if you are adding a bidirectional edge u<->v with weight w into your
  // flow graph, set directed = false (default value is directed = true)
  void add_edge(int u, int v, ll w, bool directed = true) {
    if (u == v) return;                          // safeguard: no self loop
    EL.emplace_back(v, w, 0);                    // u->v, cap w, flow 0
    AL[u].push_back(EL.size()-1);                // remember this index
    EL.emplace_back(u, directed ? 0 : w, 0);     // back edge
    AL[v].push_back(EL.size()-1);                // remember this index
  }

  ll dinic(int s, int t) {
    ll mf = 0;                                   // mf stands for max_flow
    while (BFS(s, t)) {                          // an O(V^2*E) algorithm
      last.assign(V, 0);                         // important speedup
      while (ll f = DFS(s, t))                   // exhaust blocking flow
        mf += f;
    }
    return mf;
  }
};

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	map<string,int> map_ = {{"XXL", 0}, {"XL", 1}, {"L", 2}, {"M", 3}, {"S", 4}, {"XS", 5}};
	for (size_t t = 0; t < T; t++) {
		int n, m;
		cin >> n >> m;
		max_flow flow(6 + m + 2);
		for (int i = 0; i < 6; i++) {
			flow.add_edge(0, i+2, n/6);
		}
		for (size_t i = 0; i < m; i++) {
			string s1, s2;
			cin >> s1 >> s2;
			if (map_[s1] > map_[s2]) {
				swap(s1, s2);
			}
			flow.add_edge(map_[s1]+2, i+6+2, 1);
			flow.add_edge(map_[s2]+2, i+6+2, 1);
		}
		for (int i = 0; i < m; i++) {
			flow.add_edge(i+6+2, 1, 1);
		}
		int ans = flow.dinic(0, 1);
		puts(ans >= m ? "YES" : "NO");
	}
	return 0;
}
