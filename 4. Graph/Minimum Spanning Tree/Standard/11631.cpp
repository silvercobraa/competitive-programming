#include <iostream>
#include <vector>
#include <set>

using namespace std;

class UF {
private:
	vector<long long> id;
	vector<long long> size;
public:
	UF (long long n) {
		id.resize(n, 0);
		for (long long i = 0; i < n; i++) {
			id[i] = i;
		}
		size.resize(n, 1);
	}
	long long find(long long x) {
		return id[x] = (id[x] == x ? x : find(id[x]));
	}
	bool same(long long x, long long y) {
		return find(x) == find(y);
	}
	void merge(long long x, long long y) {
		long long xx = find(x);
		long long yy = find(y);
		if (size[xx] > size[yy]) {
			size[xx] += size[yy];
			id[yy] = xx;
		}
		else {
			size[yy] += size[xx];
			id[xx] = yy;
			// id[x] = yy; // BUGAZO
		}
	}
};

int main(int argc, char const *argv[]) {
	long long n, m;
	for (cin>>n>>m; n!=0 or m!=0; cin>>n>>m) {
		set<pair<long long,pair<long long,long long>>> pq;
		UF m3n(n);
		long long total = 0;
		long long sum = 0;
		for (long long i = 0; i < m; i++) {
			long long a, b, c;
			cin >> a >> b >> c;
			pq.insert({c, {a, b}});
			total += c;
		}
		while (not pq.empty()) {
			auto p = *pq.begin();
			pq.erase(pq.begin());
			if (not m3n.same(p.second.first, p.second.second)) {
				sum += p.first;
				m3n.merge(p.second.first, p.second.second);
			}
		}
		cout << total - sum << endl;
	}
	return 0;
}
