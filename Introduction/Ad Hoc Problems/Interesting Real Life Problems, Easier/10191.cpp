#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int to_min(string s) {
	// cout << s << endl;
	return 60*(10*(s[0]-'0') + (s[1]-'0')) + 10*(s[3]-'0') + (s[4]-'0');
}

int main(int argc, char const *argv[]) {
	int n;
	for (int t = 1; cin >> n; t++) {
		string s;
		getline(cin, s);
		vector<pair<int, int>> v;
		for (size_t i = 0; i < n; i++) {
			getline(cin, s);
			int ti = to_min(s.substr(0, 5));
			int tf = to_min(s.substr(6, 5));
			// cout << ti << endl;
			// cout << tf << endl;
			v.push_back({ti, tf});
		}
		v.push_back({10*60, 10*60});
		v.push_back({18*60, 18*60});
		sort(v.begin(), v.end());
		int longest = 0;
		int best = 0;
		for (int i = 1; i < v.size(); i++) {
			int nap = v[i].first - v[i-1].second;
			if (nap > longest) {
				longest = nap;
				best = i;
			}
		}
		int hh = longest / 60;
		int mm = longest % 60;
		printf("Day #%d: the longest nap starts at %02d:%02d and will last for ", t, v[best-1].second/60, v[best-1].second%60);
		if (hh != 0) {
			printf("%d hours and ", hh);
		}
		printf("%d minutes.\n", mm);
	}
	return 0;
}
