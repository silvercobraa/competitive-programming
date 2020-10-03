#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	string s;
	getline(cin, s);
	for (int i = 0; i < n; i++) {
		if (i != 0) {
			cout << endl;
		}
		getline(cin, s);
		getline(cin, s);
		vector<int> pos;
		stringstream ss(s);
		int tmp;
		while (ss >> tmp) {
			pos.push_back(tmp);
		}
		vector<string> ans(pos.size());
		getline(cin, s);
		ss = stringstream(s);
		for (auto p: pos) {
			ss >> ans[p - 1];
		}
		for (auto x: ans) {
			cout << x << endl;
		}
	}
	return 0;
}
