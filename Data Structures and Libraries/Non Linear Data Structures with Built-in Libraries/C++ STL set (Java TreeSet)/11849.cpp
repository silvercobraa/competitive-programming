#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(int argc, char const *argv[]) {
	int n, m;
	for (cin >> n >> m; n != 0 or m != 0; cin >> n >> m) {
		set<int> sn;
		set<int> sm;
		set<int> ans;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			sn.insert(x);
		}
		for (int i = 0; i < m; i++) {
			int x;
			cin >> x;
			sm.insert(x);
		}
		set_intersection(sn.begin(), sn.end(), sm.begin(), sm.end(), inserter(ans, ans.begin()));
		cout << ans.size() << endl;
	}
	return 0;
}
