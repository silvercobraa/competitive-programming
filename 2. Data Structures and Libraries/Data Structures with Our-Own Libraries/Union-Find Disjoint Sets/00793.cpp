#include <iostream>
#include <vector>
#include <sstream>
#include <string>

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
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		if (t != 0) {
			cout << endl;
		}
		int n;
		cin >> n;
		UF men(n);
		int succ = 0;
		int unsucc = 0;
		string s;
		getline(cin, s);
		for (getline(cin, s); s != ""; getline(cin, s)) {
			stringstream ss(s);
			char c;
			int x, y;
			ss >> c >> x >> y;
			if (c == 'c') {
				men.joinSets(x-1, y-1);
			}
			else if (c == 'q') {
				auto ret = men.isSameSet(x-1, y-1);
				if (ret) {
					succ++;
				}
				else {
					unsucc++;
				}
			}
		}
		cout << succ << "," << unsucc << endl;
	}
	return 0;
}
