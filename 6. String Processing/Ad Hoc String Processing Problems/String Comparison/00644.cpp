// César Bolívar Severino
// resuelto propio
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool is_prefix(string pre, string s)
{
	if (pre.size() > s.size()) {
		return false;
	}
	for (int i = 0; i < pre.size(); i++) {
		if (pre[i] != s[i]) {
			return false;
		}
	}
	return true;
}

bool is_immediately_decodable(vector<string> v)
{
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			if (i == j) {
				continue;
			}
			if (is_prefix(v[i], v[j]) || is_prefix(v[i], v[j])) {
				// cout << "prefix " << v[i] << " and " << v[j] << endl;
				return false;
			}
		}
	}
	return true;
}

int main(int argc, char const* argv[])
{
	for (int i = 1; !cin.eof(); i++) {
		vector<string> v;
		string s;
		cin >> s;
		if (s == "") {
			break;
		}
		// cout << s << endl;
		while (s != "9") {
			v.push_back(s);
			cin >> s;
			// cout << s << endl;

		}
		if (is_immediately_decodable(v)) {
			cout << "Set " << i << " is immediately decodable" << endl;
		}
		else {
			cout << "Set " << i << " is not immediately decodable" << endl;
		}
	}
	return 0;
}
