#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {
	string qwerty =
		"`1234567890-="
		"qwertyuiop[]\\"
		"asdfghjkl;'"
		"zxcvbnm,./"
		"~!@#$%^&*()_+"
		"QWERTYUIOP{}|"
		"ASDFGHJKL:\""
		"ZXCVBNM<>?"
		" "
	;
	string dvorak =
		"`123qjlmfp/[]"
		"456.orsuyb;=\\"
		"789aehtdck-"
		"0zx,inwvg'"
		"~!@#QJLMFP?{}"
		"$%^>ORSUYB:+|"
		"&*(AEHTDCK_"
		")ZX<INWVG\""
		" "
	;
	map<char,char> m;
	for (int i = 0; i < qwerty.size(); i++) {
		m[qwerty[i]] = dvorak[i];
	}
	string s;
	while (getline(cin, s)) {
		for (auto c: s) {
			cout << m[c];
		}
		cout << endl;
	}
	return 0;
}
