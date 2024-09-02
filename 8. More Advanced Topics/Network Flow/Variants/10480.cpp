#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <map>
#include <unordered_map>

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
	vector<int> visited;

	bool BFS(int s, int t)
	{ // find augmenting path
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
				auto& e = EL[idx]; // stored in EL[idx]
				auto v = get<0>(e);
				auto cap = get<1>(e);
				auto flow = get<2>(e);
				if ((cap - flow > 0) &&
					(d[v] == -1)) // positive residual edge
					d[v] = d[u] + 1, q.push(v),
					p[v] = {u, idx}; // 3 lines in one!
			}
		}
		return d[t] != -1; // has an augmenting path
	}

	ll DFS(int u, int t, ll f = INF)
	{ // traverse from s->t
		if ((u == t) || (f == 0))
			return f;
		for (int& i = last[u]; i < (int)AL[u].size();
			++i) { // from last edge
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

	max_flow(int initialV)
		: V(initialV)
	{
		EL.clear();
		AL.assign(V, vi());
		visited.assign(V, false);
	}

	// if you are adding a bidirectional edge u<->v with weight w into your
	// flow graph, set directed = false (default value is directed = true)
	void add_edge(int u, int v, ll w, bool directed = true)
	{
		if (u == v)
			return; // safeguard: no self loop
		EL.emplace_back(v, w, 0); // u->v, cap w, flow 0
		AL[u].push_back(EL.size() - 1); // remember this index
		EL.emplace_back(u, directed ? 0 : w, 0); // back edge
		AL[v].push_back(EL.size() - 1); // remember this index
	}

	ll dinic(int s, int t)
	{
		ll mf = 0; // mf stands for max_flow
		while (BFS(s, t)) { // an O(V^2*E) algorithm
			last.assign(V, 0); // important speedup
			while (ll f = DFS(s, t)) // exhaust blocking flow
				mf += f;
		}
		return mf;
	}
	void reachables(int u)
	{
		visited[u] = true;
		for (auto edge_id : AL[u]) {
			auto& [v, cap, flow] = EL[edge_id];
			if (not visited[v] and flow < cap) {
				reachables(v);
			}
		}
	}
};


int main(int argc, char const* argv[])
{
	int n, m;
    bool first_case = true;
	for (cin >> n >> m; n != 0 or m != 0; cin >> n >> m) {
        if (first_case) {
            first_case = false;
        }
        else {
            cout << endl;
        }
		unordered_map<int, int> id;
		vector<int> original_id(50, -1);
		max_flow flow(50);
		for (size_t i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			if (id.find(a) == id.end())
				id[a] = id.size(), original_id[id[a]] = a;
			if (id.find(b) == id.end())
				id[b] = id.size(), original_id[id[b]] = b;
			int new_a = id[a];
			int new_b = id[b];
			flow.add_edge(new_a, new_b, c, false);
		}
		int mf = flow.dinic(id[1], id[2]);
		flow.reachables(id[1]);
        for (int u = 0; u < flow.AL.size(); u++)
        {
            for (auto idx : flow.AL[u])
            {
                auto& [v, cap, f] = flow.EL[idx];
                if (flow.visited[u] and not flow.visited[v])
                {
                    cout << original_id[u] << " " << original_id[v] << endl;
                }
            }
        }
	}
	return 0;
}
