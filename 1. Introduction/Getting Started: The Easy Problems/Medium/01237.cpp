#include <iostream>
#include <map>
#include <utility>

using namespace std;

string ans(map<string,pair<int,int>>& m, int x) {
	string ret = "UNDETERMINED";
	for (auto p: m) {
		if (p.second.first <= x and x <= p.second.second) {
			if (ret == "UNDETERMINED") {
				ret = p.first;
			}
			else {
				return "UNDETERMINED";
			}
		}
	}
	return ret;
}

int main(int argc, char const *argv[]) {
	int T;
	cin >> T;
	for (size_t i = 0; i < T; i++) {
		if (i != 0) {
			cout << endl;
		}
		int n;
		cin >> n;
		map<string,pair<int,int>> m;
		for (size_t j = 0; j < n; j++) {
			string s;
			int l, r;
			cin >> s >> l >> r;
			m[s] = {l, r};
		}
		int q;
		cin >> q;
		for (size_t j = 0; j < q; j++) {
			int x;
			cin >> x;
			cout << ans(m, x) << endl;
		}
	}
	return 0;
}
