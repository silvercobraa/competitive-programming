// César Bolívar Severino
// resuelto propio
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char const* argv[])
{
	int t;
	cin >> t;
	// cout << "t: " << t << endl;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		// cout << "n: " << n << endl;
		int result = 0;
		set<int> s;
		vector<int> v;
		for (int j = 0; j < n; j++) {
			int k;
			cin >> k;
			// cout << "k: " << k << endl;
			v.push_back(k);
		}
		int j = 0;
		while (j < n) {
			if (s.find(v[j]) != s.end()) {
				int l = j - 1;
				while (l >= 0 && v[l] != v[j]) {
					l--;
				}
				// cout << "i: " << i << "  l: " << l << endl;
				j = l + 1;
				s.clear();
			}
			s.insert(v[j]);
			result = max(result, int(s.size()));
			j++;
		}
		cout << result << endl;
	}
	return 0;
}
