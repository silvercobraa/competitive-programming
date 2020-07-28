#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {
	map<int, int> root;
	for (size_t i = 0; i <= 100; i++) {
		root[i*i] = i;
	}
	int n;
	cin >> n;
	string s;
	getline(cin, s);
	for (size_t i = 0; i < n; i++) {
		getline(cin, s);
		if (root.find(s.size()) == root.end()) {
			puts("INVALID");
			continue;
		}
		int r = root[s.size()];
		for (size_t j = 0; j < r; j++) {
			for (size_t i = 0; i < r; i++) {
				cout << s[i*r + j];
			}
		}
		puts("");
	}
	return 0;
}
