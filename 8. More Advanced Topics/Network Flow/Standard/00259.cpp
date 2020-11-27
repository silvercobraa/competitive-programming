#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

constexpr int MAX = 26 + 10 + 2; // letras + numeros + source + destiny
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
      // edge& ed = EL.at(AL[u][i]);
      // // auto v = get<0>(ed);
      // auto v = get<0>(ed);
      // auto cap = get<1>(ed);
      // auto flow = get<2>(ed);
      if (d[v] != d[u]+1) continue;              // not part of layer graph
      if (ll pushed = DFS(v, t, min(f, cap-flow))) {
        // cout << "before:" << get<2>(EL[AL[u][i]]) << endl;
        flow += pushed;
        // cout << "after:" << get<2>(EL[AL[u][i]]) << endl;
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
	string s;
	max_flow flow(MAX);
	int total = 0;
	while (true) {
		getline(cin, s);
		if (cin.eof() or s == "") {
			for (int i = 0; i < 10; i++) {
				flow.add_edge(i+26+2, 1, 1);
			}
			int ans = flow.dinic(0, 1);
			if (ans != total) {
				puts("!");
			}
			else {
				for (int i = 0; i < 10; i++) {
					int id_prev = flow.parent[i + 26 + 2];
					cout << (id_prev == -1 ? '_' : char(id_prev - 2 + 'A'));
				}
				cout << endl;
			}
			flow = max_flow(MAX);
			total = 0;
			if (cin.eof()) break;
			continue;
		}
		int letter = s[0] - 'A';
		int weight = s[1] - '0';
		total += weight;
		flow.add_edge(0, letter+2, weight);
		for (int pos = 3; pos+1 < s.size(); pos++) {
			flow.add_edge(letter+2, s[pos]-'0'+26+2, 1);
		}
	}
	return 0;
}
