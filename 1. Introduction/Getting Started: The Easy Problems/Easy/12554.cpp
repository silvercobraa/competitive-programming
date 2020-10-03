#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<string> v(n);
	vector<string> hb = {
		"Happy", "birthday", "to", "you",
		"Happy", "birthday", "to", "you",
		"Happy", "birthday", "to", "Rujia",
		"Happy", "birthday", "to", "you",
	};
	for (size_t i = 0; i < n; i++) {
		cin >> v[i];
	}
	int i = 0;
	int j = 0;
	for ( ; i < v.size(); i++, j++) {
		cout << v[i % v.size()] << ": " << hb[j % hb.size()] << endl;
	}
	for ( ; i % hb.size() != 0; i++, j++) {
		cout << v[i % v.size()] << ": " << hb[j % hb.size()] << endl;
	}
	return 0;
}
