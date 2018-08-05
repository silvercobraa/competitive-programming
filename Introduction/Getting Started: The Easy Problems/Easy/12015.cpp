#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		map<int, vector<string>> m;
		for (size_t j = 0; j < 10; j++) {
			string s;
			int r;
			cin >> s >> r;
			m[r].push_back(s);
		}
		cout << "Case #" << i + 1 << ":" << endl;
		for (auto s: m.rbegin()->second) {
			cout << s << endl;
		}
	}
	return 0;
}
