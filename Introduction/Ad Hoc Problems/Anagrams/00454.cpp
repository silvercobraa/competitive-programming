#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	string s;
	getline(cin, s);
	getline(cin, s);
	for (int t = 0; t < n; t++) {
		if (t != 0) {
			cout << endl;
		}
		vector<string> v;
		for (getline(cin, s); s != ""; getline(cin, s)) {
			v.push_back(s);
		}
		sort(v.begin(), v.end());
		vector<string> sorted = v;
		for (int i = 0; i < sorted.size(); i++) {
			sort(sorted[i].begin(), sorted[i].end());
			stringstream ss(sorted[i]);
			ss >> sorted[i];
			// remove(sorted[i].begin(), sorted[i].end(), ' ');
		}
		for (size_t i = 0; i < sorted.size(); i++) {
			for (size_t j = i + 1; j < sorted.size(); j++) {
				if (sorted[i] == sorted[j]) {
					cout << v[i] << " = " << v[j] << endl;
				}
			}
		}
	}
	return 0;
}
