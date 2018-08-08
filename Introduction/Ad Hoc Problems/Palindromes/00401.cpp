#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

bool is_pal(string& s) {
	int i = 0;
	int l = s.size();
	int j = i + l - 1;
	while (i < j) {
		if (s[i] != s[j]) {
			return false;
		}
		i++;
		j--;
	}
	return true;
}

map<char, char> mirror = {
	{'A', 'A'},
	{'E', '3'},
	{'H', 'H'},
	{'I', 'I'},
	{'J', 'L'},
	{'L', 'J'},
	{'M', 'M'},
	{'O', 'O'},
	{'S', '2'},
	{'T', 'T'},
	{'U', 'U'},
	{'V', 'V'},
	{'W', 'W'},
	{'X', 'X'},
	{'Y', 'Y'},
	{'Z', '5'},
	{'1', '1'},
	{'2', 'S'},
	{'3', 'E'},
	{'5', 'Z'},
	{'8', '8'},
};

int main(int argc, char const *argv[]) {
	string s;
	while (getline(cin, s)) {
		string ss;
		for (int i = int(s.size()) - 1; i >= 0; i--) {
			ss.push_back(mirror[s[i]]);
		}
		bool pal = is_pal(s);
		bool mir = s == ss;
		// cout << ss << endl;
		if (pal) {
			if (mir) {
				cout << s << " -- is a mirrored palindrome." << endl;
			}
			else {
				cout << s << " -- is a regular palindrome." << endl;
			}
		}
		else{
			if (mir) {
				cout << s << " -- is a mirrored string." << endl;
			}
			else {
				cout << s << " -- is not a palindrome." << endl;
			}
		}
		cout << endl;
	}
	return 0;
}
