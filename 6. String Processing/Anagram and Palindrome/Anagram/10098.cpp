#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	for (size_t i = 0; i < n; i++) {
		string s;
		cin >> s;
		set<string> perms;
		sort(s.begin(), s.end());
		do {
			perms.insert(s);
		} while(next_permutation(s.begin(), s.end()));
		for (auto p: perms) {
			cout << p << endl;
		}
		cout << endl;
	}
	return 0;
}
