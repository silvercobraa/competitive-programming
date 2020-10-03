#include <iostream>
#include <vector>
#include <string>

using namespace std;

int check(string& s, int k) {
	if (s[k] == 'D' or s[k] == 'B' or s[k] == 'S') return 0;
	if (k+1 < s.size() and (s[k+1] == 'B' or s[k+1] == 'S')) return 0;
	if (k+2 < s.size() and s[k+2] == 'B') return 0;
	if (k-1 >= 0 and s[k-1] == 'S') return 0;
	return 1;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	for (size_t i = 0; i < n; i++) {
		string s;
		cin >> s;
		int count = 0;
		for (int j = 0; j < s.size(); j++) {
			count += check(s, j);
		}
		printf("Case %d: %d\n", i+1, count);
	}
	return 0;
}
