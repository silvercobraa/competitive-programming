#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	for (cin >> n; n != 0; cin >> n) {
		string s;
		cin >> s;
		// cout << s << endl;
		int r = -1;
		int d = -1;
		int min = 1e9;
		for (size_t j = 0; j < s.size(); j++) {
			if (s[j] == 'R') {
				r = j;
			}
			else if (s[j] == 'D') {
				d = j;
			}
			else if (s[j] == 'Z') {
				r = d = j;
			}
			if (r != -1 and d != -1) {
				min = std::min(min, std::abs(r - d));
			}
		}
		cout << min << endl;
	}
	return 0;
}
