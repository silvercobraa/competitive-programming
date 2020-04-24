#include <iostream>
#include <string>

using namespace std;

int position = 0;
string s;

bool accept(char c) {
	if (position == s.size()) {
		return false;
	}
	if (s[position] == c) {
		position++;
		return true;
	}
	return false;
}

bool fff() {
	if (accept('F')) {
		// cout << "F" << endl;
		bool rec = fff();
		return true or rec;
	}
	return false;
}

bool slump() {
	// cout << "slump" << endl;
	if (accept('D') or accept('E')) {
		// cout << "D o E" << endl;
		bool f = fff();
		if (not f) return false;
		if (accept('G')) {
			// cout << "G" << endl;
			return true;
		}
		else {
			return slump();
		}
	}
	return false;
}

bool slimp() {
	bool a = accept('A');
	if (not a) return false;
	if (accept('H')) {
		return true;
	}
	else {
		if (accept('B')) {
			bool rec = slimp();
			if (not rec) return false;
			return accept('C');
		}
		else {
			bool rec = slump();
			if (not rec) return false;
			return accept('C');
		}
	}
}

bool slurpy() {
	bool sli = slimp();
	bool slu = slump();
	return sli and slu;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	puts("SLURPYS OUTPUT");
	for (size_t i = 0; i < n; i++) {
		position = 0;
		cin >> s;
		// cout << s << endl;
		// cout << slimp() << endl;
		if (not slurpy() or position != s.size()) {
			puts("NO");
		}
		else {
			puts("YES");
		}
	}
	puts("END OF OUTPUT");
	return 0;
}
