// Dinitz
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <cassert>
#include <queue>
#include <climits>

#define pb push_back

using namespace std;

typedef vector<vector<int>> graph;
typedef long long ll;

class Dinic
{
	struct edge
	{
		int to, rev;
		ll f, cap;
	};
	vector<ll> dist;
	vector<int> q, work;
	int n, sink;
	bool bfs(int start, int finish)
	{
		dist.assign(n, -1);
		dist[start] = 0;
		int head = 0, tail = 0;
		q[tail++] = start;
		while (head < tail) {
			int u = q[head++];
			for (const edge& e : g[u]) {
				int v = e.to;
				if (dist[v] == -1 and e.f < e.cap) {
					dist[v] = dist[u] + 1;
					q[tail++] = v;
				}
			}
		}
		return dist[finish] != -1;
	}
	ll dfs(int u, ll f)
	{
		if (u == sink)
			return f;
		for (int& i = work[u]; i < (int)g[u].size(); ++i) {
			edge& e = g[u][i];
			int v = e.to;
			if (e.cap <= e.f or dist[v] != dist[u] + 1)
				continue;
			ll df = dfs(v, min(f, e.cap - e.f));
			if (df > 0) {
				e.f += df;
				g[v][e.rev].f -= df;
				return df;
			}
		}
		return 0;
	}

	public:
	vector<vector<edge>> g;
	Dinic(int n)
	{
		this->n = n;
		g.resize(n);
		dist.resize(n);
		q.resize(n);
	}
	void add_edge(int u, int v, ll cap)
	{
		edge a = {v, (int)g[v].size(), 0, cap};
		edge b = {u, (int)g[u].size(), 0,
			0}; //Poner cap en vez de 0 si la arista es bidireccional
		g[u].pb(a);
		g[v].pb(b);
	}
	ll max_flow(int source, int dest)
	{
		sink = dest;
		ll ans = 0;
		while (bfs(source, dest)) {
			work.assign(n, 0);
			while (ll delta = dfs(source, LLONG_MAX))
				ans += delta;
		}
		return ans;
	}
};


double dist(pair<int, int> p, pair<int, int> q)
{
	int x = p.first - q.first;
	int y = p.second - q.second;
	return sqrt(x * x + y * y);
}

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		if (t != 0) {
			cout << endl;
		}
		int N, M;
		cin >> N >> M;
		vector<pair<int, int>> route(N);
		vector<pair<int, int>> interesting(M);
		// los primeros N - 1 nodos son los del lado izquierdo, es decir, las aritas en el camino del dueño.
		// los siguientes M nodos son los puntos de interés
		for (int i = 0; i < N; i++) {
			int x, y;
			cin >> x >> y;
			route[i] = {x, y};
		}
		for (int i = 0; i < M; i++) {
			int x, y;
			cin >> x >> y;
			interesting[i] = {x, y};
		}
		// (N - 1) aristas en el camino de dueño + M puntos de interes fuente + destino
		Dinic d(2 + (N - 1) + M);
		for (int i = 0; i < N - 1; i++) {
			d.add_edge((N - 1) + M, i, 1);
		}
		for (int i = 0; i < M; i++) {
			d.add_edge((N - 1) + i, N + M, 1);
		}
		for (int i = 1; i < N; i++) {
			for (int j = 0; j < M; j++) {
				double dist1 = dist(route[i - 1], interesting[j]);
				double dist2 = dist(route[i], interesting[j]);
				double dist3 = dist(route[i - 1], route[i]);
				// cout << i - 1 << ", " << i << " ; " << j << endl;
				// cout << dist1 << " + " << dist2 << " = " << dist1 + dist2 << endl;
				// cout << "straight: " << dist3 << "  " << 2*dist3 << endl;
				if (dist1 + dist2 <= 2 * dist3) {
					// cout << "adding:" << i - 1 << " " << j << endl;
					d.add_edge(i - 1, (N - 1) + j, 1);
				}
			}
		}
		cout << N + d.max_flow(N + M - 1, N + M) << endl;
		for (int i = 0; i < N - 1; i++) {
			cout << route[i].first << " " << route[i].second << " ";
			for (int j = 0; j < d.g[i].size(); j++) {
				if (d.g[i][j].f == 1) {
					// cout << "edge:" << d.g[i][j].f << endl;
					int k = d.g[i][j].to - (N - 1);
					cout << interesting[k].first << " " << interesting[k].second << " ";
					// oh oh
					// cout << interesting[j].first << " " << route[j].second << " ";
				}
			}
		}
		cout << route[N - 1].first << " " << route[N - 1].second << endl;
		// REEEEEEE
		// da WA en vez de PE si hago esto
		// cout << endl;
	}
	return 0;
}
