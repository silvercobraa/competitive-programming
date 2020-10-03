#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	string s;
	for (int cas = 1; cin >> s; cas++) {
		vector<vector<int>> count(s.size(), vector<int>(2, 0));
		for (int k = 0; k < s.size(); k++) {
			// cout << "adas" << int(s[k] - '0') << endl;
			count[k][int(s[k] - '0')] = 1;
			count[k][0] += k != 0 ? count[k - 1][0] : 0;
			count[k][1] += k != 0 ? count[k - 1][1] : 0;
		}
		int n;
		cin >> n;
		cout << "Case " << cas << ":" << endl;
		for (int k = 0; k < n; k++) {
			int a, b;
			cin >> a >> b;
			int i = std::min(a, b);
			int j = std::max(a, b);
			int len = j - i + 1;
			int zeros = count[j][0];
			int ones = count[j][1];
			if (i > 0) {
				zeros -= count[i - 1][0];
				ones -= count[i - 1][1];
			}
			if (zeros == len or ones == len) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}

	}
	return 0;
}
