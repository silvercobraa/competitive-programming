#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	string s;
	getline(cin, s);
	for (size_t i = 0; i < n; i++) {
		getline(cin, s);
		vector<int> v;
		for (auto c: s) {
			if ('A' <= c and c <= 'Z') {
				v.push_back(2*(c - 'A'));
			}
			else {
				v.push_back(2*(c - 'a') + 1);
			}
		}
		sort(v.begin(), v.end());
		do {
			for (auto c: v) {
				if (c % 2) {
					cout << char(c / 2 + 'a');
				}
				else {
					cout << char(c / 2 + 'A');
				}
			}
			cout << endl;
		} while(next_permutation(v.begin(), v.end()));
	}
	return 0;
}
