#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

bool is_pal(string& s, int i, int l) {
	int j = i + l - 1;
	while (i < j) {
		// cout << i << " " << j << endl;
		if (s[i] != s[j]) {
			return false;
		}
		i++;
		j--;
	}
	return true;
}

int main(int argc, char const *argv[]) {
	string s;
	for (getline(cin, s); s != "DONE"; getline(cin, s)) {
		string ss;
		for (auto c: s) {
			if ('a' <= c and c <= 'z') {
				ss.push_back(c);
			}
			else if ('A' <= c and c <= 'Z') {
				ss.push_back(tolower(c, std::locale()));
			}
		}
		if (is_pal(ss, 0, ss.size())) {
			cout << "You won't be eaten!" << endl;
		}
		else {
			cout << "Uh oh.." << endl;
		}
	}
	return 0;
}
