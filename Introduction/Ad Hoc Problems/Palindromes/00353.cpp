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
	while (getline(cin, s)) {
		set<string> palindromes;
		for (int i = 0; i < s.size(); i++) {
			for (int l = 1; i + l <= s.size(); l++) {
				if (is_pal(s, i, l)) {
					palindromes.insert(s.substr(i, l));
				}
			}
		}
		cout << "The string '" << s << "' contains " << palindromes.size() << " palindromes." << endl;
	}
	return 0;
}
